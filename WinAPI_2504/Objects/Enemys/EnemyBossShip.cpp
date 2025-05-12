#include "Framework.h"

EnemyBossShip::EnemyBossShip() : Enemy()
{
	hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
	hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	hTurretBrush = CreateSolidBrush(RGB(100, 100, 100));  // 포대 색상
	hSelectBrush = hBlueBrush;

	// 보스선의 꼭지점 추가 (타원형 모양)
	const float WIDTH = 150.0f;
	const float HEIGHT = 500.0f;
	
	// 타원형을 만들기 위한 점들 추가
	for (int i = 0; i < 36; i++) {
		float angle = (i * 10.0f) * (PI / 180.0f);
		float x = (WIDTH/2) * cos(angle);
		float y = (HEIGHT/2) * sin(angle);
		AddVertexs({ x, y });
	}
}

EnemyBossShip::~EnemyBossShip()
{
	DeleteObject(hRedBrush);
	DeleteObject(hBlueBrush);
	DeleteObject(hTurretBrush);
}

void EnemyBossShip::Update()
{
	if (!isActive) return;

	// 활성화된 포대 개수 확인
	int activeTurretCount = 0;
	for (const auto& turret : turrets) {
		if (turret.isActive) activeTurretCount++;
	}

	// 현재 상태에 따른 업데이트
	if (spawnTimer < 2.0f) {  // 2초 동안 내려오기
		spawnTimer += DELTA;
		Move();
	}
	else {
		// 패턴 2, 3, 4: 공격 패턴
		Move();
		Damage();
		Fire();
	}
}

void EnemyBossShip::Render(HDC hdc)
{
	if (!isActive) return;

	HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hSelectBrush);
	
	// 보스선 그리기 (충돌 판정 없이 시각적으로만 표시)
	DrawPolygon(hdc, vertexs);
	
	// 포대 그리기
	DrawTurrets(hdc);

	SelectObject(hdc, defaultBrush);
}

void EnemyBossShip::Spawn(Vector2 pos)
{
	center = pos;
	isActive = true;
	hSelectBrush = hBlueBrush;
	hp = MAX_HP;
	isDamaged = false;
	radius = RADIUS;
	spawnTimer = 0.0f;
	damage = DAMAGE;
	// 포대 초기화
	InitializeTurrets();
}

void EnemyBossShip::InitializeTurrets()
{
	turrets.clear();
	turrets.resize(6);  // 6개의 포대

	// 왼쪽 포대 3개 (상하 대칭 배치)
	for (int i = 0; i < 3; i++) {
		float yOffset = (i - 1) * 100.0f;  // -100, 0, 100으로 배치
		turrets[i].position = { -50.0f, yOffset };
		turrets[i].isActive = true;
		turrets[i].hp = 30;
	}

	// 오른쪽 포대 3개 (상하 대칭 배치)
	for (int i = 0; i < 3; i++) {
		float yOffset = (i - 1) * 100.0f;  // -100, 0, 100으로 배치
		turrets[i + 3].position = { 50.0f, yOffset };
		turrets[i + 3].isActive = true;
		turrets[i + 3].hp = 30;
	}
}

void EnemyBossShip::DrawTurrets(HDC hdc)
{
	HBRUSH defaultBrush = (HBRUSH)SelectObject(hdc, hTurretBrush);

	for (const auto& turret : turrets) {
		if (!turret.isActive) continue;

		// 포대의 실제 위치 계산 (보스선의 중심점 기준)
		Vector2 turretPos = center + turret.position;
		
		// 포대 그리기 (원형)
		Ellipse(hdc,
			turretPos.x - TURRET_RADIUS,
			turretPos.y - TURRET_RADIUS,
			turretPos.x + TURRET_RADIUS,
			turretPos.y + TURRET_RADIUS
		);
	}

	SelectObject(hdc, defaultBrush);
}

void EnemyBossShip::Damage()
{
	if (isDamaged)
	{
		damageTimer += DELTA;

		if (damageTimer >= DAMAGE_INTERVAL)
		{
			damageTimer = 0;
			isDamaged = false;
			hSelectBrush = hBlueBrush;
		}
		return;
	}

	// 포대에 대한 충돌 체크
	for (auto& turret : turrets) {
		if (!turret.isActive) continue;

		Vector2 turretPos = center + turret.position;
		
		// 포대 주변에 원형 충돌 영역 생성
		PolygonVector turretCollider;
		turretCollider.SetCenter(turretPos);
		turretCollider.SetRadius(TURRET_RADIUS);  // 충돌 반경 설정
		// 원형 충돌 영역을 위한 꼭지점 추가
		for (int i = 0; i < 36; i++) {
			float angle = (i * 10.0f) * (PI / 180.0f);
			float x = TURRET_RADIUS * cos(angle);
			float y = TURRET_RADIUS * sin(angle);
			turretCollider.AddVertexs({ x, y });
		}
		
		if (BulletManager::Get()->IsCollision(&turretCollider, "Player"))
		{
			turret.hp -= 10;
			
			if (turret.hp <= 0) {
				turret.isActive = false;
				
				// 모든 포대가 파괴되었는지 확인
				bool allTurretsDestroyed = true;
				for (const auto& t : turrets) {
					if (t.isActive) {
						allTurretsDestroyed = false;
						break;
					}
				}
				
				// 모든 포대가 파괴되면 보스도 파괴
				if (allTurretsDestroyed) {
					isActive = false;
					isDead = true;
				}
			}
			
			isDamaged = true;
			hSelectBrush = hRedBrush;
			break;  // 한 번에 하나의 포대만 처리
		}
	}
}

void EnemyBossShip::Move()
{
	// 활성화된 포대 개수 확인
	int activeTurretCount = 0;
	for (const auto& turret : turrets) {
		if (turret.isActive) activeTurretCount++;
	}

	// 목표 위치 계산
	Vector2 targetPos;
	float moveSpeed = 100.0f;  // 기본 이동 속도

	// 패턴 1: 처음 등장할 때 천천히 내려오기
	if (spawnTimer < 2.0f) {  // 2초 동안 내려오기
		targetPos = { SCREEN_WIDTH / 2.0f, 200.0f };
		moveSpeed = 100.0f;  // 이동 속도를 100으로 설정
	}
	// 패턴 2: 좌우로 움직이면서 플레이어 공격
	else if (activeTurretCount >= 6) {
		static float time = 0.0f;
		time += DELTA * 2.0f;  // 시간 증가 속도 조절
		targetPos = { SCREEN_WIDTH/2 + sin(time) * (SCREEN_WIDTH/4), 200.0f };
		moveSpeed = 150.0f;  // 좌우 이동 속도 증가
	}
	// 패턴 3: 좌우로 움직이면서 아래로 공격
	else if (activeTurretCount >= 3) {
		static float time = 0.0f;
		time += DELTA * 3.0f;  // 더 빠른 시간 증가
		targetPos = { SCREEN_WIDTH/2 + sin(time) * (SCREEN_WIDTH/4), 200.0f };
		moveSpeed = 200.0f;  // 더 빠른 좌우 이동
	}
	// 패턴 4: 상단 중앙에서 시계방향 탄막
	else {
		targetPos = { SCREEN_WIDTH / 2.0f, 150.0f };  // 100에서 150으로 수정
		moveSpeed = 100.0f;
	}

	// 부드러운 이동
	Vector2 direction = targetPos - center;
	float distance = direction.Distance({0,0});
	if (distance > 1.0f) {
		direction = direction.GetNormalized();
		center += direction * moveSpeed * DELTA;
	}
}

void EnemyBossShip::Fire()
{
	fireTimer += DELTA;

	// 활성화된 포대 개수 확인
	int activeTurretCount = 0;
	for (const auto& turret : turrets) {
		if (turret.isActive) activeTurretCount++;
	}

	// 패턴 1: 처음 등장할 때는 공격하지 않음
	if (spawnTimer < 2.0f) return;  // 2초 동안 공격하지 않음

	// 패턴 2: 플레이어를 향해 공격
	if (activeTurretCount >= 6) {
		if (fireTimer >= FIRE_INTERVAL)
		{
			fireTimer = 0.0f;

			// 활성화된 포대에서 발사
			for (const auto& turret : turrets) {
				if (!turret.isActive) continue;

				Vector2 turretPos = center + turret.position;
				Vector2 direction = player->GetCenter() - turretPos;
				direction = direction.GetNormalized();  // 방향 정규화
				BulletManager::Get()->Fire(turretPos, "Enemy", damage, COLOR_ENEMY_BULLET, direction);
			}
		}
	}
	// 패턴 3: 부채꼴 형태로 아래 방향 공격
	else if (activeTurretCount >= 3) {
		if (fireTimer >= 1.0f)  // 0.2초에서 0.4초로 수정
		{
			fireTimer = 0.0f;

			// 활성화된 포대에서 발사
			for (const auto& turret : turrets) {
				if (!turret.isActive) continue;

				Vector2 turretPos = center + turret.position;
				// 부채꼴 형태로 발사 (각도 범위: -45도 ~ 45도, 아래 방향)
				for (int i = -2; i <= 2; i++) {
					float angle = (i * 15.0f) * (PI / 180.0f) + PI/2;  // PI/2를 더해서 아래 방향으로 조정
					Vector2 direction(cos(angle), sin(angle));
					BulletManager::Get()->Fire(turretPos, "Enemy", damage, COLOR_ENEMY_BULLET, direction);
				}
			}
		}
	}
	// 패턴 4: 시계방향 탄막
	else {
		if (fireTimer >= 0.1f)  // 0.1초 주기로 발사
		{
			fireTimer = 0.0f;

			// 활성화된 포대에서 발사
			for (const auto& turret : turrets) {
				if (!turret.isActive) continue;

				Vector2 turretPos = center + turret.position;
				// 시계방향으로 회전하는 탄막
				static float currentAngle = 0.0f;
				Vector2 direction(cos(currentAngle), sin(currentAngle));
				BulletManager::Get()->Fire(turretPos, "Enemy", damage,COLOR_ENEMY_BULLET ,direction);
				currentAngle += 0.1f;  // 각도 증가
				if (currentAngle >= 2 * PI) currentAngle = 0.0f;
			}
		}
	}
}

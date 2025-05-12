#include "Framework.h"
/*
void PolygonVector::DrawPolygon(HDC hdc)
{
	vector<POINT> vertexP(vertexs.size());
	for (size_t i = 0; i < vertexs.size(); ++i)
		vertexP[i] = { (int)(vertexs[i].x + center.x), (int)(vertexs[i].y + center.y)};
	Polygon(hdc, vertexP.data(), (int)vertexP.size());
}
*/
void PolygonVector::DrawPolygon(HDC hdc, vector<Vector2>& vertexs)
{
	vector<POINT> vertexP(vertexs.size());
	for (size_t i = 0; i < vertexs.size(); ++i)
		vertexP[i] = { (int)(vertexs[i].x + center.x), (int)(vertexs[i].y + center.y) };
	Polygon(hdc, vertexP.data(), (int)vertexP.size());
}


bool PolygonVector::IsLineCircleCollision(const Vector2& P1, const Vector2& P2) {

	Vector2 lineVec = P2 - P1;
	Vector2 P1C = center - P1;
	float lineLength = lineVec.Distance({ 0,0 });
	Vector2 lineDir = lineVec.GetNormalized();

	float projection = P1C.Dot(lineDir);

	if (projection < 0) {
		projection = 0;
	}
	else if (projection > lineLength) {
		projection = lineLength;
	}

	Vector2 closestPoint = P1 + lineDir * projection;
	float distance = closestPoint.Distance(center);

	return distance <= radius;
}

bool PolygonVector::IsPolygonCircleCollision(PolygonVector* polygon) {
	vector<Vector2> vertexs = polygon->GetVertexs();
	if (vertexs.size() < 2) return false;
	for (int i = 0; i < vertexs.size(); i++) {
		if (IsLineCircleCollision(vertexs[i] + polygon->GetCenter(), polygon->GetCenter() + vertexs[(i == vertexs.size() - 1) ? 0 : i + 1])) return true;
	}
	return false;
}

vector<Vector2> PolygonVector::SumCenterVertexs(const vector<Vector2>& vertexs) {
	vector<Vector2> pos(vertexs.size());
	for (auto& vert : vertexs)
		pos.push_back(vert + center);
	return pos;
}

void PolygonVector::DrawRotatedRectangle(HDC hdc, vector<Vector2> vertex, float angle)
{
	// direction 벡터의 각도 계산
	for (auto& vert : vertex)
		vert = vert.Rotate(angle);

	DrawPolygon(hdc, vertex);


}

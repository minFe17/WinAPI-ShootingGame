#pragma once

class ItemManager : public Singleton<ItemManager>
{
	friend class Singleton;
private:
	const int ITEM_POOL_SIZE = 30;
	
public:
	ItemManager();
	~ItemManager();
	
	void Update();
	void Render(HDC hdc);

	void SetRandomItem(Item*& item);
	void SpawnItem(Vector2 pos);
	Item* GetCollidedPlayer(Player* player);
private:
	vector<Item*> items;
};
#include "Framework.h"

ItemManager::ItemManager()
{
	items.resize(ITEM_POOL_SIZE);
	for (Item*& item : items)
	{
		item = new Item();
		item->SetActive(false);
	}
}

ItemManager::~ItemManager()
{
	for (Item*& item : items)
	{
		delete item;
	}
	items.clear();
}

void ItemManager::Update()
{
	for (Item*& item : items)
	{
		item->Update();
	}
}

void ItemManager::Render(HDC hdc)
{
	for (Item*& item : items)
	{
		item->Render(hdc);
	}
}


void ItemManager::SetRandomItem(Item*& item)
{
	int randomType = rand() % (int)ItemType::End;
	item->SetType((ItemType)randomType);
}

void ItemManager::SpawnItem(Vector2 pos)
{
	for (Item*& item : items)
	{
		if (!item->IsActive())
		{
			SetRandomItem(item);
			item->Spawn(pos);
			break;
		}
	}
}

Item* ItemManager::GetCollidedPlayer(Player* player)
{
	for (Item* item : items)
	{
		if (!item->IsActive()) continue;

		if (item->IsCollisionCircle(player))
		{
			item->SetActive(false);
			return item;
		}
	}
	return nullptr;

}


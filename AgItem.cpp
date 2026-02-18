// Description: This file implements the Menu functions: reading items from the input file, formatting the menu table for display, and returning a pointer to an item when given its id.

#include "AgItem.h"

AgItem::AgItem() : m_size(0), m_worth(1), m_isHarvestable(false) {}

AgItem::AgItem(int size, int worth, bool harvestable) : m_size(size), m_worth(worth), m_isHarvestable(harvestable) {}

AgItem::~AgItem() {}

int AgItem::GetSize(){return m_size;}

int AgItem::GetWorth(){return m_worth;}

bool AgItem::GetIsHarvestable(){return m_isHarvestable;}

void AgItem::SetSize(int size){m_size = size;}

void AgItem::SetIsHarvestable(bool isAlive){m_isHarvestable = isAlive;}

void AgItem::SetWorth(int worth){m_worth = worth;}






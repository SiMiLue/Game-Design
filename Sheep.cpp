#include <stdafx.h>
#include "Sheep.h"
Sheep::Sheep(Team* team, Shop* shop) :Pet("Sheep", team, shop) {
	m_id = 30;
	m_tier = 3;
	m_attack = 2;
	m_life = 2;
}


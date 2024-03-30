#include <stdafx.h>
#include "FISH.h"
FISH::FISH(Team* team, Shop* shop) : Pet("FISH", team, shop) {
	m_id = 8;
	m_tier = 1;
	m_attack = 2;
	m_life = 3;

}


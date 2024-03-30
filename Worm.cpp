#include <stdafx.h>
#include "Worm.h"
Worm::Worm(Team* team, Shop* shop) :Pet("Worm", team, shop) {
	m_id = 18;
	m_tier = 2;
	m_attack = 1;
	m_life = 3;
}


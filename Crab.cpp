#include <stdafx.h>
#include "Crab.h"
Crab::Crab(Team* team, Shop* shop) :Pet("Crab", team, shop) {
	m_id = 12;
	m_tier = 2;
	m_attack = 4;
	m_life = 1;

}


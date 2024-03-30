#include <stdafx.h>
#include "Rat.h"
Rat::Rat(Team* team, Shop* shop) :Pet("Rat", team, shop) {
	m_id = 14;
	m_tier = 2;
	m_attack = 3;
	m_life = 6;
}


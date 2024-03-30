#include <stdafx.h>
#include "Dolphin.h"
Dolphin::Dolphin(Team* team, Shop* shop) :Pet("Dolphin", team, shop) {
	m_id = 23;
	m_tier = 3;
	m_attack = 4;
	m_life = 3;
}


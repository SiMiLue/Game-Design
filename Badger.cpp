#include <stdafx.h>
#include "Badger.h"
Badger::Badger(Team* team, Shop* shop) :Pet("Badger", team, shop) {
	m_id = 22;
	m_tier = 3;
	m_attack = 6;
	m_life = 3;
}


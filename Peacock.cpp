#include <stdafx.h>
#include "Peacock.h"
Peacock::Peacock(Team* team, Shop* shop) :Pet("Peacock", team, shop) {
	m_id = 16;
	m_tier = 2;
	m_attack = 2;
	m_life = 5;
}


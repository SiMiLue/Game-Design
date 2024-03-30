#include <stdafx.h>
#include "Dodo.h"
Dodo::Dodo(Team* team, Shop* shop) :Pet("Dodo", team, shop) {
	m_id = 21;
	m_tier = 3;
	m_attack = 4;
	m_life = 2;
}


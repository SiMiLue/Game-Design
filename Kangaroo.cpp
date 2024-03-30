#include <stdafx.h>
#include "Kangaroo.h"
Kangaroo::Kangaroo(Team* team, Shop* shop) :Pet("Kangaroo", team, shop) {
	m_id = 19;
	m_tier = 2;
	m_attack = 2;
	m_life = 3;
}


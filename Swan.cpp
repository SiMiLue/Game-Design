#include <stdafx.h>
#include "Swan.h"
Swan::Swan(Team* team, Shop* shop) :Pet("Swan", team, shop) {
	m_id = 13;
	m_tier = 2;
	m_attack = 1;
	m_life = 2;

}


#include <stdafx.h>
#include "Hippo.h"
Hippo::Hippo(Team* team, Shop* shop) :Pet("Hippo", team, shop) {
	m_id = 32;
	m_tier = 4;
	m_attack = 4;
	m_life = 7;
}


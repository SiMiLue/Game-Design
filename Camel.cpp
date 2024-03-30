#include <stdafx.h>
#include "Camel.h"
Camel::Camel(Team* team, Shop* shop) :Pet("Camel", team, shop) {
	m_id = 26;
	m_tier = 3;
	m_attack = 3;
	m_life = 4;
}


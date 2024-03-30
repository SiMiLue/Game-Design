#include <stdafx.h>
#include "Bison.h"
Bison::Bison(Team* team, Shop* shop) :Pet("Bison", team, shop) {
	m_id = 33;
	m_tier = 4;
	m_attack = 4;
	m_life = 4;
}


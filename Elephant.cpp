#include <stdafx.h>
#include "Elephant.h"
Elephant::Elephant(Team* team, Shop* shop) :Pet("Elephant", team, shop) {
	m_id = 25;
	m_tier = 3;
	m_attack = 3;
	m_life = 7;
}


#include <stdafx.h>
#include "Crocodile.h"
Crocodile::Crocodile(Team* team, Shop* shop) :Pet("Crocodile", team, shop) {
	m_id = 42;
	m_tier = 5;
	m_attack = 8;
	m_life = 4;
}
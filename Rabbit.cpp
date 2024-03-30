#include <stdafx.h>
#include "Rabbit.h"
Rabbit::Rabbit(Team* team, Shop* shop) :Pet("Rabbit", team, shop) {
	m_id = 27;
	m_tier = 3;
	m_attack = 1;
	m_life = 2;
}


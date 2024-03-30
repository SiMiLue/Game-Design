#include <stdafx.h>
#include "Monkey.h"
Monkey::Monkey(Team* team, Shop* shop) :Pet("Monkey", team, shop) {
	m_id = 44;
	m_tier = 5;
	m_attack = 1;
	m_life = 2;
}
#include <stdafx.h>
#include "Dragon.h"
Dragon::Dragon(Team* team, Shop* shop) :Pet("Dragon", team, shop) {
	m_id = 56;
	m_tier = 6;
	m_attack = 6;
	m_life = 8;
}
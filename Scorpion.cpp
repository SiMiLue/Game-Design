#include <stdafx.h>
#include "Scorpion.h"
Scorpion::Scorpion(Team* team, Shop* shop) :Pet("Scorpion", team, shop) {
	m_id = 41;
	m_tier = 5;
	m_attack = 1;
	m_life = 1;
}
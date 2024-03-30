#include <stdafx.h>
#include "Boar.h"
Boar::Boar(Team* team, Shop* shop) :Pet("Boar", team, shop) {
	m_id = 52;
	m_tier = 6;
	m_attack = 10;
	m_life = 6;
}
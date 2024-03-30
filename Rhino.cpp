#include <stdafx.h>
#include "Rhino.h"
Rhino::Rhino(Team* team, Shop* shop) :Pet("Rhino", team, shop) {
	m_id = 43;
	m_tier = 5;
	m_attack = 6;
	m_life = 9;
}
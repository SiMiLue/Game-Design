#include <stdafx.h>
#include "Deer.h"
Deer::Deer(Team* team, Shop* shop) :Pet("Deer", team, shop) {
	m_id = 38;
	m_tier = 4;
	m_attack = 1;
	m_life = 1;
}
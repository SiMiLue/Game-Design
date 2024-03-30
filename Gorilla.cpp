#include <stdafx.h>
#include "Gorilla.h"
Gorilla::Gorilla(Team* team, Shop* shop) :Pet("Gorilla", team, shop) {
	m_id = 54;
	m_tier = 6;
	m_attack = 7;
	m_life = 10;
}
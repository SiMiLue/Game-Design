#include <stdafx.h>
#include "Rooster.h"
Rooster::Rooster(Team* team, Shop* shop) :Pet("Rooster", team, shop) {
	m_id = 48;
	m_tier = 5;
	m_attack = 6;
	m_life = 4;
}
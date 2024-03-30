#include <stdafx.h>
#include "Parrot.h"
Parrot::Parrot(Team* team, Shop* shop) :Pet("Parrot", team, shop) {
	m_id = 40;
	m_tier = 4;
	m_attack = 4;
	m_life = 2;
}
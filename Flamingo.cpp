#include <stdafx.h>
#include "Flamingo.h"
Flamingo::Flamingo(Team* team, Shop* shop) :Pet("Flamingo", team, shop) {
	m_id = 17;
	m_tier = 2;
	m_attack = 3;
	m_life = 2;
}


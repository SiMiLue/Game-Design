#include <stdafx.h>
#include "Hedgehog.h"
Hedgehog::Hedgehog(Team* team, Shop* shop) :Pet("Hedgehog", team, shop) {
	m_id = 15;
	m_tier = 2;
	m_attack = 4;
	m_life = 2;
}


#include <stdafx.h>
#include "Otter.h"
Otter::Otter(Team* team, Shop* shop) : Pet("Otter", team, shop) {
	m_id = 4;
	m_tier = 1;
	m_attack = 1;
	m_life = 3;
}


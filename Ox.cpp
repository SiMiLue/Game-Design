#include <stdafx.h>
#include "Ox.h"
Ox::Ox(Team* team, Shop* shop) :Pet("Ox", team, shop) {
	m_id = 28;
	m_tier = 3;
	m_attack = 1;
	m_life = 3;
}

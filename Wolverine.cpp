#include <stdafx.h>
#include "Wolverine.h"
Wolverine::Wolverine(Team* team, Shop* shop) :Pet("Wolverine", team, shop) {
	m_id = 55;
	m_tier = 6;
	m_attack = 5;
	m_life = 4;
}
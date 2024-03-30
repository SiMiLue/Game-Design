#include <stdafx.h>
#include "Whale.h"
Whale::Whale(Team* team, Shop* shop) :Pet("Whale", team, shop) {
	m_id = 39;
	m_tier = 4;
	m_attack = 4;
	m_life = 10;
}
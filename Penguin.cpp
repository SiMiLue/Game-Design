#include <stdafx.h>
#include "Penguin.h"
Penguin::Penguin(Team* team, Shop* shop) :Pet("Penguin", team, shop) {
	m_id = 37;
	m_tier = 4;
	m_attack = 1;
	m_life = 3;
}
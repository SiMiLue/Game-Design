#include <stdafx.h>
#include "Mammoth.h"
Mammoth::Mammoth(Team* team, Shop* shop) :Pet("Mammoth", team, shop) {
	m_id = 57;
	m_tier = 6;
	m_attack = 4;
	m_life = 12;
}
#include <stdafx.h>
#include "Seal.h"
Seal::Seal(Team* team, Shop* shop) :Pet("Seal", team, shop) {
	m_id = 47;
	m_tier = 5;
	m_attack = 3;
	m_life = 8;
}
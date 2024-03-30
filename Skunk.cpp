#include <stdafx.h>
#include "Skunk.h"
Skunk::Skunk(Team* team, Shop* shop) :Pet("Skunk", team, shop) {
	m_id = 31;
	m_tier = 4;
	m_attack = 3;
	m_life = 5;
}

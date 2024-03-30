#include <stdafx.h>
#include "PIGEON.h"

PIGEON::PIGEON(Team* team, Shop* shop) : Pet("PIGEON", team, shop) {
	m_id = 3;
	m_tier = 1;
	m_attack = 3;
	m_life = 1;

}

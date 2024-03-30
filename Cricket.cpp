#include <stdafx.h>
#include "Cricket.h"
Cricket::Cricket(Team* team, Shop* shop) :Pet("Cricket", team, shop) {
	m_id = 9;
	m_tier = 1;
	m_attack = 1;
	m_life = 3;

}


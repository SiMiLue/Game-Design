#include <stdafx.h>
#include "Tiger.h"
Tiger::Tiger(Team* team, Shop* shop) :Pet("Tiger", team, shop) {
	m_id = 53;
	m_tier = 6;
	m_attack = 6;
	m_life = 4;
}
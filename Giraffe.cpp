#include <stdafx.h>
#include "Giraffe.h"
Giraffe::Giraffe(Team* team, Shop* shop) :Pet("Giraffe", team, shop) {
	m_id = 24;
	m_tier = 3;
	m_attack = 1;
	m_life = 2;
}


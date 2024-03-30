#include <stdafx.h>
#include "Armadillo.h"
Armadillo::Armadillo(Team* team, Shop* shop) :Pet("Armadillo", team, shop) {
	m_id = 45;
	m_tier = 5;
	m_attack = 2;
	m_life = 6;
}
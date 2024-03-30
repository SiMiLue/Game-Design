#include <stdafx.h>
#include "Leopard.h"
Leopard::Leopard(Team* team, Shop* shop) :Pet("Leopard", team, shop) {
	m_id = 51;
	m_tier = 6;
	m_attack = 10;
	m_life = 4;
}
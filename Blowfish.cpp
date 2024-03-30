#include <stdafx.h>
#include "Blowfish.h"
Blowfish::Blowfish(Team* team, Shop* shop) :Pet("Bison", team, shop) {
	m_id = 34;
	m_tier = 4;
	m_attack = 3;
	m_life = 6;
}
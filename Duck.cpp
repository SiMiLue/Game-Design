#include "./pets\Duck.h"
#include <stdafx.h>
Duck::Duck(Team* team, Shop* shop) : Pet("Duck", team, shop) {
	m_id = 1;
	m_tier = 1;
	m_attack = 2;
	m_life = 3;
	
}

Duck::~Duck() { 


}
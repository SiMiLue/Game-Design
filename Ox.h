#pragma once
#ifndef HEADER_PETS_OX
#define HEADER_PETS_OX

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Ox : public Pet {
public:
	Ox(Team* team, Shop* shop);
	

	//void on_sell() override;
};
#endif // HEADER_PETS_OX
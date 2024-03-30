#pragma once
#ifndef HEADER_PETS_CRAB
#define HEADER_PETS_CRAB

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Crab : public Pet {
public:
	Crab(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_CRAB

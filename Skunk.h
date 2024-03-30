#pragma once
#ifndef HEADER_PETS_SKUNK
#define HEADER_PETS_SKUNK

#include "Pets.h"
#include "shop.h"
#include "team.h"


class Skunk : public Pet {
public:
	Skunk(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_SKUNK
#pragma once
#ifndef HEADER_PETS_HORSE
#define HEADER_PETS_HORSE

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Horse : public Pet {
public:
	Horse(Team* team, Shop* shop);


	//void on_sell() override;
};


#endif // HEADER_PETS_HORSE
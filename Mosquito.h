#pragma once
#ifndef HEADER_PETS_MOSQUITO
#define HEADER_PETS_MOSQUITO

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Mosquito : public Pet {
public:
	Mosquito(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_Mosquito
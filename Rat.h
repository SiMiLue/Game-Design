#pragma once
#ifndef HEADER_PETS_RAT
#define HEADER_PETS_RAT

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Rat : public Pet {
public:
	Rat(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_RAT
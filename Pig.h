#pragma once
#ifndef HEADER_PETS_Pig
#define HEADER_PETS_Pig

#include "Pets.h"
#include "shop.h"
#include "team.h"


class Pig : public Pet {
public:
	Pig(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_Pig
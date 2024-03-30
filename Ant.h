#pragma once
#ifndef HEADER_PETS_Ant
#define HEADER_PETS_Ant

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Ant : public Pet {
public:
	Ant(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_Ant
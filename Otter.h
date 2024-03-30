#pragma once
#ifndef HEADER_PETS_Otter
#define HEADER_PETS_Otter

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Otter : public Pet {
public:
	Otter(Team* team, Shop* shop);


	//void on_sell() override;
};


#endif // HEADER_PETS_Otter
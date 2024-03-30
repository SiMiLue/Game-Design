#pragma once
#ifndef HEADER_PETS_CROCODILE
#define HEADER_PETS_CROCODILE

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Crocodile : public Pet {
public:
	Crocodile(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_CROCODILE
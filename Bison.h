#pragma once
#ifndef HEADER_PETS_BISON
#define HEADER_PETS_BISON

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Bison : public Pet {
public:
	Bison(Team* team, Shop* shop);


	//void on_sell() override;
};


#endif // HEADER_PETS_BISON
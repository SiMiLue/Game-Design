#pragma once
#ifndef HEADER_PETS_FLY
#define HEADER_PETS_FLY

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Fly : public Pet {
public:
	Fly(Team* team, Shop* shop);


	//void on_sell() override;
};


#endif // HEADER_PETS_FLY
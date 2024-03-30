#pragma once
#ifndef HEADER_PETS_DEER
#define HEADER_PETS_DEER

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Deer : public Pet {
public:
	Deer(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_DEER
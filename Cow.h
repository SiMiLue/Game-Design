#pragma once
#ifndef HEADER_PETS_COW
#define HEADER_PETS_COW

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Cow : public Pet {
public:
	Cow(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_COW
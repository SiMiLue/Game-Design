#pragma once
#ifndef HEADER_PETS_KANGAROO
#define HEADER_PETS_KANGAROO

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Kangaroo : public Pet {
public:
	Kangaroo(Team* team, Shop* shop);

	//void on_sell() override;
};


#endif // HEADER_PETS_KANGAROO
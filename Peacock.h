#pragma once
#ifndef HEADER_PETS_PEACOCK
#define HEADER_PETS_PEACOCK

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Peacock : public Pet {
public:
	Peacock(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_PEACOCK
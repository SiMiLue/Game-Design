#pragma once
#ifndef HEADER_PETS_DODO
#define HEADER_PETS_DODO

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Dodo : public Pet {
public:
	Dodo(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_DODO

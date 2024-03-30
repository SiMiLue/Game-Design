#pragma once
#ifndef HEADER_PETS_CAMEL
#define HEADER_PETS_CAMEL

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Camel : public Pet {
public:
	Camel(Team* team, Shop* shop);


	//void on_sell() override;
};
#endif // HEADER_PETS_CAMEL
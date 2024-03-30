#pragma once
#ifndef HEADER_PETS_WOLVERINE
#define HEADER_PETS_WOLVERINE

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Wolverine : public Pet {
public:
	Wolverine(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_WOLVERINE
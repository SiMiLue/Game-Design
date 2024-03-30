#pragma once
#ifndef HEADER_PETS_SEAL
#define HEADER_PETS_SEAL

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Seal : public Pet {
public:
	Seal(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_SEAL
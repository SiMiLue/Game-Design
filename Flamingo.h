#pragma once
#ifndef HEADER_PETS_FLAMINGO
#define HEADER_PETS_FLAMINGO

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Flamingo : public Pet {
public:
	Flamingo(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_FLAMINGO
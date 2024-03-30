#pragma once
#ifndef HEADER_PETS_TIGER
#define HEADER_PETS_TIGER

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Tiger : public Pet {
public:
	Tiger(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_TIGER
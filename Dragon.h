#pragma once
#ifndef HEADER_PETS_DRAGON
#define HEADER_PETS_DRAGON

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Dragon : public Pet {
public:
	Dragon(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_DRAGON
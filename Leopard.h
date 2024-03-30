#pragma once
#ifndef HEADER_PETS_LEOPARD
#define HEADER_PETS_LEOPARD

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Leopard : public Pet {
public:
	Leopard(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_LEOPARD
#pragma once
#ifndef HEADER_PETS_SPIDER
#define HEADER_PETS_SPIDER

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Spider : public Pet {
public:
	Spider(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_SPIDER
#pragma once
#ifndef HEADER_PETS_SWAN
#define HEADER_PETS_SWAN

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Swan : public Pet {
public:
	Swan(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_SWAN
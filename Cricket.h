#pragma once
#ifndef HEADER_PETS_CRICKET
#define HEADER_PETS_CRICKET

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Cricket : public Pet {
public:
	Cricket(Team* team, Shop* shop);
	

	//void on_sell() override;
};


#endif // HEADER_PETS_CRICKET
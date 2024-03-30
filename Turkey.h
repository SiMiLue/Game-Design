#pragma once
#ifndef HEADER_PETS_TURKEY
#define HEADER_PETS_TURKEY

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Turkey : public Pet {
public:
	Turkey(Team* team, Shop* shop);


	//void on_sell() override;
};

#endif // HEADER_PETS_TURKEY
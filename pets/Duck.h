#pragma once
#ifndef HEADER_PETS_DUCK
#define HEADER_PETS_DUCK

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Duck : public Pet {
public:
	Duck(Team* team, Shop* shop);
	~Duck() override;

	void on_sell() override;
};


#endif // HEADER_PETS_DUCK
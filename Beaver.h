
#ifndef HEADER_PETS_DUCK
#define HEADER_PETS_DUCK

#include "./Pets.h"
#include "shop.h"
#include "team.h"


class Beaver : public Pet {
public:
	Beaver(Team* team, Shop* shop);
	~Beaver() override;

	//void on_sell() override;
};


#endif // HEADER_PETS_DUCK
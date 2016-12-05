#pragma once
#include "Set.h"
#include "ITraversable.h"
class TraversableSet:public Set, public ITraversable
{
public:
	TraversableSet();
	~TraversableSet();
	int operator[](int)const override;
};


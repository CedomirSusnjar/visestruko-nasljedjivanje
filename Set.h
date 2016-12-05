#pragma once
#include"ITraversable.h"
#include "Collection.h"
class Set :public Collection
{
public:
	Set();
	~Set();
	Set(const Set&);
	Set(Set&&);
	bool add(int);
};


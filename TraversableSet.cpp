#include "TraversableSet.h"

TraversableSet::TraversableSet():Set() {}

TraversableSet::~TraversableSet() {}

int TraversableSet::operator[](int i) const
{
	if (i<0 || i>n)return head->obj;
	Node *p;
	for (p = head; p && --i; p = p->next);
	return p->obj;
}

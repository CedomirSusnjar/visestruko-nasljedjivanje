#include "Set.h"

Set::Set() :Collection() {}

Set::~Set() {}

Set::Set(const Set &a) { copy(a);}

Set::Set(Set &&a) { move(std::move(a));}

bool Set::add(int a)
{
	Node *q, *p;
	for (Collection::Node *temp = head; temp; temp = temp->next)
		if (temp->obj == a)
			return false;

	Node *temp = new Node(a);
	if (head == nullptr)  { head = tail = temp;}
	else if (head->obj > temp->obj) { temp->next = head; head->prev = temp; head = temp; }
	else if (tail->obj < temp->obj) { temp->prev = tail; tail->next = temp; tail = temp; }
	else
	{
		for (p = head, q = tail->prev; p->next->obj < temp->obj && q->obj > temp->obj; p = p->next, q = q->prev);
		if (q->obj < temp->obj)p = q;
		temp->next = p->next;
		temp->prev = p;
		p->next->prev = temp;
		p->next = temp;
	}
	++n;
	return true;
}

#include "Collection.h"

void Collection::copy(const Collection &other)
{
	Collection::~Collection();
	for (Node* node = other.tail; node; node = node->prev)
		add(node->obj);
}

void Collection::move(Collection &&other)
{
	head = other.head;
	tail = other.tail;
	n = other.n;
	other.head = other.tail = nullptr;
}

Collection::Collection() :n(0), head(nullptr), tail(nullptr) {}

Collection::Collection(const Collection &a) { copy(a);}

Collection::Collection(Collection &&a) { move(std::move(a));}

Collection::~Collection()
{
	Node *temp = head;
	while (temp)
	{
		Node *t = temp;
		temp = temp->next;
		delete t;
	}
	head = tail = nullptr;
	n = 0;
}

bool Collection::add(int a)
{
	Node *temp = new Node(a);
	if (head)
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	else head = tail = temp;
	++n;
	return true;
}

void Collection::remove(int i)
{
	if (i<0 || i>n)return;
	Node* node = getElement(i);
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
	--n;
}

Collection::Node * Collection::getElement(int i)const
{
	Node *node;
	for (node = head; --i; node = node->next);
	return node;
}

Collection::Node::Node(int a) :obj(a), next(nullptr), prev(nullptr) {}

std::ostream & operator<<(std::ostream &str, const Collection &c)
{
	for (Collection::Node *temp = c.head; temp; temp = temp->next)
		str << temp->obj<<" ";
	std::cout << std::endl;
	return str;
}

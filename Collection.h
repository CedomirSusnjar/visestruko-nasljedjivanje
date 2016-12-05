#pragma once
#include <iostream>
class Collection
{
protected:
	void copy(const Collection&);
	void move(Collection&&);
	struct Node
	{
		int obj;
		Node *next, *prev;
		Node(int);
	};
	Node *head;
	Node *tail;
	int n;
	friend std::ostream& operator<<(std::ostream&, const Collection&);
public:
	Collection();
	Collection(const Collection&);
	Collection(Collection&&);
	virtual ~Collection();
	virtual bool add(int);
	void remove(int);
	Node* getElement(int)const;
};


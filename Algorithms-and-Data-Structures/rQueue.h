#pragma once

#include "rNode.h"

template <class elementType>
class rQueue
{
private:
	rNode<elementType> *front, *back;
	unsigned long long count;
public:
	rQueue()
	{
		this->front = this->back = nullptr;
		this->count = 0;
	}

	rQueue(rQueue & copy)
	{

		rNode<elementType> *current = copy.front;

		while (current != nullptr)
		{
			temp.Push(current->element);
			current = current->next;
		}

		this->count = copy.count;
	}

	~rQueue()
	{
		while (!(this->isEmpty()))
			this->Pop();
	}

	void Push(elementType elementToInsert)
	{
		rNode<elementType> *newElement = new rNode<elementType>();

		newElement->element = elementToInsert;
		newElement->next = nullptr;

		if (this->isEmpty())
		{
			this->front = this->back = newElement;
		}
		else
		{
			(this->back)->next = newElement;
			this->back = newElement;
		}

		this->count++;
	}

	bool isEmpty()
	{
		if (this->front == nullptr)
			return true;
		else
			return false;
	}

	elementType & Front()
	{
		return (this->front)->element;
	}

	void Pop()
	{
		if (!(this->isEmpty()))
		{
			rNode<elementType> *temp = this->front;
			this->front = (this->front)->next;

			delete(temp);

			this->count--;
		}
	}

	unsigned long long getCount()
	{
		return this->count;
	}

	rQueue & operator = (rQueue & copy)
	{
		rNode<elementType> *current = copy.front;
		
		while (!(this->isEmpty()))
			this->Pop();

		while (current != nullptr)
			this->Push(current->element);

		this->count = copy.count;

		return *this;
	}
};

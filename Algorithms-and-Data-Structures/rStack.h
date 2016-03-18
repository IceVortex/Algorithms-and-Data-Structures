#pragma once

#include "rNode.h"

template <class elementType>
class rStack
{
private:
	rNode<elementType> *topElement;
	unsigned long long count;
public:
	rStack()
	{
		this->topElement = nullptr;
		this->count = 0;
	}

	rStack(rStack & copy)
	{
		rStack<elementType> temp;

		rNode<elementType> *current = copy.topElement;

		while (current != nullptr)
		{
			temp.Push(current->element);
			current = current->next;
		}

		while (!temp.isEmpty())
		{
			this->Push(temp.Top());
			temp.Pop();
		}

		this->count = copy.count;
	}

	~rStack()
	{
		while (!(this->isEmpty()))
			this->Pop();
	}

	void Push(elementType elementToInsert)
	{
		rNode<elementType> *newElement = new rNode<elementType>();
		
		newElement->element = elementToInsert;
		newElement->next = this->topElement;

		this->topElement = newElement;
		this->count++;
	}

	bool isEmpty()
	{
		if (this->topElement == nullptr)
			return true;
		else
			return false;
	}

	elementType & Top()
	{
		return (this->topElement)->element;
	}

	void Pop()
	{
		if (!(this->isEmpty()))
		{
			rNode<elementType> *temp = this->topElement;
			this->topElement = (this->topElement)->next;

			delete(temp);

			this->count--;
		}
	}

	unsigned long long getCount()
	{
		return this->count;
	}

	rStack & operator = (rStack & copy)
	{
		rStack<elementType> temp;

		rNode<elementType> *current = copy.topElement;

		while (current != nullptr)
		{
			temp.Push(current->element);
			current = current->next;
		}

		while (!(this->isEmpty()))
		{
			this->Pop();
		}

		while (!temp.isEmpty())
		{
			this->Push(temp.Top());
			temp.Pop();
		}

		this->count = copy.count;

		return *this;
	}
};

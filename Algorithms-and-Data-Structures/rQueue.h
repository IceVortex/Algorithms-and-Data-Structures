#pragma once

#include "rNode.h"

/*
	Queue class which keeps track of the first and the last element
	The functions available to manipulate the queue are the standard ones such as push, pop, is_empty and so on
*/
template <class element_type>
class rQueue
{
private:
	rNode<element_type> *front, *back;
	unsigned long long count;
public:
	rQueue()
	{
		this->front = this->back = nullptr;
		this->count = 0;
	}

	rQueue(rQueue & copy)
	{

		rNode<element_type> *current = copy.front;

		while (current != nullptr)
		{
			temp.Push(current->element);
			current = current->next;
		}

		this->count = copy.count;
	}

	~rQueue()
	{
		while (!(this->is_empty()))
			this->Pop();
	}

	void push(element_type element_to_insert)
	{
		rNode<element_type> *new_element = new rNode<element_type>();

		new_element->element = element_to_insert;
		new_element->next = nullptr;

		if (this->is_empty())
		{
			this->front = this->back = new_element;
		}
		else
		{
			(this->back)->next = new_element;
			this->back = new_element;
		}

		this->count++;
	}

	bool is_empty()
	{
		if (this->front == NULL)
			return true;
		else
			return false;
	}

	element_type & front()
	{
		return (this->front)->element;
	}

	void pop()
	{
		if (!(this->is_empty()))
		{
			rNode<element_type> *temp = this->front;
			this->front = (this->front)->next;

			delete(temp);

			this->count--;
		}
	}

	unsigned long long get_count()
	{
		return this->count;
	}

	rQueue & operator = (rQueue & copy)
	{
		rNode<element_type> *current = copy.front;
		
		while (!(this->isEmpty()))
			this->Pop();

		while (current != nullptr)
			this->Push(current->element);

		this->count = copy.count;

		return *this;
	}
};

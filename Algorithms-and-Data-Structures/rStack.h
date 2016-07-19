#pragma once

#include "rNode.h"

template <class element_type>
class rStack
{
private:
	rNode<element_type> *top_element;
	unsigned long long count;
public:
	rStack()
	{
		this->top_element = NULL;
		this->count = 0;
	}

	rStack(rStack & copy)
	{
		rStack<element_type> temp;

		rNode<element_type> *current = copy.top_element;

		while (current != NULL)
		{
			temp.push(current->element);
			current = current->next;
		}

		while (!temp.is_empty())
		{
			this->push(temp.Top());
			temp.pop();
		}

		this->count = copy.count;
	}

	~rStack()
	{
		while (!(this->is_empty()))
			this->pop();
	}

	void push(element_type element_to_insert)
	{
		rNode<element_type> *new_element = new rNode<element_type>();
		
		new_element->element = element_to_insert;
		new_element->next = this->top_element;

		this->top_element = new_element;
		this->count++;
	}

	bool is_empty()
	{
		if (this->top_element == NULL)
			return true;
		else
			return false;
	}

	element_type & Top()
	{
		return (this->top_element)->element;
	}

	void pop()
	{
		if (!(this->is_empty()))
		{
			rNode<element_type> *temp = this->top_element;
			this->top_element = (this->top_element)->next;

			delete(temp);

			this->count--;
		}
	}

	unsigned long long get_count()
	{
		return this->count;
	}

	rStack & operator = (rStack & copy)
	{
		rStack<element_type> temp;

		rNode<element_type> *current = copy.top_element;

		while (current != NULL)
		{
			temp.push(current->element);
			current = current->next;
		}

		while (!(this->is_empty()))
		{
			this->pop();
		}

		while (!temp.is_empty())
		{
			this->push(temp.Top());
			temp.pop();
		}

		this->count = copy.count;

		return *this;
	}
};

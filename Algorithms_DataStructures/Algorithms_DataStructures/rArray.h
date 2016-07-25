#pragma once
#include "rDoubleNode.h"

/*
	rArray class used to store sequencial values
	
	Methods available:

	- add(element_to_add, index)
	- push_back(element_to_add)
	- push_front(element_to_add)
	- remove(index)
	- pop_back()
	- pop_front()
	- front()
	- back()
	- look_up(index) / [] indexing operator
	- length()
	- append(array_to_append) / + operator // not yet
*/
template <class element_type>
class rArray
{
private:
	rDoubleNode<element_type> *first, *last;
	unsigned long long count;
public:
	rArray()
	{
		first = last = NULL;
		count = 0;
	}

	rArray(element_type* copy, unsigned long long number_of_elements)
	{
		for (int i = 0; i < number_of_elements; i++)
			this->insert(copy[i], i);
	}

	void insert(element_type element_to_add, unsigned long long index)
	{
		if (index == 0)
			this->push_front(element_to_add);
		else if (index == this->count)
			this->push_back(element_to_add);
		else if (index < this->count)
		{
			rDoubleNode<element_type> *new_element = new rDoubleNode<element_type>();
			new_element->value = element_to_add;

			rDoubleNode<element_type> *current_element = this->first;

			for (unsigned long long i = 0; i < index - 1; i++)
			{
				current_element = current_element->next;
			}

			(current_element->next)->previous = new_element;
			new_element->next = current_element->next;

			new_element->previous = current_element;
			current_element->next = new_element;

			this->count++;
		}
		else
			return;
	}

	void push_front(element_type element_to_add)
	{
		rDoubleNode<element_type> *new_element = new rDoubleNode<element_type>();
		new_element->value = element_to_add;

		if (this->first == NULL)
		{
			new_element->next = new_element->previous = NULL;
			this->first = this->last = new_element;
		}
		else
		{
			new_element->next = this->first;
			new_element->previous = NULL;
			(this->first)->previous = new_element;
			this->first = new_element;
		}

		this->count++;
	}

	void push_back(element_type element_to_add)
	{
		rDoubleNode<element_type> *new_element = new rDoubleNode<element_type>();
		new_element->value = element_to_add;

		if (this->first == NULL)
		{
			new_element->next = new_element->previous = NULL;
			this->first = this->last = new_element;
		}
		else
		{
			/*
			Example for easier explanation:
			#<-1-><-2->#

			1's previous element is NULL
			1's next element is 2
			2's previous element is 1
			2's next element is NULL

			Initial configuration:
			#<-1-><-2-><-3-><-4-><-5->#

			*/

			this->last->next = new_element; // #<-1-><-2-><-3-><-4-><-5->6 Add link from 5 to 6 (next)
			new_element->previous = this->last; // #<-1-><-2-><-3-><-4-><-5-><-6  Add link from 6 to 5 (previous)
			new_element->next = NULL; // #<-1-><-2-><-3-><-4-><-5-><-6-># Add link from 6 to NULl (next)
			this->last = new_element; // Just update the last element Update last element
		}

		this->count++;
	}

	element_type front()
	{
		return this->first->value;
	}

	element_type back()
	{
		return this->last->value;
	}

	element_type look_up(unsigned long long index)
	{
		if (0 < index && index < this->count - 1)
		{
			rDoubleNode<element_type> *current_element = this->first;

			for (unsigned long long i = 0; i < index; i++)
			{
				current_element = current_element->next;
			}

			return current_element->value;
		}
		else if (index == 0)
			return front();
		else if (index == this->count - 1)
			return back();
		else
			return NULL;
	}

	element_type operator[] (unsigned long long index)
	{
		return this->look_up(index);
	}

	unsigned long long length()
	{
		return this->count;
	}
};


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
	- remove(index)
	- front()
	- back()
	- look_up(index) / [] indexing operator
	- length()
	- extend(array_to_extend)
	- slice(start, finish)
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
		this->first = this->last = NULL;
		this->count = 0;
	}

	rArray(element_type* copy, unsigned long long number_of_elements)
	{
		this->first = this->last = NULL;
		this->count = 0;
		for (int i = 0; i < number_of_elements; i++)
			this->push_back(copy[i]);
	}

	rArray(rArray & copy)
	{
		this->first = this->last = NULL;
		this->count = 0;
		for (int i = 0; i < copy.count; i++)
			this->push_back(copy[i]);
	}

	/*
		Inserts element at given position
	*/
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

	/*
		Pushes element at the beginning of the array
	*/
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

	/*
		Pushes element at the back of the array
	*/
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
	
	/*
		Returns the first element of the array and deletes it from the list
	*/
	element_type pop_front()
	{
		element_type result = (this->first)->value;
		rDoubleNode<element_type> *to_delete = this->first;
		
		((this->first)->next)->previous = NULL;
		this->first = (this->first)->next;

		delete(to_delete);
		this->count--;

		return result;
	}

	/*
		Returns the last element of the array and deletes it from the list
	*/
	element_type pop_back()
	{
		element_type result = (this->last)->value;
		rDoubleNode<element_type> *to_delete = this->last;

		((this->last)->previous)->next = NULL;
		this->last = (this->last)->previous;

		delete(to_delete);
		this->count--;

		return result;
	}

	/*
		Deletes the element at the given index
	*/
	void remove(unsigned long long index)
	{
		if (index == 0)
			element_type temp = this->pop_front();
		else if (index == this->count - 1)
			element_type temp = this->pop_back();
		else if (0 < index && index < this->count)
		{
			rDoubleNode<element_type> *to_delete = this->first;

			unsigned long long current_index = 0;

			for (; current_index != index; to_delete = to_delete->next, current_index++)
				;

			(to_delete->previous)->next = to_delete->next;
			(to_delete->next)->previous = to_delete->previous;
			
			this->count--;
			delete(to_delete);
		}
	}

	/*
		Retrieves the first element
	*/
	element_type front()
	{
		return this->first->value;
	}

	/*
		Retrieves the last element
	*/
	element_type back()
	{
		return this->last->value;
	}

	/*
		Retrieves the element at the given position
	*/
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

	/*
		Indexing operator to retrieve the element at a given position
	*/
	element_type operator[] (unsigned long long index)
	{
		return this->look_up(index);
	}

	/*
		Extends the current array by adding the elements of another
	*/
	void extend(rArray<element_type> & to_add)
	{
		unsigned long long limit = to_add.count;
		for (unsigned long long i = 0; i < limit; i++)
			this->push_back(to_add[i]);
	}

	/*
		TODO
		Returns a slice of the array starting with the element at the position start
		and ending with the element at the position "finish"
	*/
	element_type * slice(unsigned long long start, unsigned long long finish)
	{
		returns NULL;
		/*if (start < finish
			&& (0 <= start && start < this->count)
			&& (0 <= finish && finish < this->count))
		{
			rDoubleNode<element_type> * current_element = this->first;
			element_type * new_list = new[]
			unsigned long long current_index = 0;
			
		}*/
	}

	/*
		Returns the length of the list
	*/
	unsigned long long length()
	{
		return this->count;
	}
};


#include "rNode.h"

/*
	Simple linked list
	Contains two pointers for the first element and the last one
*/
template <class element_type>
class rLinkedList
{
private:
	rNode<element_type> *start, *finish;
public:
	rLinkedList()
	{
		this->start = this->finish = NULL;
	}

	rLinkedList(rLinkedList & copy)
	{
		rNode<element_type> *current_element;
		rNode<element_type> *new_element;
		int index = 0;

		current_element = copy.start;
		
		while (current_element != NULL)
		{
			this->insert(current_element->value, index++);
			current = current->next;
		}
	}

	~rLinkedList()
	{
		rNode<element_type> *temp;
		rNode<element_type> *current = this->start;

		while (current != NULL)
		{
			temp = current;
			current = current->next;
			delete(temp);
		}
	}

	/*
		Inserts an element at the designated position
		Return True if the element was inserted properly and False otherwise
	*/
	bool insert(element_type element_to_insert, unsigned int index)
	{
		if (index == 0)
		{
			rNode<element_type> *new_element = new rNode<element_type>();

			new_element->value = element_to_insert;
			new_element->next = this->start;

			this->start = new_element;

			// If there's no previous element in the list, I mark the last one as also being the first one
			if (this->finish == NULL)
				this->finish = this->start;

			return true;
		}
		else
		{
			rNode<element_type> *previous_element = this->start;
			rNode<element_type> *current_element = this->start;

			unsigned int current_index = 0;

			// I iterate through all the elements until I reach the one at position "index" or NULL
			while (current_index < index && current_element != NULL)
			{
				previous_element = current_element;
				current_element = current_element->next;
				current_index++;
			}

			// If the "index" position is past the limit, it means the position is invalid
			if (index - current_index > 1)
				return false;
			
			rNode<element_type> *new_element = new rNode<element_type>();
			new_element->value = element_to_insert;

			previous_element->next = new_element;
			new_element->next = current_element;

			// If the curent element is NULL it means the one I inserted is in fact the last element
			// and therefore I have to update the list
			if (current_element == NULL)
				this->finish = new_element;

			return true;
		}
	}

	/*
		Deletes the element at the designated position.
		Returns True if the element was deleted properrly and False otherwise.
	*/
	bool Delete(unsigned int index)
	{
		if (index == 0)
		{
			rNode<element_type> *temp = this->start;

			this->start = (this->start)->next;

			delete(temp);

			return true;
		}
		else
		{
			rNode<element_type> *previous_element = this->start;
			rNode<element_type> *current_element = this->start;
			rNode<element_type> *temp;

			unsigned int current_index = 0;

			while (current_index < index && current_element != NULL)
			{
				previous_element = current_element;
				current_element = current_element->next;
				current_index++;
			}

			if (current_element == NULL && index - current_index > 1)
				return false;

			temp = current_element;
			previous_element->next = current_element->next;
			current_element = current_element->next;

			delete(temp);

			return true;
		}
	}

	/*
		Returns the element at the designated position.
		If the position is invalid, returns the last one instead.
	*/
	element_type look_up(unsigned int index)
	{
		if (index == 0)
		{
			return (this->start)->value;
		}
		else
		{
			rNode<element_type> *current_element = this->start;

			unsigned int current_index = 0;

			while (current_index < index && current_element != NULL)
			{
				current_element = current_element->next;
				current_index++;
			}

			if (current_element == NULL)
				return (this->finish)->value;

			return current_element->value;
		}
	}
};

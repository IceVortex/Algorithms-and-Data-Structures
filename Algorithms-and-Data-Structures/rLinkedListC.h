// Linked List with Count

#include "rNode.h"

template <class elementType>
class rLinkedListC
{
private:
	rNode<elementType> *start, *finish;
	unsigned long long count;
public:
	rLinkedListC()
	{
		this->start = this->finish = nullptr;
		this->count = 0;
	}

	rLinkedListC(rLinkedListC & copy)
	{
		this->count = copy->count;

		rNode<elementType> *current;
		rNode<elementType> *newElement;
		int index = 0;

		current = copy.start;
		
		while (current != nullptr)
		{
			this->Insert(current->element, index++);
			current = current->next;
		}
		
	}

	~rLinkedListC()
	{
		rNode<elementType> *temp;
		rNode<elementType> *current = this->start;

		while (current != nullptr)
		{
			temp = current;
			current = current->next;
			delete(temp);
		}
	}

	bool Insert(elementType elementToInsert, unsigned int index)
	{
		if (index > this->count)
			return false;

		if (index == 0)
		{
			rNode<elementType> *newElement = new rNode<elementType>();

			newElement->element = elementToInsert;
			newElement->next = this->start;

			this->start = newElement;

			if (this->finish == nullptr)
				this->finish = this->start;

			(this->count)++;
			return true;
		}
		else
		{
			rNode<elementType> *previous = this->start;
			rNode<elementType> *current = this->start;

			unsigned int currentIndex = 0;

			while (currentIndex < index && current != nullptr)
			{
				previous = current;
				current = current->next;
				currentIndex++;
			}

			if (index - currentIndex > 1)
				return false;
			
			rNode<elementType> *newElement = new rNode<elementType>();
			newElement->element = elementToInsert;

			previous->next = newElement;
			newElement->next = current;

			if (current == nullptr)
				this->finish = newElement;

			(this->count)++;
			return true;
		}
	}

	bool Delete(unsigned int index)
	{
		if (index >= this->count)
			return false;

		if (index == 0)
		{
			rNode<elementType> *temp = this->start;

			this->start = (this->start)->next;

			delete(temp);

			(this->count)--;
			return true;
		}
		else
		{
			rNode<elementType> *previous = this->start;
			rNode<elementType> *current = this->start;
			rNode<elementType> *temp;

			unsigned int currentIndex = 0;

			while (currentIndex < index && current != nullptr)
			{
				previous = iterator;
				current = current->next;
				currentIndex++;
			}

			if (current == nullptr && index - currentIndex > 1)
				return false;

			temp = current;
			previous->next = current->next;
			current = current->next;

			delete(temp);

			(this->count)--;
			return true;
		}
	}

	elementType LookUp(unsigned int index)
	{
		if (index == 0)
		{
			return (this->start)->element;
		}
		else if (index >= this->count)
			return (this->finish)->element;
		else
		{
			rNode<elementType> *current = this->start;

			unsigned int currentIndex = 0;

			while (currentIndex < index && current != nullptr)
			{
				current = current->next;
				currentIndex++;
			}

			if (current == nullptr)
				return (this->finish)->element;

			return current->element;
		}
	}

	unsigned long long getCount()
	{
		return this->count;
	}
};

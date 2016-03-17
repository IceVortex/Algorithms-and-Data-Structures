#include "rNode.h"

template <class elementType>
class rLinkedList
{
private:
	rNode<elementType> *start, *finish;
public:
	rLinkedList()
	{
		this->start = this->finish = nullptr;
	}

	rLinkedList(rLinkedList & copy)
	{
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

	~rLinkedList()
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
		if (index == 0)
		{
			rNode<elementType> *newElement = new rNode<elementType>();

			newElement->element = elementToInsert;
			newElement->next = this->start;

			this->start = newElement;

			if (this->finish == nullptr)
				this->finish = this->start;

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

			return true;
		}
	}

	bool Delete(unsigned int index)
	{
		if (index == 0)
		{
			rNode<elementType> *temp = this->start;

			this->start = (this->start)->next;

			delete(temp);

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

			return true;
		}
	}

	elementType LookUp(unsigned int index)
	{
		if (index == 0)
		{
			return (this->start)->element;
		}
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
};

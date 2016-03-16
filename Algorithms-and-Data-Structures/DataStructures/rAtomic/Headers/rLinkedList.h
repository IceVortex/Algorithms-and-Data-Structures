#include "rNode.h"

template <class T>
class rLinkedList
{
private:
	rNode<T> *start, *finish;
public:
	rLinkedList()
	{
		this->start = this->finish = nullptr;
	}

	rLinkedList(rLinkedList & copy)
	{
		rNode<T> *current;
		rNode<T> *newElement;

		iterator = copy.start;
		newElement = new rNode<T>();
		newElement->element = current->element;

		this->start = this->finish = newElement;

		while (current != nullptr)
		{
			current = current->next;

			newElement = new rNode<T>();
			newElement->element = current->element;

			(this->finish)->next = newElement;
			this->finish = newElement;
		}

		(this->finish)->next = nullptr;
	}

	~rLinkedList()
	{
		rNode<T> *temp;
		rNode<T> *current = this->start;

		while (current != nullptr)
		{
			temp = current;
			current = current->next;
			delete(temp);
		}
	}

	bool Insert(T elementToInsert, unsigned int index)
	{
		if (index == 0)
		{
			rNode<T> *newElement = new rNode<T>();

			newElement->element = elementToInsert;
			newElement->next = this->start;

			this->start = newElement;

			if (this->finish == nullptr)
				this->finish = this->start;

			return true;
		}
		else
		{

			rNode<T> *previous = this->start;
			rNode<T> *current = this->start;

			unsigned int currentIndex = 0;

			while (currentIndex < index && current != nullptr)
			{
				previous = current;
				current = current->next;
				currentIndex++;
			}

			if (index - currentIndex > 1)
				return false;
			
			rNode<T> *newElement = new rNode<T>();
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
			rNode<T> *temp = this->start;

			this->start = (this->start)->next;

			delete(temp);

			return true;
		}
		else
		{
			rNode<T> *previous = this->start;
			rNode<T> *current = this->start;
			rNode<T> *temp;

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

	T LookUp(unsigned int index)
	{
		if (index == 0)
		{
			return (this->start)->element;
		}
		else
		{
			rNode<T> *current = this->start;

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


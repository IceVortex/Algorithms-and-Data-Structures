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

		rNode<elementType> *current = copy->topElement;

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

		this->count = copy->count;
	}

	~rStack()
	{
		rNode<elementType> *temp;
		rNode<elementType> *current = this->topElement;

		while (current != nullptr)
		{
			temp = current;
			current = current->next;
			delete(temp);
		}
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
		if (this->count > 0)
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
};

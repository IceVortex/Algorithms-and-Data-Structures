#pragma once

/*
Node class defines node objects which are elements of linked lists.
Each nodes contains a pointer to the following element, the previous element, and its value
*/
template <class element_type>
class rDoubleNode
{
public:
	rDoubleNode *next, *previous;
	element_type value;
};


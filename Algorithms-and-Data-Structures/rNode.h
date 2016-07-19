#pragma once

/*
	Node class defines node objects which are elements of linked lists.
	Each nodes contains a pointer to the following element and its value
*/
template <class element_type>
class rNode
{
public:
	rNode *next;
	element_type value;
};


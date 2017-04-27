/****************************
Author: Sana Tauqir
Date: 5/25/2016
Description: Implementation of the StringList class with required and helper functions
****************************/

#include <iostream>
#include "StringList.hpp"
#include <string>

using namespace std;

/*default constructor, creates an empty StringList object*/
StringList::StringList() {
	head = NULL;
}

/*Copy Constructor helper function, recursively performs the deep copy*/
StringList::ListNode* StringList::copyList(ListNode *listOne) {

	if (listOne == NULL)
		return NULL;
	else {
		ListNode *nodeCopy = copyList(listOne->next);
		return new ListNode(listOne->s1, nodeCopy);
	}

}

/*Programmar defined copy constructor, calling upon the recursive copy function*/
StringList::StringList(StringList &stl){

	head = copyList(stl.head);

}

/*Destructor, destroys a stringList by deleting all nodes*/
StringList::~StringList() {
	ListNode *nodePtr = head;
	while (nodePtr != NULL)				//loop through the List, node-by-node
	{
		ListNode *garbage = nodePtr;    //pointer to keep track of node to be deleted
		nodePtr = nodePtr->next;
		delete garbage;
	}

}

/*Adds an element to a stringList*/
void StringList::add(string str) {
	if (head == NULL)
		head = new ListNode(str);		//since the list is empty, just add the value
	else {

		//keep going through the list until you reach the last node
		ListNode *nodePtr = head;
		while (nodePtr->next != NULL)
			nodePtr = nodePtr->next;

		//you have reached the last node so create a new node and add it after this
		nodePtr->next = new ListNode(str);
	}

}

/*Searches for parameter and returns the location, else returns -1 if it does not exist*/
int StringList::positionOf(string str) {
	ListNode *nodePtr = head;
	int size = 0;
	while (nodePtr->next != NULL)
	{
		if (nodePtr->s1 == str)
			return size;
		size++;
	}
	return -1;

}

/*changes the value of the node at the given position*/
bool StringList::setNodeVal(int x, string str) {

	ListNode *nodePtr = head;

	if (x >= getSize())
	{
		return false;
	}
	else {
		for (int i = 0; i < x; i++)
		{
			nodePtr = nodePtr->next;
		}
		nodePtr->s1 = str;
		return true;
	}
}

/*Helper function which returns the size of the stringlist*/
int StringList::getSize() {
	ListNode *nodePtr = head;
	int size = 1;
	while (nodePtr->next != NULL)
	{
		size++;
		nodePtr = nodePtr->next;
	}
	return size;
}

/*Converts the stringlist into a vector and returns*/
vector<string> StringList::getAsVector() {
	ListNode *nodePtr = head;
	vector<string> vecString;

	while (nodePtr->next != NULL)
	{
		vecString.push_back(nodePtr->s1);
		nodePtr = nodePtr->next;
	}

	vecString.push_back(nodePtr->s1);
	return vecString;
}



int main() {

	StringList myString;
	myString.add("hello");
	myString.add("good");
	myString.add("bye");
	int y = myString.getSize();
	cout << y << endl;
	int x = myString.positionOf("hello");
	cout << x << endl;
	bool haveBeenSet = myString.setNodeVal(1, "bad");
	cout << haveBeenSet << endl;
	
	vector<string> myVector = myString.getAsVector();
	for (int i = 0; i < myVector.size(); i++)
		cout << myVector[i] << endl;

	system("PAUSE");


}

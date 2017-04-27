/*****************************************
Author: Sana Tauqir
Date: 5/25/2016
Description: Declaration of the StringList class
*****************************************/

#ifndef STRINGLIST_HPP
#define STRINGLIST_HPP
#include <string>
#include <vector>

using namespace std;

class StringList {

private:
	struct ListNode {
		string s1;
		ListNode *next;
		ListNode(string str, ListNode *next1 = NULL) {
			s1 = str;
			next = next1;
		}
	};

	ListNode *head;

public: 

	StringList();
	StringList (StringList &stl);
	~StringList();

	ListNode* copyList(ListNode *listOne);
	int getSize();

	void add(string str);
	int positionOf(string str);
	bool setNodeVal(int x, string str);
	vector<string> getAsVector();


};
















#endif
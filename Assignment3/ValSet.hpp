/*******************************************************
Author: Sana Tauqir
Date: 5/16/2016
Description: Declaration of the ValSet Template class
*******************************************************/

#ifndef VALSET_HPP
#define VALSET_HPP
#include <vector>
#include <string>


using namespace std;

template <class T>
class ValSet {

private:
	T *aptr;	// pointer to array of T
	int arrSize;   //the size of the array
	int numValues;    //number of values that are currently part of the the set

public:
	ValSet();
	ValSet(const ValSet &r);
	~ValSet();
	ValSet<T> operator=(ValSet<T> &right);

	int size();				// returns  numValues
	bool isEmpty();			//true is valset contains no values
	bool contains(T t1);	
	void add(T t2);
	void remove(T t3);
	vector<T> getAsVector();

};





#endif
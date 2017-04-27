/*******************************************************
Author: Sana Tauqir
Date: 5/16/2016
Description: Definition of the ValSet Template class
*******************************************************/

#include "ValSet.hpp"

using namespace std;

/*Constructor which set the initial values for variables and allocates array memory*/
template <class T>
ValSet<T>::ValSet() {
	aptr = new T[10];
	arrSize = 10;
	numValues = 0;
	for (int i = 0; i < arrSize; i++)
		aptr[i] = T();

}

/*Copy constructor, makes a copy of the object passed to it*/
template <class T>
ValSet<T>::ValSet(const ValSet &right) {
	arrSize = right.arrSize;
	aptr = new T[arrSize];
	for (int i = 0; i < arrSize; i++) {
		aptr[i] = right.aptr[i];
	}
	numValues = right.numValues;
}

/*Desctuctor = deallocates memory*/
template <class T>
ValSet<T>::~ValSet() {
	if (arrSize > 0)
		delete [] aptr;

}

/*overloaded assignment operator function, creates a copy of the object passed to it*/
template <class T>
ValSet<T> ValSet<T>::operator=(ValSet<T> &right){
	aptr = new T[right.arrSize];
	for (int i = 0; i < arrSize; i++) {
		aptr[i] = right.aptr[i];
	}
	numValues = right.arrSize;
	arrSize = right.arrSize;
	return *this;
}

/*returns the numValues*/
template <class T>
int ValSet<T>::size() {
	return numValues;
}

/*returns a bool value regarding whether the array is empty*/
template <class T>
bool ValSet<T>::isEmpty() {
	if (numValues == 0)
		return true;
	else
		return false;

}

/*checks whether an element exists in the array*/
template <class T>
bool ValSet<T>::contains(T t1) {
	for (int i = 0; i < arrSize; i++){
		if (aptr[i] == t1)
			return true;
	}
			return false;
}

/*adds an element to the array and adjusts numValues accordingly*/
template <class T>
void ValSet<T>::add(T t2) {
	if (contains(t2) == false)   //if the value is not currently in the array
	{
		if (numValues <  arrSize) {
			aptr[numValues] = t2;
		}
		else {
			arrSize *= 2;
			aptr = new T[arrSize];						//dynamically allocate a new array of 2x the size
			for (int i = 0; i <  arrSize; i++)			//copy over the old array and delete it
				aptr[i] = this->aptr[i];
			this->~ValSet();
			aptr[numValues] = t2;				//add the new value in 
		}

	}
	numValues++;
}

/*removes an element from the array and decreases numValues accordingly*/
template <class T>
void ValSet<T>::remove(T t3) {
	int subscript;
	if (contains(t3) == true)   //if the value is currently in the array
	{

		for (int i = 0; i < arrSize; i++) {
			if (aptr[i] == t3)
				subscript = i;
		}
		for (int j = subscript; j < arrSize; j++)
			aptr[j] = aptr[j+1];
	}
	numValues--;
}

/*Function that converts and returns the array as a vector*/
template <class T>
vector<T> ValSet<T>::getAsVector() {
	vector<T> valVector;
	for (int i = 0; i < numValues; i++) {
		valVector.push_back(aptr[i]);
	}
	return valVector;

}

template class ValSet<int>;
template class ValSet<char>;
template class ValSet<string>;










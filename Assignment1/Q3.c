/* CS261- Assignment 1 - Q.3*/
/* Name: sana tauqir
 * Date: 7/5/16
 * Solution description: bubble sorting arrays
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
	int i = 0, j = 0, temp = 0;
	for (i=0; i < n ; i++) {
		for (j=0; j < n-1; j++) {
			if (number[j] > number[j + 1]) {
				temp = number[j+1];
				number[j + 1] = number[j];
				number[j] = temp;
			}
		}
	}
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
	int* myArray = malloc(n * sizeof(int));
    /*Fill this array with random numbers, using rand().*/
	int k = 0;
	for (k; k < 20; k++)
		myArray[k] = rand();
    /*Print the contents of the array.*/
	int i = 0;
	for (i; i < 20; i++)
		printf("%d, ", myArray[i]);
    /*Pass this array along with n to the sort() function of part a.*/
	sort(myArray, 20);
    /*Print the contents of the array.*/    
	int j = 0;
	for (j; j < 20; j++)
		printf("\n%d", myArray[j]);
	free(myArray);
    return 0;
}

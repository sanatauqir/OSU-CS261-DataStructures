/* CS261- Assignment 1 - Q.2*/
/* Name:sana tauqir
 * Date:7/5/16
 * Solution description: Passing by reference practice
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a *= 2;
    /*Set b to half its original value*/
	*b *= .5;
    /*Assign a+b to c*/
	c = *a + *b;
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x = 5, y = 6, z = 7, a = 0;
    /*Print the values of x, y and z*/
	printf("%d %d %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
	a = foo(&x, &y, z);
    /*Print the value returned by foo*/
	printf("%d\n", a);
    /*Print the values of x, y and z again*/
	printf("%d %d %d\n", x, y, z);
    /*Is the return value different than the value of z?  Why?*/
	return 0;
}
    
    

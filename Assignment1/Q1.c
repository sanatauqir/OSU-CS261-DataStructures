/* CS261- Assignment 1 - Q.1*/
/* Name: Sana Tauqir
 * Date: 7/4/16
 * Solution description: C Struct Practice
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student *s;
	s = malloc(10*sizeof(struct student));
     /*return the pointer*/
	return s;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	int i = 1, j = 1, x= 0, rExists = 1;
	for (i; i < 11; i++)
	{
		students[i].score = rand() % 100;
	}

	i = 1;
	for (i; i < 11; i++)
	{
		rExists = 1;
		while(rExists == 1){      //if r exists in the array
			x = rand() % 10 + 1;			//generate another random
			rExists = 0;
			for (j = 0; j < i; j++) {				// see if this random is in the array
				if (x == students[j].id)
					rExists = 1;
			}
		}
		students[i].id = x;
	}
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	int i = 1;
	for (i; i < 11; i++)
	{
		printf("ID%d: %d  ", i, students[i].id);
		printf("Score%d: %d\n", i, students[i].score);
	}

}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     
	int min = 100, max = 0, average = 0, sum=0, i = 1;
	for (i; i < 10; i++)
	{
		if (students[i].score < min)
			min = students[i].score;
		if (students[i].score > max)
			max = students[i].score;
		sum += students[i].score;
	}
	average = sum / 10;

	printf("Minimum: %d\n", min);
	printf("Maximum: %d\n", max);
	printf("Average: %d\n", average);


}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
	stud = allocate();
    /*call generate*/
	generate(stud);
    /*call output*/
	output(stud);
    /*call summary*/
	summary(stud);
    /*call deallocate*/
	deallocate(stud);
    return 0;
}

/***
Author: Sana Tauqir
Date: 7/16/16
Description: Circular Doubly-Linked List Implementations
***/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	list->sentinel = malloc(sizeof(struct Link));
	assert(list->sentinel != 0);
	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;
	list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	struct Link *newlink = malloc(sizeof(struct Link));
	assert(newlink != 0);
	newlink->value = value;
	newlink->next = NULL;
	newlink->prev = NULL;
	return newlink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	struct Link *newlink = createLink(value);
	newlink->prev = link;
	newlink->next = link->next;
	link->next->prev = newlink;
	link->next = newlink;
	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	link->prev->next = link->next;
	link->next->prev = link->prev;
	free(link);
	list->size--;
}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	while (!circularListIsEmpty(list))
	{
		circularListRemoveFront(list);
	}
	free(list->sentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	struct Link *newLink = createLink(value);
	assert(newLink != 0);
	newLink->next = list->sentinel->next;
	newLink->prev = list->sentinel;
	list->sentinel->next->prev = newLink;
	list->sentinel->next = newLink;
	list->size++;
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	struct Link *newLink = createLink(value);
	newLink->prev = list->sentinel->prev;
	newLink->next = list->sentinel;
	list->sentinel->prev->next = newLink;
	list->sentinel->prev = newLink;
	list->size++;
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	return list->sentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	removeLink(list, list->sentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	if (list->sentinel->next == list->sentinel && list->sentinel->prev == list->sentinel)
		return 1;
	else {
		return 0;
	}
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	int i;
	struct Link *currentLink = list->sentinel->next;
	for (i = 0; i < list->size; i++) {
		printf("  %g  ", currentLink->value);
		currentLink = currentLink->next;
	}
	printf("\n");
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	assert(list != 0);
	assert(list->size > 1); //make sure it's not just one element
	int i = 0;
	struct Link *temp = list->sentinel;
	struct Link *linkPos = list->sentinel->next;
	list->sentinel->prev = linkPos;
	for (i = 0; i < list->size; i++) {
		temp = linkPos->next;
		if (temp->next == list->sentinel) {
			list->sentinel->next = temp;
		}
		linkPos->next = linkPos->prev;
		linkPos->prev = temp;
		linkPos = temp;
	}



}

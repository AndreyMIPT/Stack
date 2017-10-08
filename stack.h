#ifndef _STACK_H_
#define _STACK_H_


#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct stack stack;		//	this struct stores :	
								//	void* data; 	pointer to beginning of allocated memory for stack data
								//	void* peek;		pointer to last element
								//	st_info* info;	pointer to struct stores:
													//	int elem_size;		stores size of one stack element. When st_creat elem_size = numb. 
													//	int num;			stores amount of stack elements. When st_creat num = 0. When st_push num += 1. When st_pop num -= 1.
													//	int count;			stures max amount of stack elements. when st_creat count = 1. when st_push count += 1.


stack*  st_creat        (int numb);					//	Creates a stack and returns a pointer to it. All elements of stack
													//	have size (int) numb bytes. If lack of memory then returns NULL.
													
int     st_clear        (stack* st);				//  clear all stack st.If function's argument is equal to NULL
													//	then return 1. If succsess then return 0.

int     st_push         (stack* st, void* data);	//	puts (any tip *) data in stack st (copy first size of elements st bytes). 
													//	If one of function's argument is equal to NULL
													//	then return 1. If lack of memory return 2. If succsess return 0.
													
int     st_pop          (stack* st, void* data);	//	puts last element of stack in (void *) data (copy first size of elements st bytes)
													//	and delete last stack element.If one of function's argument is equal to NULL
													//	then return 1. If stack st has not elements then return 3. If can not delete last element return 2.
													//	if succsess return 0.
													
int     st_get_num      (stack* st);				//	return Amount of elements.If function's argument is equal to NULL
													//	then return -1.

#endif

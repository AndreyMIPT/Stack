#include "stack.h"

void test_creat(stack* st)
{
	if (st == NULL)
		printf("Lack of memory:creat\n");
	return;
};	

void test_clear(int res)
{
	if (res == 1)
	{
		printf("NULL has come\n");
		return;
	}
	printf("stack has cleared\n");
	return;
}

void test_push(int res)
{
	if (res == 1)
	{
		printf( "one of function's argument is equal to NULL\n");
		return;
	}
	if (res == 2)
	{
		printf( "lack of memory\n");
		return;
	}
	printf( "sucsess push\n");
	return;
}

void test_pop(int res)
{
	if (res == 1)
	{
		printf( "one of function's argument is equal to NULL\n");
		return;
	}
	if (res == 3)
	{
		printf("stack has not elements for pop\n");
		return;
	}
	if (res == 2)
	{
		printf( "can not delete last element\n");
		return;
	}
	printf( "sucsess pop\n");
	return;
}

int main(int argc, char **argv)
{
	void* st1;
	void* st2;
	void* n=NULL;
	int a=1,b,i;
	char s[7];
	st1 =  st_creat(sizeof(int));
	test_creat(st1);
	printf("   put 1 , 2, 3 to stack for int and pop they\n");
	
	test_push(st_push(st1, &a));
	a = 2;
	test_push(st_push(st1, &a));
	a = 3;
	test_push(st_push(st1, &a));
	
	test_pop(st_pop(st1, &a));
	printf("   data=%d num elem=%d\n", a,st_get_num(st1));
	test_pop(st_pop(st1, &a));
	printf("   data=%d num elem=%d\n", a,st_get_num(st1));
	test_pop(st_pop(st1, &a));
	printf("   data=%d num elem=%d\n   another pop\n", a,st_get_num(st1));
	test_pop(st_pop(st1, &a));
	
	printf("   push to Nonexistent pointer of stack\n");
	test_push(st_push(n, &a));
	
	printf("   clear Nonexistent stack\n");
	test_clear(st_clear(n));
	
	printf("   test stack with words\n");
	st2 = st_creat(6*sizeof(char));
	test_creat(st2);
	
	s[0]='e';s[1]='a';s[2]='r';s[3]='t';s[4]='h';s[5]='s';s[6]='\0';
	printf("%s\n",s);
	test_push(st_push(st2,s));
	
	s[0]='t';s[1]='a';s[2]='b';s[3]='l';s[4]='e';s[5]='s';s[6]='\0';
	printf("%s\n",s);
	test_push(st_push(st2,s));
	
	s[0]='c';s[1]='r';s[2]='e';s[3]='a';s[4]='m';s[5]='s';s[6]='\0';
	printf("%s\n",s);
	test_push(st_push(st2,s));
	
	s[0]='b';s[1]='a';s[2]='n';s[3]='a';s[4]='n';s[5]='a';s[6]='\0';
	printf("%s\n",s);
	test_push(st_push(st2,s));
	
	for ( i = 0; i < 4;i++)
	{ 
		test_pop(st_pop(st2,s));
		s[6]='\0';
		printf("%s\n",s);
	}
		
	test_clear(st_clear(st1));
	test_clear(st_clear(st2));
	free(n);
	free(st1);
	free(st2);
	return 0;
}


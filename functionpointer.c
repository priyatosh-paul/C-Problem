#include<stdio.h>
void fun1(void)
{
	printf("I am in fun1\n");
}
void fun2(void)
{
	printf("I am in fun2\n");
}

int main()
{
	void (*fun[])(void,void)={fun1,fun2};

	(*fun[])(0,1);
	//(*fun)(1);


	return 0;
}

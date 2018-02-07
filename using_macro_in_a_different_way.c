#include<stdio.h>

#define START 1

void fun1(void)
{
	printf("fun1\n");	
}

void fun2(void)
{
	printf("fun2\n");	
}

void fun3(void)
{
	printf("fun3\n");	
}

#define ENUM_TABLE \
Z(FUN1,START) Y(fun1),\
X(FUN2) Y(fun2),\
X(FUN3) Y(fun3),\

enum e { 
#define Z(a,b) a=b
#define X(a) a
#define Y(a)
ENUM_TABLE
#undef X
#undef Y
#undef Z
};

static void(*fptr[])(void ) = { 0 ,
#define Y(a) a
#define X(a)
#define Z(a,b)
ENUM_TABLE
#undef X
#undef Y
#undef Z
};

int main(void)
{
	printf("Hello Wolrd....%d\n",FUN3);
	fptr[FUN3]();
	return 0;
}

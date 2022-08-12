#pragma once
#include"stdc++.h"
#define STACK_INT_SIZE 100
#define STACKINCREMENT 100
typedef int Elemtype;
typedef struct {
	Elemtype *base;
	Elemtype *top;
	Elemtype stacksize;
}Sqstack;
void InitStack(Sqstack &S) {
	S.base = (Elemtype *)malloc(STACK_INT_SIZE*sizeof(Elemtype));
	S.top = S.base;
	S.stacksize = STACK_INT_SIZE;
}
int GetTop(Sqstack S, Elemtype &e) {
	if (S.top == S.base)
		return 0;
	else
		e = *(S.top - 1);
	return 1;
}
void Push(Sqstack &S, Elemtype e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (Elemtype *)realloc(S.base, (S.stacksize + STACKINCREMENT)*sizeof(Elemtype));
		S.top = S.base + S.stacksize;
		if (!S.base)
			exit(OVERFLOW);
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
}
int Pop(Sqstack &S, Elemtype &e) {
	if (S.top == S.base)
		return 0;
	else
		e = *--S.top;
	return 1;
}

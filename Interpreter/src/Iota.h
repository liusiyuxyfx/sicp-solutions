
#ifndef IOTA_H
#define IOTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

typedef double (*pfunc)(int,double*);
typedef struct NODE node;
typedef struct AST ast;
typedef struct SYM sym;

/********************************************************************
	String Tree
********************************************************************/
struct NODE
{
	int len;
	
	union
	{
		node *sub[16];
		char str[64];
	};
};

#define VARIABLE 0
#define BUILT_IN 1
#define ARG_REF 2
#define COMPLEX 3
#define IF_CLAUSE 4
#define LET_CLAUSE 5
#define SET_CLAUSE 6
#define WHILE_CLAUSE 7

/********************************************************************
	Abstract Syntax Tree
********************************************************************/
struct AST
{
	int16_t type, len;
	
	union
	{
		double *var; //variable
		pfunc fn; //built-in
		int index; //arg ref
		ast *sub; //sub ast
	};
};

#define MAX_STR_LEN 32

/********************************************************************
	Symbol
********************************************************************/
struct SYM
{
	char name[MAX_STR_LEN];
	ast val;
	sym *next;
};

#endif

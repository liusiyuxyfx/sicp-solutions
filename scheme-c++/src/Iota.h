
#ifndef IOTA_H
#define IOTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

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

/********************************************************************
	Allocator.c
********************************************************************/
void InitAllocator( void );
void *Salloc( size_t size );
void *Dalloc( size_t size );
void ResetAllocator( void );

/********************************************************************
	Parser.c
********************************************************************/
node *SParse( char *str );
void DisplayStrTree( node *p );

/********************************************************************
	SymbolTable.c
********************************************************************/
int StrMatch( char *a, char *b );
sym *SearchSymbol( char *str );
sym *ImportSymbol( char *name, int16_t type );
void ImportFunc( char *name, pfunc fn );
void ImportVar( char *name, double val );

/********************************************************************
	Interpret.c
********************************************************************/
void Interpret( char *str );
void DisplayAST( ast x );

/********************************************************************
	Evaluator.c
********************************************************************/
void InitStack( void );
double Eval( ast exp );

/********************************************************************
	Built-in.c
********************************************************************/
double plus( int argc, double *argv );
double minus( int argc, double *argv );
double multiply( int argc, double *argv );
double divide( int argc, double *argv );
double max( int argc, double *argv );
double min( int argc, double *argv );
double greater( int argc, double *argv );
double less( int argc, double *argv );
double and( int argc, double *argv );
double or( int argc, double *argv );
double not( int argc, double *argv );
double absolute( int argc, double *argv );
double print( int argc, double *argv );
double clock_ms( int argc, double *argv );

#endif

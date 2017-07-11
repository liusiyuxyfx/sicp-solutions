
#include "Iota.h"
#include "Interpreter.h"
#include "Allocator.h"
#include "SymbolTable.h"
#include "Parser.h"
#include "Evaluator.h"
static char *ArgList[64];
static int Len = 0;

static int SearchList( char *str )
{
	for( int i=Len-1; i>=0; i-- )
	{
		if( StrMatch( str, ArgList[i] ) ) return i;
	}
	return -1;
}

/********************************************************************
	translate string tree into AST
********************************************************************/
static ast BuildExpr( node *src )
{
	ast expr;
	
	if( src->len ) {
		expr.type = COMPLEX;
		expr.len = src->len;
		expr.sub = Dalloc( src->len * sizeof(ast) );
		
		if( StrMatch( src->sub[0]->str, "let" ) ) {
			for( int i=0; i<src->sub[1]->len; i++ ) {
				ArgList[Len++] = src->sub[1]->sub[i]->sub[0]->str;
			}
			for( int i=0; i<src->len; i++ ) {
				expr.sub[i] = BuildExpr( src->sub[i] );
			}
			Len -= src->sub[1]->len;
		} else {
			for( int i=0; i<src->len; i++ ) {
				expr.sub[i] = BuildExpr( src->sub[i] );
			}
		}
	} else {
		int index = SearchList( src->str );
		
		if( index >= 0 ) {
			expr.type = ARG_REF;
			expr.index = index;
		} else {
			sym *symbol = SearchSymbol( src->str );
			
			if( symbol ) {
				expr = symbol->val;
			} else {
				expr.type = VARIABLE;
				expr.var = Dalloc( sizeof(double) );
				expr.var[0] = atof( src->str );
			}
		}
	}
	return expr;
}

/********************************************************************
	translate string tree into AST
********************************************************************/
static void BuildFunc( node *src, ast *p )
{
	if( src->len ) {
		p->type = COMPLEX;
		p->len = src->len;
		p->sub = Salloc( src->len * sizeof(ast) );
		
		if( StrMatch( src->sub[0]->str, "let" ) ) {
			for( int i=0; i<src->sub[1]->len; i++ ) {
				ArgList[Len++] = src->sub[1]->sub[i]->sub[0]->str;
			}
			for( int i=0; i<src->len; i++ ) {
				BuildFunc( src->sub[i], p->sub + i );
			}
			Len -= src->sub[1]->len;
		} else {
			for( int i=0; i<src->len; i++ ) {
				BuildFunc( src->sub[i], p->sub + i );
			}
		}
	} else {
		int index = SearchList( src->str );
		
		if( index >= 0 ) {
			p->type = ARG_REF;
			p->index = index;
		} else {
			sym *symbol = SearchSymbol( src->str );
			
			if( symbol ) {
				*p = symbol->val;
			} else {
				p->type = VARIABLE;
				p->var = Salloc( sizeof(double) );
				p->var[0] = atof( src->str );
			}
		}
	}
}

/********************************************************************
	define procedure
********************************************************************/
static void DefineFunc( node *arg, node *src )
{
	for( int i=1; i<arg->len; i++ )
	{
		ArgList[Len++] = arg->sub[i]->str;
	}
	sym *symbol = ImportSymbol( arg->sub[0]->str, 0 );
	
	BuildFunc( src, &(symbol->val) );
	
	Len = 0;
}

/********************************************************************
	Iota interpreter
********************************************************************/
void Interpret( char *str )
{
	node *p = SParse( str );
	
	if( p->len > 0 && p->sub[0]->len == 0 &&
		StrMatch( p->sub[0]->str, "define" ) )
	{
		if( p->sub[1]->len > 0 ) //define function
		{
			DefineFunc( p->sub[1], p->sub[2] );
		}
		else //define variable
		{
			double val = Eval( BuildExpr( p->sub[2] ) );
			
			ImportVar( p->sub[1]->str, val );
		}
	}
	else //expression
	{
		Eval( BuildExpr( p ) );
	}
	ResetAllocator();
}

/********************************************************************
	display the AST
********************************************************************/
void DisplayAST( ast x )
{
	if( x.type == VARIABLE ) printf( " var<%u:%g> ", x.var, x.var[0] );
	else if( x.type == BUILT_IN ) printf( " <built-in> " );
	else if( x.type == ARG_REF ) printf( " [%d] ", x.index );
	else if( x.type == IF_CLAUSE ) printf( " if " );
	else if( x.type == LET_CLAUSE ) printf( " let " );
	else if( x.type == SET_CLAUSE ) printf( " set " );
	else if( x.type == WHILE_CLAUSE ) printf( " while " );
	else if( x.type == COMPLEX )
	{
		printf( " (" );
		for( int i=0; i<x.len; i++ )
		{
			DisplayAST( x.sub[i] );
		}
		printf( ") " );
	}
	else printf( "undef!" );
}

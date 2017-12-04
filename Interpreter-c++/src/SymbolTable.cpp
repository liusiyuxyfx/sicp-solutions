
#include "Iota.h"
#include "SymbolTable.h"
#include "Allocator.h"
/********************************************************************
	string match
********************************************************************/
int StrMatch( char *a, char *b )
{
	for( int i=0; i<MAX_STR_LEN; i++ )
	{
		if( a[i] != b[i] ) return 0;
		if( a[i] == '\0' ) return 1;
	}
	return 1;
}

#define HASH_SIZE 1009

static sym *SymbolTable[HASH_SIZE];

/********************************************************************
	string hash function
********************************************************************/
static int Hash( unsigned char *str )
{
	unsigned int abyss = 0;
	
	for( int i=0; str[i] && i<MAX_STR_LEN; i++ )
	{
		abyss += ( abyss << 5 ) + str[i];
	}
	return abyss % HASH_SIZE;
}

/********************************************************************
	search symbol in the symbol table
********************************************************************/
sym *SearchSymbol( char *str )
{
	sym *iter;
	iter = SymbolTable[Hash((unsigned char*)str)];
	
	while( iter && !StrMatch( iter->name, str ) )
	{
		iter = iter->next;
	}
	return iter;
}

/********************************************************************
	import symbol
********************************************************************/
sym *ImportSymbol( char *name, int16_t type )
{
	sym *symbol = (sym *)Salloc( sizeof(sym) );
	int i = 0;
	for( ; name[i] && i<MAX_STR_LEN; i++ )
	{
		symbol->name[i] = name[i];
	}
	symbol->name[i] = '\0';
	symbol->val.type = type;
	
	int index = Hash( (unsigned char*) name );
	symbol->next = SymbolTable[index];
	SymbolTable[index] = symbol;
	
	return symbol;
}

/********************************************************************
	import built-in function
********************************************************************/
void ImportFunc( char *name, pfunc fn )
{
	sym *symbol = ImportSymbol( name, BUILT_IN );
	
	symbol->val.fn = fn;
}

/********************************************************************
	import variable
********************************************************************/
void ImportVar( char *name, double val )
{
	sym *symbol = ImportSymbol( name, VARIABLE );
	
	symbol->val.var = (double *)Salloc( sizeof(double) );
	symbol->val.var[0] = val;
}

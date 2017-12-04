
#include "Iota.h"
#include "Allocator.h"
static char *Index;

/********************************************************************
	translate linear text into string tree
********************************************************************/
static node *NodeParse( void )
{
	node *p = (node *) Dalloc( sizeof(node) );
	p->len = 0;
	while( *Index == ' ' ) Index++;
	
	if( *Index == '(' )
	{
		Index++;
		while( *Index != ')' )
		{
			p->sub[p->len++] = NodeParse();
			while( *Index == ' ' ) Index++;
		}
		Index++;
	}
	else
	{
		int i = 0;
		while( *Index != ' ' &&
  			   *Index != '(' &&
  			   *Index != ')' )
		{
			p->str[i++] = *Index++;
		}
		p->str[i] = '\0';
	}
	return p;
}

node *SParse( char *str )
{
	Index = str;
	
	return NodeParse();
}




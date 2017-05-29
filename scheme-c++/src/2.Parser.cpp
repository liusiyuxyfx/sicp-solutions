
#include "Iota.h"

static char *Index;

/********************************************************************
	translate linear text into string tree
********************************************************************/
static node *NodeParse( void )
{
	node *p = Dalloc( sizeof(node) );
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

/********************************************************************
	display the string tree with indent
********************************************************************/
static void DisplayNode( node *p, int indent )
{
	for( int i=0; i<indent; i++ ) printf( "    " );
	
	if( p->len )
	{
		printf( "(\n" );
		
		for( int i=0; i<p->len; i++ )
		{
			DisplayNode( p->sub[i], indent + 1 );
		}
		for( int i=0; i<indent; i++ ) printf( "    " );
		
		printf( ")\n" );
	}
	else printf( "\"%s\"\n", p->str );
}

void DisplayStrTree( node *p )
{
	DisplayNode( p, 0 );
}

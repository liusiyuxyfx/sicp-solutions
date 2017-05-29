
#include "Iota.h"

static char *PoolA, *SPA, *PoolB, *SPB;

void InitAllocator( void )
{
	SPA = PoolA = malloc( 10000000 );
	SPB = PoolB = malloc( 10000000 );
}

void *Salloc( size_t size )
{
	void *temp = SPA;
	
	SPA += ( ( size + 7 ) >> 3 ) << 3;
	
	return temp;
}

void *Dalloc( size_t size )
{
	void *temp = SPB;
	
	SPB += ( ( size + 7 ) >> 3 ) << 3;
	
	return temp;
}

void ResetAllocator( void ) { SPB = PoolB; }

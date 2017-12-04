#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "Iota.h"
void InitAllocator( void );
void *Salloc( size_t size );
void *Dalloc( size_t size );
void ResetAllocator( void );
#endif
#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "Iota.h"

int StrMatch( char *a, char *b );
sym *SearchSymbol( char *str );
sym *ImportSymbol( char *name, int16_t type );
void ImportFunc( char *name, pfunc fn );
void ImportVar( char *name, double val );
#endif
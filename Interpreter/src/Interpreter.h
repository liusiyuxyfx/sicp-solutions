#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>
#include "Iota.h"

void Interpret( char *str );
void DisplayAST( ast x );

#endif
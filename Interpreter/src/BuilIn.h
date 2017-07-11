#ifndef INTERPRETER_BUILIN_H
#define INTERPRETER_BUILIN_H

#include "Iota.h"

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

#endif //INTERPRETER_BUILIN_H

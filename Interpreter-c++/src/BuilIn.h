#ifndef INTERPRETER_BUILIN_H
#define INTERPRETER_BUILIN_H

#include "Iota.h"
class BuilInfunc {
public:
    static double pluss(int , double*);
    static double minuss( int , double* );
    static double multiply( int , double* );
    static double divide( int , double *);
    static double max( int , double *);
    static double min( int , double *);
    static double greaterr( int , double *);
    static double lesss( int , double *);
    static double andd( int , double *);
    static double orr( int , double *);
    static double nott( int , double *);
    static double absolute( int , double *);
    static double print( int , double *);
    static double clock_ms( int , double *);

};

#endif //INTERPRETER_BUILIN_H

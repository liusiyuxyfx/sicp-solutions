
#include "Iota.h"
#include "BuilIn.h"
double BuilInfunc::pluss( int argc, double *argv )
{
	double sum = 0;
	
	for( int i=0; i<argc; i++ )
	{
		sum += argv[i];
	}
	return sum;
}

double BuilInfunc::minuss( int argc, double *argv )
{
	double val = argv[0];
	
	for( int i=1; i<argc; i++ )
	{
		val -= argv[i];
	}
	return val;
}

double BuilInfunc::multiply( int argc, double *argv )
{
	double product = argv[0];
	
	for( int i=1; i<argc; i++ )
	{
		product *= argv[i];
	}
	return product;
}

double BuilInfunc::divide( int argc, double *argv )
{
	double val = argv[0];
	
	for( int i=1; i<argc; i++ )
	{
		val /= argv[i];
	}
	return val;
}

double BuilInfunc::max( int argc, double *argv )
{
	double val = argv[0];
	
	for( int i=1; i<argc; i++ )
	{
		if( argv[i] > val ) val = argv[i];
	}
	return val;
}

double BuilInfunc::min( int argc, double *argv )
{
	double val = argv[0];
	
	for( int i=1; i<argc; i++ )
	{
		if( argv[i] < val ) val = argv[i];
	}
	return val;
}

double BuilInfunc::greaterr( int argc, double *argv )
{
	return argv[0] > argv[1] ? 1 : -1;
}

double BuilInfunc::lesss( int argc, double *argv )
{
	return argv[0] < argv[1] ? 1 : -1;
}

double BuilInfunc::andd( int argc, double *argv )
{
	for( int i=0; i<argc; i++ )
	{
		if( argv[i] < 0 ) return -1;
	}
	return 1;
}

double BuilInfunc::orr( int argc, double *argv )
{
	for( int i=0; i<argc; i++ )
	{
		if( argv[i] > 0 ) return 1;
	}
	return -1;
}

double BuilInfunc::nott( int argc, double *argv )
{
	return argv[0] > 0 ? -1 : 1;
}

double BuilInfunc::absolute( int argc, double *argv )
{
	return argv[0] > 0 ? argv[0] : -argv[0];
}

double BuilInfunc::print( int argc, double *argv )
{
	printf( "{ " );
	
	for( int i=0; i<argc; i++ )
	{
		printf( "%g ", argv[i] );
	}
	printf( "}\n" );
	
	return 0;
}

double BuilInfunc::clock_ms( int argc, double *argv )
{
	return clock() * 1000.0 / CLOCKS_PER_SEC;
}


#include "Iota.h"
#include "1.Allocator.cpp"
#include "2.Parser.cpp"
#include "3.SymbolTable.cpp"
#include "4.Interpreter.cpp"
#include "5.Evaluator.cpp"
#include "6.Built-in.cpp"

void Initialize( void )
{
	InitAllocator();
	InitStack();

	ImportFunc( "+", plus );
	ImportFunc( "-", minus );
	ImportFunc( "*", multiply );
	ImportFunc( "/", divide );
	ImportFunc( "max", max );
	ImportFunc( "min", min );
	ImportFunc( ">", greater );
	ImportFunc( "<", less );
	ImportFunc( "and", and );
	ImportFunc( "or", or );
	ImportFunc( "not", not );
	ImportFunc( "abs", absolute );
	ImportFunc( "print", print );
	ImportFunc( "clock", clock_ms );

	ImportSymbol( "if", IF_CLAUSE );
	ImportSymbol( "let", LET_CLAUSE );
	ImportSymbol( "set", SET_CLAUSE );
	ImportSymbol( "while", WHILE_CLAUSE );
}

static char Buff[4096];
static int Index = 0;

void Launch( char *path )
{
	FILE *src = fopen( path, "r" );

	if( src )
	{
		int c, depth = 0;

		while( ( c = fgetc( src ) ) != EOF )
		{
			Buff[Index++] = ( c == '\n' || c == '\t' ) ? ' ' : c;

			if( c == '(' ) depth++;
			else if( c == ')' )
			{
				if( --depth == 0 )
				{
					Buff[Index] = 0;
					Interpret( Buff );
					Index = 0;
				}
			}
		}
		fclose( src );
	}
}

int main()
{
	Initialize();
	Launch( "rocket.txt" );
}

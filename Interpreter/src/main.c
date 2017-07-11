
#include "Iota.h"
#include "BuilIn.h"
#include "Interpreter.h"
#include "SymbolTable.h"
#include "Allocator.h"
#include "Evaluator.h"
#include <string.h>
#include <stdio.h>
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

int main();
char quit[10] = "(quit)";
char sinput[1000];
int main() {
	Initialize();
    FILE *src = fopen ("rocket.txt", "w");
    int flag = 0;
    while (gets(sinput)!=EOF) {
        for (; flag < 6; ++flag) {
            if (sinput[flag] != quit[flag]) {
                break;
            }
        }
        if (flag == 6) break;
        flag = 0;
        fputs(sinput,src);
        fputs("\n",src);

    }
    fclose(src);
    Launch ("rocket.txt");
    return getchar();
}

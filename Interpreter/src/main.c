
#include "Iota.h"
#include "BuilIn.h"
#include "Interpreter.h"
#include "SymbolTable.h"
#include "Allocator.h"
#include "Evaluator.h"
#include <string.h>
#include <stdio.h>
char quit[10] = "(quit)";
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

void Launch(  )
{
	//FILE *src = fopen( path, "r" );
	int flag = 0;

		int depth = 0;
        char c;

		while( 1 )
		{
            c = getchar();
			Buff[Index++] = ( c == '\n' || c == '\t' ) ? ' ' : c;
			
			if( c == '(' ) depth++;
			else if( c == ')' )
			{
				if( --depth == 0 )
				{
                    for (; flag < 6; ++flag) {
                        if (Buff[flag] != quit[flag]) {
                            break;
                        }
                    }
                    if (flag == 6) break;
                    flag = 0;
					Buff[Index] = 0;
					printf("=>");
					Interpret( Buff );
					puts("");
					Index = 0;
				}
			}
		}
		//fclose( src );
    return;

}

int main();
char sinput[1000];
int main() {
	Initialize();
    /*FILE *src = fopen ("rocket.txt", "w");
	puts("please input your scheme program");
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
    fclose(src);*/
    Launch ();
    return getchar();
}

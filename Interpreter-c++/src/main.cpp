#include "BuilIn.h"
#include "Interpreter.h"
#include "SymbolTable.h"
#include "Allocator.h"
#include "Evaluator.h"
#include <iostream>
using namespace std;
char quit[10] = "(quit)";
void Initialize( void )
{
	InitAllocator();
	InitStack();

	ImportFunc( "+", &BuilInfunc::pluss );
	ImportFunc( "-", &BuilInfunc::minuss );
	ImportFunc( "*", &BuilInfunc::multiply );
	ImportFunc( "/", &BuilInfunc::divide );
	ImportFunc( "max", &BuilInfunc::max );
	ImportFunc( "min", &BuilInfunc::min );
	ImportFunc( ">", &BuilInfunc::greaterr );
	ImportFunc( "<", &BuilInfunc::lesss );
	ImportFunc( "and", &BuilInfunc::andd );
	ImportFunc( "or", &BuilInfunc::orr );
	ImportFunc( "not", &BuilInfunc::nott );
	ImportFunc( "abs", &BuilInfunc::absolute );
	ImportFunc( "print", &BuilInfunc::print );
	ImportFunc( "clock", &BuilInfunc::clock_ms );

	ImportSymbol( "if", IF_CLAUSE );
	ImportSymbol( "let", LET_CLAUSE );
	ImportSymbol( "set", SET_CLAUSE );
	ImportSymbol( "while", WHILE_CLAUSE );
}

static char Buff[4096];
static int Index = 0;

void Launch(  )
{
	int flag = 0;

		int depth = 0;
        char c;
    	cout << "<=";
		while( true )
		{
            c = getchar();
			Buff[Index++] = ( c == '\n' || c == '\t' ) ? ' ' : c;
			
			if( c == '(' ) depth++;
			else if( c == ')' )
			{
				if( --depth == 0 )
				{

					Buff[Index] = 0;
					int cnt = 0;
					for (; flag < 6; ++flag) {
						if (Buff[cnt] == ' ')
							cnt++;
                        if (Buff[cnt++] != quit[flag]) {
                            break;
                        }
                    }
                    if (flag == 6) break;
                    flag = 0;

					Interpret( Buff );
					cout << "<=";
					Index = 0;
				}
			}
		}
    return;

}

void printLicense() {
	cout << "+--------------------------------------------------------------------------+" << endl;
	cout << "|                                  LICENSE                                 |" << endl;
	cout << "|  This project is developed by Richard.Liusiyu(richard.liusiyu@gmail.com),|" << endl;
	cout << "|only for study, cannot be spread without writer's permission.             |" << endl;
    cout << "|  For more information, please contact me.                                |" << endl;
	cout << "|                                                                          |" << endl;
	cout << "|                                     Email: richard.liusiyu@gmail.com     |" << endl;
	cout << "|                                     Github: github.com/liusiyuxyfx       |" << endl;
	cout << "|                                     2017.07.22                           |" << endl;
	cout << "+--------------------------------------------------------------------------+" << endl;
	cout << "" << endl;
	cout << "+--------------------------------------------------------------------------+" << endl;
	cout << "|                                  README                                  |" << endl;
	cout << "|  This is a Scheme Language Interpreter, originally based on c (you can   |" << endl;
	cout << "|clone 'https://github.com/liusiyuxyfx/SICP-Solutions.git' to get c version|" << endl;
	cout << "|, this version is based on c++.According to SICP Chp4, It has functions as|" << endl;
    cout << "|follow:                                                                   |" << endl;
	cout << "|   1.( print a )                                                          |" << endl;
	cout << "|   2.( max a b)                                                           |" << endl;
	cout << "|   3.( min a b)                                                           |" << endl;
	cout << "|   4.( and ), ( or ), ( not )                                             |" << endl;
	cout << "|   5.( let a b )                                                          |" << endl;
	cout << "|   6.( set a b )                                                          |" << endl;
	cout << "|   7.( while a b )                                                        |" << endl;
	cout << "|   8.( clock a b )                                                        |" << endl;
	cout << "|   9.( + - * / )                                                          |" << endl;
	cout << "|   10.( > < )                                                             |" << endl;
	cout << "|   11.( if )                                                              |" << endl;
	cout << "|   12.( while )                                                           |" << endl;
	cout << "|                                                                          |" << endl;
	cout << "|  It is a repl Interpreter, stop when get '(quit)' command.               |" << endl;
	cout << "|                                                                          |" << endl;
	cout << "|  Compile:                                                                |" << endl;
	cout << "|    * MacOS & Linux : I've prepared the MAKEFILE, you can complie it by   |" << endl;
	cout << "|      command 'make'.                                                     |" << endl;
	cout << "|    * Windows : Only JetBrain Clion can compile it directly, I do not rec-|" << endl;
	cout << "|      ommend you to use other IDE.                                        |" << endl;
	cout << "+--------------------------------------------------------------------------+" << endl;
	cout << "" << endl;
	cout << " Interpreter Start! " << endl << endl;
}
int main();
int main() {
	printLicense();
	Initialize();
    Launch ();
    return getchar();
}

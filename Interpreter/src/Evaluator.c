
#include "Iota.h"
#include "Evaluator.h"

static double *ArgStack, *ABP, *ASP, *TempStack, *TSP;

void InitStack( void )
{
	ArgStack = ABP = ASP = malloc( 10000000 );
	TempStack = TSP = malloc( 10000000 );
}

double Eval( ast exp )
{
	switch( exp.type )
	{
		case VARIABLE: return exp.var[0];
		
		case BUILT_IN: return exp.fn( 0, 0 );
		
		case ARG_REF: return ABP[exp.index];
		
		case COMPLEX: switch( exp.sub[0].type )
		{
			case BUILT_IN:
			{
				double *temp = TSP; TSP += exp.len-1;
				
				for( int i=1; i<exp.len; i++ )
				{
					temp[i-1] = Eval( exp.sub[i] );
				}
				TSP = temp;
				
				return exp.sub[0].fn( exp.len-1, temp );
			}
			case COMPLEX:
			{
				double *p = ABP, *temp = TSP; TSP += exp.len-1;
				
				for( int i=1; i<exp.len; i++ )
				{
					temp[i-1] = Eval( exp.sub[i] );
				}
				ABP = ASP; TSP = temp;
				
				for( int i=0; i<exp.len-1; i++ )
				{
					*ASP++ = temp[i];
				}
				temp[0] = Eval( exp.sub[0] );
				
				ASP = ABP; ABP = p;
				
				return temp[0];
			}
			case IF_CLAUSE:
			{
				int branch = Eval( exp.sub[1] ) > 0 ? 2 : 3;
				
				return Eval( exp.sub[branch] );
			}
			case LET_CLAUSE:
			{
				for( int i=0; i<exp.sub[1].len; i++ )
				{
					if( ASP != ABP + exp.sub[1].sub[i].sub[0].index )
					{
						printf( "\nERROR:\n[%d] : %d\n",
							exp.sub[1].sub[i].sub[0].index, ASP-ABP );
					}
					*ASP = Eval( exp.sub[1].sub[i].sub[1] ); ASP++;
				}
				double temp = 0;
				
				for( int i=2; i<exp.len; i++ )
				{
					temp = Eval( exp.sub[i] );
				}
				ASP -= exp.sub[1].len;
				
				return temp;
			}
			case SET_CLAUSE:
			{
				double val = Eval( exp.sub[2] );
				
				if( exp.sub[1].type == VARIABLE )
				{
					exp.sub[1].var[0] = val;
				}
				else if( exp.sub[1].type == ARG_REF )
				{
					ABP[exp.sub[1].index] = val;
				}
				return val;
			}
			case WHILE_CLAUSE:
			{
				while( Eval( exp.sub[1] ) > 0 )
				{
					for( int i=2; i<exp.len; i++ )
					{
						Eval( exp.sub[i] );
					}
				}
			}
		}
	}
	return 0.0 / 0.0;
}

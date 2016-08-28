#include <stdio.h>
#include "subroutine.h"

#define MAX_COUNT 100000

// sorting by exchanges
void sort_exchange( int * array, int count )
	{
	int	i, j;

	for( i = 0; i < count - 1; i++ )
		for( j = i + 1; j < count; j++ )
			if( array[ i ] > array[ j ] )
				swap( array + j, array + i );

	return;
	}

//main
int main( void )
	{
	int		array[ MAX_COUNT ] = { 0 }, count;
	FILE	* in, * out;

	in = fopen( "input.txt", "r" );
	out = fopen( "output.txt", "w" );
	count = read( in, array, MAX_COUNT );
	sort_exchange( array, count );
	write( out, array, count );

	return 0;
	}

#include <stdio.h>
#include "subroutine.h"

#define MAX_COUNT 100000

// bubble-sorting
void sort_bubble( int * array, int count )
	{
	int	i, j, tmp;

	for( i = 1; i < count; array[ j ] = tmp, i++ )
		for( j = i, tmp = array[ i ]; j > 0 && array[ j - 1 ] > tmp; j-- )
			array[ j ] = array[ j - 1 ];

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
	sort_bubble( array, count );
	write( out, array, count );

	return 0;
	}

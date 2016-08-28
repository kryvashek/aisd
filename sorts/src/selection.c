#include <stdio.h>
#include "subroutine.h"

#define MAX_COUNT 100000

// sorting by choosing
void sort_selection( int * array, int count )
	{
	int	i, j, m;

	for( i = 0; i < count - 1; swap( array + m, array + i ), i++ )
		for( j = i + 1, m = i; j < count; j++ )
			if( array[ m ] > array[ j ] )
				m = j;

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
	sort_selection( array, count );
	write( out, array, count );

	return 0;
	}

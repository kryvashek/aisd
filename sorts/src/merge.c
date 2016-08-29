#include <stdio.h>
#include <stdlib.h>
#include "subroutine.h"

#define MAX_COUNT 3000001

// merge sorting
void sort_merge( int * array, int * temp_array, int start, int finish )
	{
	if( start >= finish )
		return;

	int	middle = ( start + finish ) / 2,
		i, j, k;

	sort_merge( array, temp_array, start, middle );
	sort_merge( array, temp_array, middle + 1, finish );

	i = start;
	j = middle + 1;

	for( k = start; k <= finish; k++ )
		if( j > finish || ( i <= middle && array[ i ] < array[ j ] ) )
			temp_array[ k ] = array[ i++ ];
		else
			temp_array[ k ] = array[ j++ ];

	for( k = start; k <= finish; k++ )
		array[ k ] = temp_array[ k ];

	return;
	}

int main( void )
	{
	int		* array = ( int * )malloc( MAX_COUNT * sizeof( int ) ),
			count, * temp_array;
	FILE	* in, * out;

	in = fopen( "input.txt", "r" );
	out = fopen( "output.txt", "w" );

	count = read( in, array, MAX_COUNT );
	temp_array = ( int * )malloc( count * sizeof( int ) );

	sort_merge( array, temp_array, 0, count - 1 );
	write( out, array, count );

	free( temp_array );
	free( array );

	return 0;
	}
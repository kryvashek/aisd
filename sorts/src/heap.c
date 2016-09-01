#include <stdio.h>
#include <stdlib.h>
#include "subroutine.h"

#define MAX_COUNT 3000001

// sorting with binary heap
void sort_heap( int * array, int count )
	{
	int	i, parent, child;

	array--;
	for( i = 2; i <= count; i++ )
		for( child = i, parent = child / 2; child > 1 && array[ parent ] < array[ child ]; child = parent, parent /= 2 )
			swap( array + parent, array + child );

	for( i = count; i > 1; i-- )
		{
		swap( array + 1, array + i );

		for( parent = 1, child = 2; child < i; parent = child, child *= 2 )
			{
			if( child < i - 1 && array[ child ] < array[ child + 1 ] )
				child++;

			if( array[ parent ] >= array[ child ] )
				break;

			swap( array + child, array + parent );
			}
		}

	return;
	}

int main( void )
	{
	int		* array = ( int * )malloc( MAX_COUNT * sizeof( int ) ),
			count;
	FILE	* in, * out;

	in = fopen( "input.txt", "r" );
	out = fopen( "output.txt", "w" );

	count = read( in, array, MAX_COUNT );
	sort_heap( array, count );
	write( out, array, count );

	free( array );

	return 0;
	}
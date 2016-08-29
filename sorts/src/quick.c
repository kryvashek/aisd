#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include "subroutine.h"

#define MAX_COUNT 3000001
#define INT_LIMIT ((double)INT_MAX)

// function of choosing prop element
int choose_prop( int left, int right )
	{
	double	coerced_length = ( ( double )( right - left + 1 ) ) / ( 6.0 * INT_LIMIT );

	left += ( int )( coerced_length * ( double )rand() );
	right -= ( int )( coerced_length * ( double )rand() );

	return ( left + right ) / 2;
	}

// quick sorting
void sort_quick( int * array, int start, int finish )
	{
	if( start >= finish )
		return;

	int middle = choose_prop( start, finish ),
		prop = array[ middle ], left = start - 1, right = finish + 1;

	while( left < right )
		{
		while( array[ ++left ] < prop );
		while( array[ --right ] > prop );

		if( left < right )
			swap( array + left, array + right );
		}

	sort_quick( array, start, right );
	sort_quick( array, right + 1, finish );

	return;
	}

int main( void )
	{
	int		* array = ( int * )malloc( MAX_COUNT * sizeof( int ) ),
			count;
	FILE	* in, * out;

	in = fopen( "input.txt", "r" );
	out = fopen( "output.txt", "w" );

	srand( time( NULL ) );
	count = read( in, array, MAX_COUNT );

	sort_quick( array, 0, count - 1 );
	write( out, array, count );

	free( array );

	return 0;
	}
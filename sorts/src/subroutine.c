#include <stdio.h>
//#include <subroutine.h>

// reading from file
int read( FILE * file, int * array, int max_count )
	{
	int count = 0;

	if( NULL != array )
		while( count < max_count && 1 == fscanf( file, "%d", array + count ) )
			count++;

	return count;
	}

// writing to file
void write( FILE * file, int * array, int count )
	{
	int	i;

	if( NULL != array )
		for( i = 0; i < count; i++ )
			fprintf( file, "%d ", array[ i ] );

	return;
	}

// swapping values
extern inline void swap( int * one, int * two )
	{
	int tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
	return;
	}
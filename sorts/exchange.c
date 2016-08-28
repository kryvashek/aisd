#include <stdio.h>

#define MAX_COUNT 100000

// reading from file
int read( int * array )
	{
	int count = 0;

	while( count < MAX_COUNT && scanf( "%d", array + count ) == 1 )
		count++;

	return count;
	}

// writing to file
void write( int * array, int count )
	{
	int	i;

	for( i = 0; i < count; i++ )
		printf( "%d ", array[ i ] );

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
	int	array[ MAX_COUNT ] = { 0 }, count;

	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
	count = read( array );
	sort_exchange( array, count );
	write( array, count );

	return 0;
	}

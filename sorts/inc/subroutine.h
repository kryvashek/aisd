#include <stdio.h>

// reading from file
extern int read( FILE * file, int * array, int max_count );

// writing to file
extern void write( FILE * file, int * array, int count );

// swapping values
extern void swap( int * one, int * two );
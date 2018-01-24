/**
*@desc A file that has been created to read comma seperated values from givenfiles
*and return statements that establish most pop, least pop, location of least pop,
* location of most pop, and total population.
*@author Matthew Richmond mjr1408@cs.rit.edu
*
*/

#include <stdio.h> //standard io for processing data entry
#include <stdlib.h>  // std lib for strtol
#include <limits.h> //contains max and min values for var types.
int main(){
// The main function to intake and interpret given data seperated by commas
	int size = 256; //line size
	char buff[size]; // buffer to hold lines
	char *eos; // pointer to recieve end of string
	fgets(buff, size, stdin); // rem the first line, unnecessary.
	int ttl = 0; // total number of zips
	long maxpop = LONG_MIN; // max population, set to min pop so any pop is higher
	long minpop = LONG_MAX; // min pop, set to max so any pop is lower
	long minzip;
	long maxzip;
	long curzip; // "pointer"
	long curpop; // "pointer"
	long totalpop = 0; // total population
	while((fgets(buff, size, stdin)) != '\0'){ //main loop.
		ttl++;
		curzip = strtol(buff, &eos, 10);
		++eos;
		curpop = strtol(eos,&eos, 10);
		totalpop += curpop;
		if(curpop > maxpop)
			maxpop = curpop;
			maxzip = curzip;
		}
		if(curpop < minpop){
			minpop = curpop;
			minzip = curzip;
		}
	}
	printf("Total population across %d zipcodes is %ld.\n", ttl, totalpop);
	printf("The fewest people live in %ld, population %ld.\n", minzip, minpop);
	printf("The most people live in %ld, population %ld.\n", maxzip, maxpop);
}


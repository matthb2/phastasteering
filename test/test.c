#include <stdio.h>

#include "phastasteering.h"

int main(int argc ,char** argv)
{
	init_steering();
	int i;
	double p;
	int f;
	for(i=0;i<10;i++)
	{
		pollpressure(&p, &f);
		if(f == 1)
			printf("Pressure: %g\n", p);
		else
			printf("No value rxed this loop\n");
		sleep(1);
	}
	cleanup_steering();
	return(0);
}

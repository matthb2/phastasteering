#include <stdio.h>

#include <mpi.h>

#include "phastasteering.h"

int main(int argc ,char** argv)
{
	MPI_Init(&argc, &argv);
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
	MPI_Finalize();
	return(0);
}

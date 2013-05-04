#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <mpi.h>
#include <zmq.h>

#include "phastasteering.h"

static void* context;
static void* socket;
static double pressure;

void init_steering()
{
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	pressure = -1.0;
	if(rank == 0)
	{
		context = zmq_ctx_new();
		socket = zmq_socket(context, ZMQ_PAIR);
		int rc = zmq_bind(socket, "tcp://*:5555");
		assert(rc==0);
	}
	context = zmq_ctx_new();
	socket = zmq_socket(context, ZMQ_PAIR);
	int rc = zmq_bind(socket, "tcp://*:5555");
	assert(rc==0);

}

void pollpressure(double* p, int* rxed)
{
	char value[100];
	int rc;
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank == 0)
	{
		rc = zmq_recv(socket, value, 100, ZMQ_DONTWAIT);
		value[99] = '\0';
		if(rc != -1) {
			pressure = atof(value);
			*p = pressure;
			*rxed = 1;
		} else {
			*rxed = -1;
		}

	}
	MPI_Bcast(rxed, 1, MPI_INTEGER, 0, MPI_COMM_WORLD);
	MPI_Bcast(&pressure, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
	*p = pressure;
}

void cleanup_steering()
{
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank == 0)
	{
		zmq_close(socket);
		zmq_ctx_destroy(context);
	}
}

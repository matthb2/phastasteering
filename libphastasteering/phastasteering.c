#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <zmq.h>

#include "phastasteering.h"

static void* context;
static void* socket;
static double pressure;

void init_steering()
{
	context = zmq_ctx_new();
	socket = zmq_socket(context, ZMQ_PAIR);
	int rc = zmq_bind(socket, "tcp://*:5555");
	pressure = -1.0;
	assert(rc==0);

}

void pollpressure(double* p, int* rxed)
{
	char value[100];
	int rc;
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

void cleanup_steering()
{
	zmq_close(socket);
	zmq_ctx_destroy(context);
}

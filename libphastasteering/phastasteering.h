#ifndef __PHASTASTEERING_H__
#define __PHASTASTEERING_H__
#include "FCMangle.h"

#define init_steering FortranCInterface_GLOBAL_(init_steering, INIT_STEERING)
#define pollpressure FortranCInterface_GLOBAL_(pollpressure, POLLPRESSURE)
#define cleanup_steering FortranCInterface_GLOBAL_(cleanup_steering, CLEANUP_STEERING)

void init_steering();
void pollpressure(double* p, int* rxed);
void cleanup_steering();

#endif

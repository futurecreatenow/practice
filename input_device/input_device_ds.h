#include <stdio.h>

#include "../mydef/mydef.h"

#ifndef INPUT_DEVICE_DS_H
#define INPUT_DEVICE_DS_H

typedef struct input_device_ {
   FILE* inputFile;
   boolean eofReached;
} input_device, *acc_input_device;

#endif

#ifndef INPUT_DEVICE_H
#define INPUT_DEVICE_H

#include <mydef.h>

#include <input_device_ds.h>

extern acc_input_device INDCreate(FILE*);
extern void INDDispose(acc_input_device);
extern void INDSet_EOF(acc_input_device);
extern void INDReset_EOF(acc_input_device);
extern boolean INDEOF_Reached(acc_input_device);
extern char INDGet_Char(acc_input_device);

#endif


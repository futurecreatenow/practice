#include <stdio.h>

#include <mydef.h>

#include <input_device_ds.h>
#include <stm_ds.h>

#ifndef STRING_INPUT_DEVICE_DS_H
#define STRING_INPUT_DEVICE_DS_H

typedef struct string_input_device_ {
   acc_input_device accInputDev;
   acc_stm *stms;
   int noSTMs;
} string_input_device, *acc_string_input_device;

#endif

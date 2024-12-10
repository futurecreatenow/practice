#ifndef STRING_INPUT_DEVICE_H
#define STRING_INPUT_DEVICE_H

#include <mydef.h>

#include <input_device.h>
#include <string_input_device_ds.h>

extern acc_string_input_device SIDCreate(FILE*, int);
extern void SIDDDispose(acc_string_input_device);
extern void SIDPut_STM(acc_string_input_device, acc_stm, int);
extern string SIDGet_Token(acc_string_input_device);
extern boolean SIDEOF_Reached(acc_string_input_device);

#endif


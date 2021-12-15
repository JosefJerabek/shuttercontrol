#ifndef IO_STATE_NAME_H
#define IO_STATE_NAME_H

#include "global.h"

#ifndef ARDUINO

#include <string>
std::string GetIoStateName(IoState ioState);

#endif // ARDUINO

#endif

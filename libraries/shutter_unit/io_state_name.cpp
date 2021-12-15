#include "io_state_name.h"

#ifndef ARDUINO

std::string GetIoStateName(IoState ioState)
{
    switch (ioState) {
        case IO_NONE:
            return("IO_NONE");
        case IO_UP:
            return("IO_UP");
        case IO_DOWN:
            return("IO_DOWN");
        case IO_BOTH:
            return("IO_BOTH");
    };
    return("IO_NONE");
};

#endif
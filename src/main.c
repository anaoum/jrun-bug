#include "SEGGER_RTT.h"

int main() {
    unsigned long counter = 0;
    while (1) {
        char buffer[64];
        int length = sprintf(buffer, "Hello, World #%lu!\n", counter++);
        SEGGER_RTT_Write(0, buffer, length);
        for (unsigned long i = 0; i < 10000000; ++i);
    }
    return 0;
}

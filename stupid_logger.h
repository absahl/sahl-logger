#ifndef STUPID_LOGGER_H
#define STUPID_LOGGER_H

#include <time.h>
#include <stdio.h>

void log_debug(const char* tag, const char* message)
{
    time_t now;
    time(&now);
    printf("%s [%s]: %s\n", ctime(&now), tag, message);
}

#endif

#ifndef STUPID_LOGGER_H
#define STUPID_LOGGER_H

#include <time.h>
#include <stdio.h>

void stupid_log(const char* tag, const char* message)
{
    time_t now;
    time(&now);
    printf("%s [%s]: %s\n", ctime(&now), tag, message);
}

#endif

#ifndef STUPID_LOGGER_H
#define STUPID_LOGGER_H

#include <time.h>
#include <stdio.h>
#include <string.h>

static void slog_format(const char* tag, const char* message)
{
    time_t now = {0};
    const char* now_str = NULL;

    time(&now);
    now_str = ctime(&now);
    printf("%.*s %s %s\n", (int)(strlen(now_str) - 1), now_str, tag, message);
}

void slog_debug(const char* message)
{
    slog_format("DEBUG", message);
}

#endif

#ifndef STUPID_LOGGER_H
#define STUPID_LOGGER_H

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <syslog.h>

static void syslog_ex(const int priority, const char* format, ...)
{
    va_list arglist = {0};

    openlog("SLOGGER", LOG_PID, LOG_USER);
    va_start(arglist, format);
    vsyslog(priority, format, arglist);
    va_end(arglist);
    closelog();
}

static void slog_format(const char* tag, const char* format, va_list arglist)
{
    time_t now = {0};
    const char* now_str = NULL;
    char* _format = NULL;
    size_t _format_length = 0;

    time(&now);
    now_str = ctime(&now);

    // timestamp + 1B (space character) + tag + 1B (space character) +
    // format (in argument) + 1B (end of line character) + 1B (null character)
    _format_length = (strlen(now_str) - 1) + 1 + strlen(tag) + 1 + strlen(format) + 1 + 1;
    _format = (char*)malloc(_format_length);
    if (!_format)
    {
        syslog_ex(LOG_ERR, "failed to allocate memory for format string [%u bytes]", _format_length);
        return;
    }
    sprintf(_format, "%.*s %s %s\n", (int)(strlen(now_str) - 1), now_str, tag, format);

    vprintf(_format, arglist);
    free(_format);
}

void slog_init()
{
    syslog_ex(LOG_INFO, "logger initialized");
}

void slog_debug(const char* format, ...)
{
    va_list arglist;
    va_start(arglist, format);
    slog_format("DEBUG", format, arglist);
    va_end(arglist);
}

void slog_info(const char* format, ...)
{
    va_list arglist;
    va_start(arglist, format);
    slog_format("INFO", format, arglist);
    va_end(arglist);
}

void slog_warn(const char* format, ...)
{
    va_list arglist;
    va_start(arglist, format);
    slog_format("WARN", format, arglist);
    va_end(arglist);
}

void slog_error(const char* format, ...)
{
    va_list arglist;
    va_start(arglist, format);
    slog_format("ERROR", format, arglist);
    va_end(arglist);
}

#endif

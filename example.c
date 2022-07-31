#include "stupid_logger.h"

int main()
{
    slog_debug("debug log");
    slog_info("info log");
    slog_warn("warn log");
    slog_error("error log");
    return 0;
}

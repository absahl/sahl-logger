#include "stupid_logger.h"

int main()
{
    slog_init(); //optional
    slog_debug("This is very %s. But I would rather want it to be %s%c %d out of %d to be exact%c", "fine", "amazing", '.', 100, 100, '!');
    return 0;
}

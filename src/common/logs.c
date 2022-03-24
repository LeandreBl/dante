#include <stdarg.h>
#include <stdio.h>

void logs_error(const char *format, ...)
{
    va_list va;
    va_start(va, format);
    vfprintf(stderr, format, va);
    va_end(va);
}
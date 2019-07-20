#include "Log.h"
#include <QtGlobal>
#include <cstdarg>

Log* Log::GetLogInstace()
{
    static Log log;
    return &log;
}

void Log::Info(const char* funcInfo,...)
{
    va_list args;
    va_start(args, funcInfo);

    qDebug(funcInfo, args);

    va_end(args);
}

void Log::Error(const char* funcInfo...)
{
    va_list args;
    va_start(args, funcInfo);

    qCritical(funcInfo, args);

    va_end(args);
}

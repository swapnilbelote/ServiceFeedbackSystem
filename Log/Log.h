#ifndef LOG_H
#define LOG_H

class Log
{
public:
    static Log* GetLogInstace();
    void Info(const char* funInfo...);
    void Error(const char* funcInfo...);

private:
    Log() = default;
    ~Log() = default;
};

#define LogInfo(...) Log::GetLogInstace()->Info(__VA_ARGS__)
#define LogError(...) Log::GetLogInstace()->Error(__VA_ARGS__)

#endif // LOG_H

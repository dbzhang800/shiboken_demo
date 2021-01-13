
#pragma once

#if defined _WIN32
    #if DEMOCPPLIB_BUILD
        #define DEMOCPPLIB_API __declspec(dllexport)
    #else
        #define DEMOCPPLIB_API __declspec(dllimport)
    #endif
#else
    #define DEMOCPPLIB_API
#endif


class DEMOCPPLIB_API DemoCppClass
{
public:
    DemoCppClass();
    ~DemoCppClass();
private:
};


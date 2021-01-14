
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

#include <string>

class DEMOCPPLIB_API DemoCppClass
{
public:
    DemoCppClass();
    ~DemoCppClass();

    void setName(const std::string &name);
    std::string name() const;

    static std::string className();

private:
    std::string m_name;
};


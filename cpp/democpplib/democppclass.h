
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
#include <vector>

class DEMOCPPLIB_API DemoCppClass
{
public:
    DemoCppClass();
    ~DemoCppClass();

    void setName(const std::string &name);
    std::string name() const;

    std::vector<int> values() const;
    void setValues(const std::vector<int> &values);

    static std::string className();
    static std::vector<DemoCppClass *> allDemoCppClasses();

private:
    std::string m_name;
    std::vector<int> m_values;
};

void DEMOCPPLIB_API setGlobalValues(const std::vector<int> &values);

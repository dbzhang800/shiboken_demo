
#include "democppclass.h"

DemoCppClass::DemoCppClass()
{
}

DemoCppClass::~DemoCppClass()
{
}

void DemoCppClass::setName(const std::string &name)
{
    m_name = name;
}

std::string DemoCppClass::name() const
{
    return m_name;
}

std::vector<int> DemoCppClass::values() const
{
    return m_values;
}

void DemoCppClass::setValues(const std::vector<int> &values)
{
    m_values = values;
}

std::string DemoCppClass::className()
{
    return "DemoCppClass";
}

std::vector<DemoCppClass *> DemoCppClass::allDemoCppClasses()
{
    return std::vector<DemoCppClass *>();
}

void setGlobalValues(const std::vector<int> &values)
{
}


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

std::string DemoCppClass::className()
{
    return "DemoCppClass";
}

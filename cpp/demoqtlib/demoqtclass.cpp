
#include "demoqtclass.h"

DemoQtClass::DemoQtClass()
{
}

DemoQtClass::~DemoQtClass()
{
}

int DemoQtClass::value() const
{
    return m_value;
}

void DemoQtClass::setValue(int value)
{
    m_value = value;
}

QVector<int> DemoQtClass::values() const
{
    return m_values;
}

void DemoQtClass::setValues(const QVector<int> &values)
{
    m_values = values;
}

std::vector<int> DemoQtClass::stdValues() const
{
    return std::vector<int>(m_values.begin(), m_values.end());
}

void DemoQtClass::setStdValues(const std::vector<int> &values)
{
    m_values = QVector<int>(values.begin(), values.end());
}


#pragma once

#include <QObject>
#include <QVector>
#include <vector>

#if DEMOQTLIB_BUILD
#define DEMOQTLIB_API Q_DECL_EXPORT
#else
#define DEMOQTLIB_API Q_DECL_IMPORT
#endif

class DEMOQTLIB_API DemoQtClass : public QObject
{
    Q_OBJECT
public:
    DemoQtClass();
    ~DemoQtClass();

    int value() const;
    void setValue(int value);

    QVector<int> values() const;
    void setValues(const QVector<int> &values);

    std::vector<int> stdValues() const;
    void setStdValues(const std::vector<int> &values);

private:
    int m_value;
    QVector<int> m_values;
};

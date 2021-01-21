
#pragma once

#include <QObject>
#include <QVector>
#include <QString>
#include <vector>

#if DEMOQTLIB_BUILD
#define DEMOQTLIB_API Q_DECL_EXPORT
#else
#define DEMOQTLIB_API Q_DECL_IMPORT
#endif

class QRectF;

class DEMOQTLIB_API DemoQtClass : public QObject
{
    Q_OBJECT
public:
    DemoQtClass();
    ~DemoQtClass();

    void testForwardDeclare(const QRectF &rect);

    int value() const;
    void setValue(int value);

    QVector<int> values() const;
    void setValues(const QVector<int> &values);

    std::vector<int> stdValues() const;
    void setStdValues(const std::vector<int> &values);

    static DemoQtClass *getDemoQtClass(const QString &id);
    static DemoQtClass *getDemoQtClass(const QString &id, int dump);

    // Cannot extracted by shiboken when std::function is used as argument
    static DemoQtClass *getDemoQtClass(const QString &id, const std::function<bool()> &filter);

private:
    int m_value;
    QVector<int> m_values;
};

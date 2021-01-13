
#pragma once

#include <QObject>

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
private:
};


#ifndef QEXE_H
#define QEXE_H

#include <QObject>
#include <QIODevice>

#include "QExe_global.h"
#include "qexeerrorinfo.h"
#include "qexedosstub.h"
#include "qexecoffheader.h"
#include "qexeoptheader.h"

class QEXE_EXPORT QExe : QObject
{
    Q_OBJECT
public:
    explicit QExe(QObject *parent = nullptr);
    void reset();
    bool read(QIODevice &src, QExeErrorInfo *error = nullptr);
    QByteArray toBytes();
    QExeDOSStub &dosStub();
    QExeCOFFHeader &coffHead();
    QExeOptHeader &optHead();
private:
    QExeDOSStub *m_dosStub;
    QExeCOFFHeader *m_coffHead;
    QExeOptHeader *m_optHead;
};

#endif // QEXE_H

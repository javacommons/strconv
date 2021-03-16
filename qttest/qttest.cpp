#include <QtTest/QtTest>

#include "strconvQt.h"

class TestStrconv: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void cleanupTestCase();
    void test01();
};

void TestStrconv::initTestCase()
{
    qDebug() << "initTestCase() called";
}

void TestStrconv::cleanupTestCase()
{
    qDebug() << "cleanupTestCase() called";
    //QFAIL("xyz");
}

void TestStrconv::test01()
{
    std::wstring ws = L"漢字=한자";
    QString qs = wide_to_qstr(ws);
    QCOMPARE(qs, L"漢字=한자");
}

QTEST_MAIN(TestStrconv)
#include "qttest.moc"

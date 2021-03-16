#include <QtTest/QtTest>

#include "strconvQt.h"

class TestStrconv: public QObject
{
    Q_OBJECT
private slots:
    void initTestCase();
    void cleanupTestCase();
    void test01();
    void test02();
    void test03();
    void test04();
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
    std::wstring ws2 = qstr_to_wide(qs);
    QCOMPARE(ws2, L"漢字=한자");
}

void TestStrconv::test02()
{
    QString qs = "漢字=한자";
    std::string as = qstr_to_ansi(qs);
    QCOMPARE(as, utf8_to_ansi("漢字=한자"));
    QString qs2 = ansi_to_qstr(utf8_to_ansi("漢字=한자"));
    QCOMPARE(qs2, L"漢字=??");
}

void TestStrconv::test03()
{
    QString qs = "漢字=한자";
    std::string as = qstr_to_sjis(qs);
    QCOMPARE(as, utf8_to_sjis("漢字=한자"));
    QString qs2 = sjis_to_qstr(utf8_to_sjis("漢字=한자"));
    QCOMPARE(qs2, L"漢字=??");
}

void TestStrconv::test04()
{
    QString qs = "漢字=한자";
    std::string as = qstr_to_utf8(qs);
    QCOMPARE(as, "漢字=한자");
    QString qs2 = utf8_to_qstr("漢字=한자");
    QCOMPARE(qs2, L"漢字=한자");
}

QTEST_MAIN(TestStrconv)
#include "qttest.moc"

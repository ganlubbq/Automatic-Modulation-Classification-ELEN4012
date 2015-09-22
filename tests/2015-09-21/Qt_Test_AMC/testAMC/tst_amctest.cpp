#include <QString>
#include <QtTest>
#include <amc.h>
#include <iostream>

class AMCTest : public QObject
{
    Q_OBJECT

public:
    AMCTest();

private Q_SLOTS:
    void absReal();
    void absComplex();
    void meanComplex();
    void meanReal();
    void stdDev();
    void stdDevKurtosisReal();
    //void stdDevKurtosisComplex();
};

AMCTest::AMCTest()
{
}

void AMCTest::absReal()
{
    size_t N = 5;
    std::vector<double> a(N);
    std::vector<double> b(N);

    for (size_t n = 0; n < N; ++n)
    {
        a[n] = (double) 0-n;
        b[n] = (double) n;

    }

    QCOMPARE(b, AMC::abs(a));
}

void AMCTest::absComplex()
{
    size_t N = 5;
    std::vector<double> b(N);
    std::vector<std::complex<double> > aC(N);

    for (size_t n = 0; n < N; ++n)
    {
        aC[n] = std::complex<double>((double) 0-n,0);
        b[n] = (double) n;
    }

    QCOMPARE(b, AMC::abs(aC));
}

void AMCTest::meanComplex()
{
    size_t N = 10;
    std::vector<std::complex<double> > a(N);
    for (size_t n = 0; n < N; ++n)
    {
        a[n] = std::complex<double>(n,n);
    }
    auto b = AMC::mean(a);

    QCOMPARE(std::complex<double>(4.5, 4.5), b);
}

void AMCTest::meanReal()
{
    size_t N = 10;
    std::vector<double> a(N);
    for (size_t n = 0; n<N; ++n)
    {
        a[n] = (double) n;
    }
    auto b = AMC::mean(a);

    QCOMPARE((double) 4.5, b);
}

void AMCTest::stdDev()
{
    size_t N = 10;
    std::vector<double> a(N);
    for (size_t n = 0; n<N; ++n)
    {
        a[n] = (double) n;
    }
    auto b = AMC::stdDev(a);

    QCOMPARE( floor(b*10e4), floor(2.87228*10e4));
}

void AMCTest::stdDevKurtosisReal()
{
    size_t N = 10;
    std::vector<double> a(N);
    for (size_t n = 0; n<N; ++n)
    {
        a[n] = (double) n;
    }

    double stdDev = 0;
    double kurt = 0;

    AMC::stdDevKurtosis(a,stdDev,kurt);

    QCOMPARE(stdDev, 8.25);
    QCOMPARE(kurt, 1.7756);
}



QTEST_APPLESS_MAIN(AMCTest)

#include "tst_amctest.moc"

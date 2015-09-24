#ifndef AMC_H
#define AMC_H

#include <fftw3.h>
#include <vector>
#include <complex>
#include <boost/thread.hpp>

#define PI 3.141592654

namespace AMC
{
/* \brief Computes the FFT of a complex-valued signal
 *
 * This function is a wrapper for fftw3. It computes the Fast Fourier Transform of a vector of complex doubles
 *
 */
    std::vector<std::complex<double> > fft(
            std::vector<std::complex<double> > &x);
    std::vector<std::complex<double> > ifft(
            std::vector<std::complex<double> > &X);
    std::vector<std::complex<double> > instantaneousSignal(
            std::vector<std::complex<double> > &x);
    std::vector<double> instantaneousAmplitude(
            std::vector<std::complex<double> > &x);
    std::vector<double> instantaneousPhase(
            std::vector<std::complex<double> > &x);
    std::vector<double> unwrapPhase(
            std::vector<double> x_i_phase);
    std::vector<double> unwrappedInstantaneousPhase(
            std::vector<std::complex<double> > &x);
    std::vector<double> nonLinearUnwrappedInstantaneousPhase(
            std::vector<std::complex<double> > &x,
            const double &fc,
            const double &fs);

    auto abs(std::vector<double> x) -> std::vector<double>;
    auto abs(std::vector<std::complex<double> > x) -> std::vector<double>;
    auto mean(const std::vector<std::complex<double> > &x) -> std::complex<double>;
    auto mean(const std::vector<double> &x) -> double;
    auto stdDev(const std::vector<double> &x) -> double;
    auto stdDev(const std::vector<std::complex<double> > &x) -> double;
    void stdDevKurtosis(
            const std::vector<double> &x,
            double &stdDev,
            double &kurt);
    void stdDevKurtosis(
            const std::vector<std::complex<double> > &x,
            double &stdDev,
            double &kurt);
    auto differentiate(const std::vector<double> &x, const double &fs) -> std::vector<double>;
    auto absMax(const std::vector<double> &x) -> double;
    auto absMax(const std::vector<std::complex<double> > &x) -> double;
    auto max(const std::vector<std::complex<double> > &x) -> std::complex<double>;
    auto center(std::vector<double> x) -> std::vector<double>;
    auto center(std::vector<std::complex<double> > x) -> std::vector<std::complex<double> >;
    auto normalize(std::vector<double> x) -> std::vector<double>;
    auto normalize(std::vector<std::complex<double> > x) -> std::vector<std::complex<double> >;

    auto symmetry(const std::vector<std::complex<double> > &x, const double &fc, const double &fs) -> double;
    auto maxPower(const std::vector<double> &x) -> double;
    auto maxPower(const std::vector<std::complex<double> > &x) -> double;
}

#endif

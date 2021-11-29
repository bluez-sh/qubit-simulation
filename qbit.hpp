#ifndef _qbit_
#define _qbit_

#include <complex>
#include <exception>
#include <random>

class qbit
{
private:
    std::complex<double> alpha;
    std::complex<double> beta;

    const int resolution = 10000;
    std::default_random_engine re;
    std::uniform_int_distribution<> dist;
public:
    qbit();
    qbit(std::complex<double> alpha, std::complex<double> beta);
    ~qbit();

    void set_state(std::complex<double> alpha, std::complex<double> beta);
    std::pair<std::complex<double>, std::complex<double>> get_state();

    // Get probability of the first state e.g. |0>
    double get_probability();

    // Measure the qbit to collapse superposition into a definite state
    void measure();

    // Run experiment "sample_size" times and return occurrences of the first state
    static unsigned int simulate(const qbit& q, unsigned long sample_size);
};

#endif
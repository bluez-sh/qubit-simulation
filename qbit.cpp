#include "qbit.hpp"

qbit::qbit()
{
    qbit(1, 0);
}

qbit::qbit(std::complex<double> alpha, std::complex<double> beta): alpha(alpha), beta(beta), dist(1, resolution)
{
    if (ceil(alpha.real()*alpha.real() + alpha.imag()*alpha.imag() + beta.real()*beta.real() + beta.imag()*beta.imag()) != 1)
        throw std::invalid_argument("Coefficients not normalized");
    
    std::random_device r;
    re.seed(r());
}

qbit::~qbit()
{
}

double qbit::get_probability()
{
    return alpha.real()*alpha.real() + alpha.imag()*alpha.imag();
}

void qbit::measure()
{
    unsigned int div = ceil(get_probability() * resolution);
    unsigned int x = dist(re);
    if (x <= div) {
        alpha = 1;
        beta = 0;
    } else {
        alpha = 0;
        beta = 1;
    }
}

unsigned int qbit::simulate(const qbit& q, unsigned long sample_size)
{
    unsigned long count_first = 0;
    while (sample_size--) {
        qbit qtest(q.alpha, q.beta);
        qtest.measure();
        if (qtest.get_probability()) ++count_first;
    }
    return count_first;
}
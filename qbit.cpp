#include <complex>
#include <exception>
#include <random>
#include <iostream>

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

    // Get probability of the first state e.g. |0>
    double get_probability();

    // Measure the qbit to collapse superposition into a definite state
    void measure();

    // Run experiment "sample_size" times and return occurrences of the first state
    static unsigned int simulate(const qbit& q, unsigned long sample_size);
};

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
    while(sample_size--) {
        qbit qtest(q.alpha, q.beta);
        qtest.measure();
        if (qtest.get_probability()) ++count_first;
    }
    return count_first;
}

int main()
{
    qbit q(sqrt(1/3.0), sqrt(2/3.0));
    std::cout << "\nProb |0>: " << q.get_probability();
    std::cout << "\nProb |1>: " << 1-q.get_probability();

    // q.measure();
    // if (q.get_probability())
    //     std::cout << "\nMeasured: |0>";
    // else
    //     std::cout << "\nMeasured: |1>";
    
    const unsigned long sample_size = 8192;
    std::cout << "\n\n--- Simulation result ---";
    auto cnt = qbit::simulate(q, sample_size);
    auto percent = (cnt / static_cast<double>(sample_size)) * 100;
    std::cout << "\nCount |0>: " << cnt << ", " << percent << "%";
    std::cout << "\nCount |1>: " << sample_size-cnt << ", " << 100-percent << "%";

    return 0;
}

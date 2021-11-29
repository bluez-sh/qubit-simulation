#include <iostream>

#include "qbit.hpp"
#include "qoperators.hpp"

void run_simulation(const qbit& q)
{
    const unsigned long sample_size = 8192;
    std::cout << "\n\n--- Simulation result ---";
    auto cnt = qbit::simulate(q, sample_size);
    auto percent = (cnt / static_cast<double>(sample_size)) * 100;
    std::cout << "\nCount |0>: " << cnt << ", " << percent << "%";
    std::cout << "\nCount |1>: " << sample_size-cnt << ", " << 100-percent << "%";
}

void print_info(const qbit& q)
{
    std::cout << "\nProb |0>: " << q.get_probability();
    std::cout << "\nProb |1>: " << 1-q.get_probability();
    std::cout << "\nCoeffs: " << q.get_state().first << ", " << q.get_state().second;
}

int main()
{
    qbit q;
    print_info(q);
    
    qop::x(q);
    std::cout << "\n\nx-gate applied";
    print_info(q);

    qop::y(q);
    std::cout << "\n\ny-gate applied";
    print_info(q);

    qop::h(q);
    std::cout << "\n\nh-gate applied";
    print_info(q);

    qop::z(q);
    std::cout << "\n\nz-gate applied";
    print_info(q);

    run_simulation(q);

    std::cout << "\n";

    q.measure();
    if (q.get_probability())
        std::cout << "\nMeasured: |0>";
    else
        std::cout << "\nMeasured: |1>";

    return 0;
}
#include <iostream>

#include "qbit.hpp"

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
#ifndef _qensemble_
#define _qensemble_

#include "qbit.hpp"

#include <vector>

class qensemble
{
private:
    std::vector<std::complex<double>> cv;
public:
    qensemble(std::vector<qbit> qv);
    ~qensemble();

    std::vector<std::complex<double>>& get_state();
    std::vector<double> get_probabilities() const;
};

#endif
#include "qensemble.hpp"

using coeff_pair = std::pair<std::complex<double>, std::complex<double>>;

qensemble::qensemble(std::vector<qbit> qv)
{
    size_t n = pow(2, qv.size());
    std::vector<coeff_pair> states;
    for (auto q: qv)
        states.push_back(q.get_state());

    for (size_t i = 0; i < n; ++i)
        if (i % 2 == 0) cv.push_back(states[0].first);
        else cv.push_back(states[0].second);

    int rep = 2;
    for (size_t i = 1; i < states.size(); ++i, rep *= 2) {
        int cnt = -rep;
        for (size_t j = 0; j < n; ++j, ++cnt) {
            if (cnt < 0) cv[j] *= states[i].first;
            else cv[j] *= states[i].second;
            if (cnt == rep-1) cnt = -rep;
        }     
    }
}

qensemble::~qensemble()
{
}

std::vector<std::complex<double>>& qensemble::get_state()
{
    return cv;
}

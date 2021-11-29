#include "qoperators.hpp"

#include <array>

static std::pair<std::complex<double>, std::complex<double>>
apply(const std::array<double, 4>& mat, const std::pair<std::complex<double>, std::complex<double>>& v)
{
    std::pair<std::complex<double>, std::complex<double>> v_new;
    v_new.first = mat[0] * v.first + mat[1] * v.second;
    v_new.second = mat[2] * v.first + mat[3] * v.second;
    return v_new;
}

void qop::x(qbit& q)
{
    std::array<double, 4> mat = { 0, 1, 1, 0 };
    auto s = apply(mat, q.get_state());
    q.set_state(s.first, s.second);
}

void qop::h(qbit& q)
{
    std::array<double, 4> mat = { 1/sqrt(2), 1/sqrt(2), 1/sqrt(2), -1/sqrt(2) };
    auto s = apply(mat, q.get_state());
    q.set_state(s.first, s.second);
}
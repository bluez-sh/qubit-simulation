#include "qoperators.hpp"

#include <array>
#include <assert.h>

using coeff_pair = std::pair<std::complex<double>, std::complex<double>>;

static coeff_pair apply(const std::array<std::complex<double>, 4>& mat, coeff_pair v)
{
    coeff_pair v_new;
    v_new.first = mat[0] * v.first + mat[1] * v.second;
    v_new.second = mat[2] * v.first + mat[3] * v.second;
    return v_new;
}

static std::vector<std::complex<double>>
apply(const std::vector<std::vector<std::complex<double>>>& mat, const std::vector<std::complex<double>>& v)
{
    std::vector<std::complex<double>> v_new(v.size(), 0);
    assert(mat.size() == mat[0].size() && mat.size() == v.size());
    for (size_t i = 0; i < mat.size(); ++i)
        for (size_t j = 0; j < mat.size(); ++j)
            v_new[i] += mat[i][j] * v[j];
    return v_new;
}

qbit& qop::x(qbit& q)
{
    std::array<std::complex<double>, 4> mat = { 0, 1, 1, 0 };
    auto s = apply(mat, q.get_state());
    q.set_state(s.first, s.second);
    return q;
}

qbit& qop::y(qbit& q)
{
    std::array<std::complex<double>, 4> mat = { 0, {0, -1}, {0, 1}, 0 };
    auto s = apply(mat, q.get_state());
    q.set_state(s.first, s.second);
    return q;
}

qbit& qop::z(qbit& q)
{
    std::array<std::complex<double>, 4> mat = { 1, 0, 0, -1 };
    auto s = apply(mat, q.get_state());
    q.set_state(s.first, s.second);
    return q;
}

qbit& qop::h(qbit& q)
{
    std::array<std::complex<double>, 4> mat = {
        1/sqrt(2), 1/sqrt(2), 1/sqrt(2), -1/sqrt(2)
    };
    auto s = apply(mat, q.get_state());
    q.set_state(s.first, s.second);
    return q;
}

qensemble& qop::cx(qensemble& qens)
{
    assert(qens.get_state().size() == 4);
    std::vector<std::vector<std::complex<double>>> mat = {
        { 1, 0, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 0, 0, 1 },
        { 0, 0, 1, 0 }
    };
    qens.get_state() = apply(mat, qens.get_state());
    return qens;
}
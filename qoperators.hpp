#ifndef _qoperators_
#define _qoperators_

#include "qbit.hpp"

namespace qop {

    // Pauli-X gate
    void x(qbit& q);

    // Pauli-Y gate
    void y(qbit& q);

    // Pauli-Z gate
    void z(qbit& z);

    // Hadamard gate
    void h(qbit& q);
};

#endif
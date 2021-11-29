#ifndef _qoperators_
#define _qoperators_

#include "qbit.hpp"

namespace qop {

    // Pauli-X gate or "Invert" gate
    void x(qbit& q);

    // Hadamard gate
    void h(qbit& q);
};

#endif
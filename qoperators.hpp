#ifndef _qoperators_
#define _qoperators_

#include "qbit.hpp"
#include "qensemble.hpp"

namespace qop {

    //// Single qubit gates ////

    // Pauli-X gate
    qbit& x(qbit& q);

    // Pauli-Y gate
    qbit& y(qbit& q);

    // Pauli-Z gate
    qbit& z(qbit& q);

    // Hadamard gate
    qbit& h(qbit& q);

    //// Two qubit gates ////

    // CNOT gate
    qensemble& cx(qensemble& qens);
};

#endif
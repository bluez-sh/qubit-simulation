#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <qensemble.hpp>

using cd = std::complex<double>;

TEST_CASE( "qensemble init: 1 qubit", "[qensemble]" ) {
    qbit q0;
    std::vector<cd> v;

    v = qensemble({q0}).get_state();
    REQUIRE( v == std::vector<cd>{1, 0} );

    q0.set_state(0, 1);

    v = qensemble({q0}).get_state();
    REQUIRE( v == std::vector<cd>{0, 1} );
}

TEST_CASE( "qensemble init: 2 qubits", "[qensemble]" ) {
    qbit q0, q1;
    std::vector<cd> v;

    v = qensemble({q0, q1}).get_state();
    REQUIRE( v == std::vector<cd>{1, 0, 0, 0} );

    q0.set_state(0, 1);

    v = qensemble({q0, q1}).get_state();
    REQUIRE( v == std::vector<cd>{0, 1, 0, 0} );

    q1.set_state(0, 1);

    v = qensemble({q0, q1}).get_state();
    REQUIRE( v == std::vector<cd>{0, 0, 0, 1} );

    q0.set_state(1, 0);

    v = qensemble({q0, q1}).get_state();
    REQUIRE( v == std::vector<cd>{0, 0, 1, 0} );
}
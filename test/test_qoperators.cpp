#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <qoperators.hpp>

using cd = std::complex<double>;
using namespace qop;

TEST_CASE( "qop: x gate", "[qoperators]" ) {
    qbit q0;
    auto p = x(q0).get_state();
    REQUIRE( p == std::pair<cd, cd>{0, 1} );

    p = x(q0).get_state();
    REQUIRE( p == std::pair<cd, cd>{1, 0} );

    q0.set_state(1/sqrt(2), 1/sqrt(2));
    p = x(q0).get_state();
    REQUIRE( p == std::pair<cd, cd>{1/sqrt(2), 1/sqrt(2)} );
}

TEST_CASE( "qop: y gate", "[qoperators]" ) {
    qbit q0(0, 1);
    auto p = y(q0).get_state();
    REQUIRE( p == std::pair<cd, cd>{{0, -1}, 0} );

    p = y(q0).get_state();
    REQUIRE( p == std::pair<cd, cd>{0, 1} );
}

TEST_CASE( "qop: z gate", "[qoperators]" ) {
    qbit q0(1/sqrt(2), 1/sqrt(2));
    auto p = z(q0).get_state();
    REQUIRE( p == std::pair<cd, cd>{1/sqrt(2), -1/sqrt(2)} );

    p = z(q0).get_state();
    REQUIRE( p == std::pair<cd, cd>{1/sqrt(2), 1/sqrt(2)} );
}

TEST_CASE( "qop: h gate", "[qoperators]" ) {
    qbit q0;
    auto p = h(q0).get_state();
    REQUIRE( p == std::pair<cd, cd>{1/sqrt(2), 1/sqrt(2)} );

    p = h(q0).get_state();
    REQUIRE( std::abs(p.first - cd(1)) < 0.000001 ) ;
    REQUIRE( std::abs(p.second - cd(0)) < 0.000001 );
}

TEST_CASE( "qop: cx gate", "[qoperators]" ) {
    qensemble qens({qbit(), qbit()});
    auto p = cx(qens).get_state();
    REQUIRE( p == std::vector<cd>{1, 0, 0, 0} );

    qens.get_state() = {0, 1, 0, 0};
    p = cx(qens).get_state();
    REQUIRE( p == std::vector<cd>{0, 1, 0, 0} );

    qens.get_state() = {0, 0, 1, 0};
    p = cx(qens).get_state();
    REQUIRE( p == std::vector<cd>{0, 0, 0, 1} );

    qens.get_state() = {0, 0, 0, 1};
    p = cx(qens).get_state();
    REQUIRE( p == std::vector<cd>{0, 0, 1, 0} );

    qensemble qbell({qbit(), qbit(1/sqrt(2), 1/sqrt(2))});
    p = cx(qbell).get_state();
    REQUIRE( p == std::vector<cd>{1/sqrt(2), 0, 0, 1/sqrt(2)} );
}
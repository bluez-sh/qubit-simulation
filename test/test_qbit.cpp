#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <qbit.hpp>

using cd = std::complex<double>;

TEST_CASE( "qbit init", "[qbit]" ) {
    qbit q0;
    REQUIRE( q0.get_state().first == cd(1) );
    REQUIRE( q0.get_state().second == cd(0) );

    qbit q1(0, 1);
    REQUIRE( q1.get_state().first == cd(0) );
    REQUIRE( q1.get_state().second == cd(1) );
}

TEST_CASE( "qbit modify", "[qbit]" ) {
    qbit q0;
    q0.set_state(1/sqrt(2), 1/sqrt(2));
    REQUIRE( q0.get_state().first == cd(1/sqrt(2)) );
    REQUIRE( q0.get_state().second == cd(1/sqrt(2)) );
}

TEST_CASE( "qbit measure", "[qbit]" ) {
    qbit q0;
    q0.measure();

    REQUIRE( q0.get_state().first == cd(1) );
    REQUIRE( q0.get_state().second == cd(0) );

    q0.set_state(1/sqrt(2), 1/sqrt(2));
    q0.measure();

    REQUIRE( ( q0.get_state().first == cd(1) || q0.get_state().first == cd(0) ) );
    
    if (q0.get_state().first == cd(1)) {
        REQUIRE( q0.get_state().second == cd(0) ); 
    } else {
        REQUIRE( q0.get_state().second == cd(1) ); 
    }
}
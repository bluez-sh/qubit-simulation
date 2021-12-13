list(TRANSFORM PROJECT_SRCS PREPEND ../)

add_executable(test_qbit test_qbit.cpp ${PROJECT_SRCS})
add_test(test_qbit test_qbit)

add_executable(test_qensemble test_qensemble.cpp ${PROJECT_SRCS})
add_test(test_qensemble test_qensemble)

add_executable(test_qoperators test_qoperators.cpp ${PROJECT_SRCS})
add_test(test_qoperators test_qoperators)
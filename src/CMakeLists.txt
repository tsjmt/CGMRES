add_library(nmpcsolver STATIC matrixfree_gmres.cpp init_cgmres.cpp continuation_gmres.cpp)
add_library(simulator STATIC simulator.cpp numerical_integrator.cpp)
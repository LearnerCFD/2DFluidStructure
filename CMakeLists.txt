cmake_minimum_required(VERSION 2.8)
project(2DFluidStructure)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


#SET(EIGEN3_INCLUDE_DIR  "${PROJECT_SOURCE_DIR}/EIGEN" )
#IF( NOT EIGEN3_INCLUDE_DIR )
#    MESSAGE( FATAL_ERROR "Please point the environment variable EIGEN3_INCLUDE_3DIR to the include directory of your Eigen3 installation.")
#ENDIF()
#INCLUDE_DIRECTORIES ( "${EIGEN3_INCLUDE_DIR}" )


set(SOURCE_FILES main.cpp Intersector.cpp Intersector.h Segment_Hierarchy.cpp Segment_Hierarchy.h KD_Tree.cpp KD_Tree.h MatrixVec.h)

        #Fluid_Solver.cpp Fluid_Solver.h Structure_Solver.cpp Structure_Solver.h )
add_executable(2DFluidStructure ${SOURCE_FILES})
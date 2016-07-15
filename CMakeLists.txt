# This is the CMake script for compiling a CGAL application.


project(sample)

cmake_minimum_required(VERSION 2.8.11)

find_package(CGAL QUIET COMPONENTS ImageIO)

if ( CGAL_FOUND AND CGAL_ImageIO_FOUND )

  include( ${CGAL_USE_FILE} )
  include_directories(${CGAL_INCLUDE_DIRS})
  include_directories(include)

  #include( CGAL_CreateSingleSourceCGALProgram )

  #create_single_source_cgal_program( "mesh_a_3d_gray_image.cpp" )
  #create_single_source_cgal_program( "mesh_an_implicit_function.cpp" )
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fPIC")
  add_library(sample SHARED "src/test.cpp")
  target_link_libraries(sample ${CGAL_LIBRARIES})
else()
  if(RUNNING_CGAL_AUTO_TEST)
    # Just to avoid a warning from CMake if that variable is set on the command line...
  endif()
  
  message(STATUS "NOTICE: This program requires the CGAL and CGAL ImageIO libraries, and will not be compiled.")
  
endif()


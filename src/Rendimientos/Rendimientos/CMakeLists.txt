# CMakeList.txt : CMake project for Rendimientos, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Rendimientos "Rendimientos.c" "Rendimientos.h" "design_constants.h" "comp_tiempo.c" "comp_tiempo.h" "comp_area.c" "comp_area.h")

# TODO: Add tests and install targets if needed.

set(debao_module_name democpplib)

# ================================ Project configuration ======================================

# Specify which C++ files will be generated by shiboken. This includes the module wrapper
# and a '.cpp' file per C++ type. These are needed for generating the module shared
# library.
set(generated_sources
    ${CMAKE_CURRENT_BINARY_DIR}/${debao_module_name}binding/${debao_module_name}binding_module_wrapper.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/${debao_module_name}binding/democppclass_wrapper.cpp
    )


include(../binding_common.cmake)

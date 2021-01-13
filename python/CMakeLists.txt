
# ================================== Shiboken detection ======================================
# Use provided python interpreter if given.
if(NOT python_interpreter)
    find_program(python_interpreter "python")
endif()
message(STATUS "Using python interpreter: ${python_interpreter}")

# Macro to get various pyside / python include / link flags and paths.
# Uses the not entirely supported utils/pyside2_config.py file.
macro(pyside2_config option output_var)
    if(${ARGC} GREATER 2)
        set(is_list ${ARGV2})
    else()
        set(is_list "")
    endif()

    execute_process(
        COMMAND ${python_interpreter} "${CMAKE_CURRENT_SOURCE_DIR}/utils/pyside2_config.py"
              ${option}
      OUTPUT_VARIABLE ${output_var}
      OUTPUT_STRIP_TRAILING_WHITESPACE)

    if ("${${output_var}}" STREQUAL "")
        message(FATAL_ERROR "Error: Calling pyside2_config.py ${option} returned no output.")
    endif()
# Fix following code, which will fail when space exists in path
#    if(is_list)
#        string (REPLACE " " ";" ${output_var} "${${output_var}}")
#    endif()
endmacro()

# Query for the shiboken generator path, Python path, include paths and linker flags.
pyside2_config(--pyside2-path pyside2_module_path)
pyside2_config(--shiboken2-module-path shiboken2_module_path)
pyside2_config(--shiboken2-generator-path shiboken2_generator_path)
pyside2_config(--python-include-path python_include_dir)
pyside2_config(--shiboken2-generator-include-path shiboken_include_dir 1)
pyside2_config(--shiboken2-module-shared-libraries-cmake shiboken_shared_libraries 0)
pyside2_config(--pyside2-shared-libraries-cmake pyside2_link 0)
pyside2_config(--python-link-flags-cmake python_linking_data 0)


set(shiboken_path "${shiboken2_generator_path}/shiboken2${CMAKE_EXECUTABLE_SUFFIX}")
if(NOT EXISTS ${shiboken_path})
    message(FATAL_ERROR "Shiboken executable not found at path: ${shiboken_path}")
endif()

# ==================================== RPATH configuration ====================================


# =============================================================================================
# !!! (The section below is deployment related, so in a real world application you will want to
# take care of this properly with some custom script or tool).
# =============================================================================================
# Enable rpaths so that the built shared libraries find their dependencies.
set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH ${shiboken2_module_path} ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# =============================================================================================
# !!! End of dubious section.

add_subdirectory(democppbind)
add_subdirectory(demoqtbind)

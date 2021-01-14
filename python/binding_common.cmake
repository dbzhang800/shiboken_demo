# ================================ Project configuration ======================================
if (debao_required_qt_modules)
    find_package(Qt5 COMPONENTS ${debao_required_qt_modules} REQUIRED)
endif()

set(debao_pymodule_name ${debao_module_name}binding)

# The header file with all the types and functions for which bindings will be generated.
# Usually it simply includes other headers of the library you are creating bindings for.
set(wrapped_header ${CMAKE_CURRENT_SOURCE_DIR}/${debao_pymodule_name}.h)

# The typesystem xml file which defines the relationships between the C++ types / functions
# and the corresponding Python equivalents.
set(typesystem_file ${CMAKE_CURRENT_SOURCE_DIR}/${debao_pymodule_name}.xml)

# ====================== Shiboken target for generating binding C++ files  ====================

# Set up the options to pass to shiboken.
set(shiboken_options --generator-set=shiboken --enable-parent-ctor-heuristic
    --enable-return-value-heuristic --use-isnull-as-nb_nonzero
    --avoid-protected-hack
    --output-directory=${CMAKE_CURRENT_BINARY_DIR}
    )

set(includepaths ${CMAKE_SOURCE_DIR}/cpp/${debao_module_name})
foreach(module ${debao_required_qt_modules})
    list(APPEND includepaths ${Qt5${module}_INCLUDE_DIRS} ${pyside2_module_path}/include/Qt${module})
endforeach()
list(REMOVE_DUPLICATES includepaths)

foreach(path ${includepaths})
    list(APPEND shiboken_options -I${path})
endforeach()

if (debao_required_qt_modules)
    list(APPEND shiboken_options --enable-pyside-extensions -T${pyside2_module_path}/typesystems/ -I${pyside2_module_path}/include)
endif()

set(generated_sources_dependencies ${wrapped_header} ${typesystem_file})

# Add custom target to run shiboken to generate the binding cpp files.
add_custom_command(OUTPUT ${generated_sources}
                    COMMAND ${shiboken_path}
                    ${shiboken_options} ${wrapped_header} ${typesystem_file}
                    DEPENDS ${generated_sources_dependencies}
                    IMPLICIT_DEPENDS CXX ${wrapped_header}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                    COMMENT "Running generator for ${typesystem_file}.")


# =============================== CMake target - bindings_library =============================


# Set the cpp files which will be used for the bindings library.
set(${debao_pymodule_name}_sources ${generated_sources})

# Define and build the bindings library.
add_library(${debao_pymodule_name} MODULE ${${debao_pymodule_name}_sources})

# Apply relevant include and link flags.
target_include_directories(${debao_pymodule_name} PRIVATE ${python_include_dir})
target_include_directories(${debao_pymodule_name} PRIVATE ${shiboken_include_dir})
target_include_directories(${debao_pymodule_name} PRIVATE ${CMAKE_SOURCE_DIR}/cpp/${debao_module_name})

if (debao_required_qt_modules)
    target_include_directories(${debao_pymodule_name} PRIVATE ${pyside2_module_path}/include/)
endif()

foreach(module ${debao_required_qt_modules})
    target_include_directories(${debao_pymodule_name} PRIVATE ${pyside2_module_path}/include/Qt${module}/)
    target_link_libraries(${debao_pymodule_name} PRIVATE Qt::${module})
endforeach()

target_link_libraries(${debao_pymodule_name} PRIVATE ${shiboken_shared_libraries})
target_link_libraries(${debao_pymodule_name} PRIVATE ${pyside2_link})
target_link_libraries(${debao_pymodule_name} PRIVATE ${debao_module_name})


# Adjust the name of generated module.
set_property(TARGET ${debao_pymodule_name} PROPERTY PREFIX "")
set_property(TARGET ${debao_pymodule_name} PROPERTY OUTPUT_NAME
             "${debao_pymodule_name}${PYTHON_EXTENSION_SUFFIX}")
if(WIN32)
    set_property(TARGET ${debao_pymodule_name} PROPERTY SUFFIX ".pyd")
endif()

# Make sure the linker doesn't complain about not finding Python symbols on macOS.
if(APPLE)
  set_target_properties(${debao_pymodule_name} PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
endif(APPLE)

# Find and link to the python import library only on Windows.
# On Linux and macOS, the undefined symbols will get resolved by the dynamic linker
# (the symbols will be picked up in the Python executable).
if (WIN32)
    list(GET python_linking_data 0 python_libdir)
    list(GET python_linking_data 1 python_lib)
    find_library(python_link_flags ${python_lib} PATHS ${python_libdir} HINTS ${python_libdir})
    target_link_libraries(${debao_pymodule_name} PRIVATE ${python_link_flags})
endif()

# ================================= Dubious deployment section ================================

if(WIN32)
    set_target_properties(${debao_pymodule_name}
                           PROPERTIES LINK_FLAGS "${python_additional_link_flags}")
endif()

# =============================================================================================
# !!! (The section below is deployment related, so in a real world application you will want to
# take care of this properly with some custom script or tool).
# =============================================================================================
# Install the library and the bindings module into the source folder near the main.py file, so
# that the Python interpeter successfully imports the used module.
set(dist_dir "${CMAKE_SOURCE_DIR}/examples")

install(TARGETS ${debao_pymodule_name}
        LIBRARY DESTINATION "${dist_dir}"
        RUNTIME DESTINATION "${dist_dir}"
        )
# =============================================================================================
# !!! End of dubious section.
# =============================================================================================


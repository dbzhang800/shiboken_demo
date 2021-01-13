set(libname democpplib)

add_library(${libname} SHARED democppclass.cpp)
set_property(TARGET ${libname} PROPERTY PREFIX "")
target_compile_definitions(${libname} PRIVATE DEMOCPPLIB_BUILD)

set(dist_dir "${CMAKE_SOURCE_DIR}/examples")

install(TARGETS ${libname}
        LIBRARY DESTINATION "${dist_dir}"
        RUNTIME DESTINATION "${dist_dir}"
        )

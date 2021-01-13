
find_package(Qt5 COMPONENTS Core REQUIRED)
set(CMAKE_AUTOMOC ON)

set(libname demoqtlib)

add_library(${libname} SHARED demoqtclass.h demoqtclass.cpp)
set_property(TARGET ${libname} PROPERTY PREFIX "")
target_compile_definitions(${libname} PRIVATE DEMOQTLIB_BUILD)
target_link_libraries(${libname} PRIVATE Qt::Core)


set(dist_dir "${CMAKE_SOURCE_DIR}/examples")

install(TARGETS ${libname}
        LIBRARY DESTINATION "${dist_dir}"
        RUNTIME DESTINATION "${dist_dir}"
        )

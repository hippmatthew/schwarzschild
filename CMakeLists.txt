cmake_minimum_required(VERSION 3.21)

project(Schwarzchild)

find_package(Groot REQUIRED)

set(SOURCES
  ${CMAKE_SOURCE_DIR}/src/main.cpp
)

set(SHADERS
  ${CMAKE_SOURCE_DIR}/shaders/viewport.vert
  ${CMAKE_SOURCE_DIR}/shaders/viewport.frag
  ${CMAKE_SOURCE_DIR}/shaders/schwarzschild.comp
)

foreach(SHADER ${SHADERS})
  get_filename_component(FILE_NAME ${SHADER} NAME)
  set(SPV ${CMAKE_BINARY_DIR}/shaders/${FILE_NAME}.spv)

  add_custom_command(OUTPUT ${SPV}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/shaders
    COMMAND ${GLSLC} -o ${SPV} ${SHADER}
    DEPENDS ${SHADER}
    COMMENT "compiling ${SHADER}..."
  )

  list(APPEND SPVS ${SPV})
endforeach()

add_custom_target(shaders ALL DEPENDS ${SPVS})
add_executable(simulate ${SOURCES})
add_dependencies(simulate shaders)

target_include_directories(simulate PRIVATE
  ${CMAKE_SOURCE_DIR}
  /opt/homebrew/include
  /usr/local/include
)

target_link_directories(simulate PRIVATE
  /opt/homebrew/lib
  /usr/local/lib
)

target_link_libraries(simulate PRIVATE
  groot::groot
)
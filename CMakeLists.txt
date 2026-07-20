cmake_minimum_required (VERSION 3.20)

set(THIRDPARTY_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_SHARED_LIBS OFF)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141 AND MSVC)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<CONFIG:Debug,RelWithDebInfo>,EditAndContinue,ProgramDatabase>")
endif()

# better debugging in windows
set(CMAKE_CXX_FLAGS_DEBUG "-g -gdwarf-4 -O0 -fno-omit-frame-pointer")

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_subdirectory(${THIRDPARTY_ROOT})
set(XENONANALYSE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/XenonAnalyse)
set(XENONUTILS_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/XenonUtils)
set(XENONRECOMP_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/XenonRecomp)

project ("XenonRecomp-ALL")

add_subdirectory(${XENONANALYSE_ROOT})
add_subdirectory(${XENONRECOMP_ROOT})
add_subdirectory(${XENONUTILS_ROOT})

# Only tests if this is the top level project
if (${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    add_subdirectory(XenonTests)
endif()

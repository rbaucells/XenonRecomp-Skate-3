project("XenonTests")

file(GLOB TEST_FILES *.cpp)

if(TEST_FILES)
    add_executable(XenonTests 
        ${TEST_FILES}
    )
    target_link_libraries(XenonTests 
        PUBLIC 
            XenonUtils
            fmt::fmt
    )

    if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64|AMD64")
        if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
            target_compile_options(my_program PRIVATE -march=sandybridge "-Wno-unused-label" "-Wno-unused-variable")
        elseif(MSVC)
            target_compile_options(my_program PRIVATE /arch:AVX "-Wno-unused-label" "-Wno-unused-variable")
        endif()
    endif()
endif()

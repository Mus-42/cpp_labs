function(setup_target_warnings TARGET_NAME)
    # almost all "best practicies" warnings list

    if(MSVC)
        set(PROJECT_WARNINGS
            /W4 /w14242 /w14254 /w14263 /w14265 /w14287 /we4289 /w14296 /w14311 /w14545 /w14546 /w14547 /w14549 /w14555 /w14619 /w14640 /w14826 /w14905 /w14906 /w14928 /permissive-
        )
    elseif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(PROJECT_WARNINGS
            -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough
        )

        if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
            set(PROJECT_WARNINGS ${PROJECT_WARNINGS} -Wmisleading-indentation -Wduplicated-cond -Wuseless-cast -Wduplicated-branches -Wlogical-op)
        endif()
    else()
        message(WARNING "can't set waringings for ${CMAKE_CXX_COMPILER_ID}")
    endif()

    target_compile_options(${TARGET_NAME} PUBLIC ${PROJECT_WARNINGS})
endfunction()
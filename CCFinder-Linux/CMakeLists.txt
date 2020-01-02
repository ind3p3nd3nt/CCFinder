cmake_minimum_required(VERSION 3.14)
project(ccfinder)
set(Boost_DEBUG 1)
set(CMAKE_COMPILER "g++")
set(BOOST_ROOT "/usr/include/boost")
set(BOOST_LIBRARYDIR "/usr/include/boost")
find_package( Boost COMPONENTS system filesystem regex iostreams REQUIRED )
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
add_executable(ccfinder ccfinder-linux.cpp)
target_link_libraries(ccfinder ${Boost_LIBRARIES})
################################################################################
# Source groups
################################################################################
set(no_group_source_files
    "bootstrap.sh"
)
source_group("" FILES ${no_group_source_files})

set(Headers
    "header.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "ccfinder-linux.cpp"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${no_group_source_files}
    ${Headers}
    ${Sources}
)

################################################################################
# Target
################################################################################
add_executable(${ALL_FILES})

set(ROOT_NAMESPACE CCFinder_Linux)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Linux"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUG   "ccfinder"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUG   "$ENV{RemoteTargetPath}"
    )
endif()
################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "ARM")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Release>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "ARM64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Release>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                /showIncludes;
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY};
                /w;
                /TP
            >
            $<$<CONFIG:Release>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                ${DEFAULT_CXX_DEBUG_RUNTIME_LIBRARY}
            >
            $<$<CONFIG:Release>:
                ${DEFAULT_CXX_RUNTIME_LIBRARY}
            >
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        string(CONCAT FILE_CL_OPTIONS
            "$<$<CONFIG:Release>:"
                "-std=c++11"
            ">"
        )
    endif()
    source_file_compile_options(ccfinder-linux.cpp ${FILE_CL_OPTIONS})
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "ARM")
        target_link_options(${PROJECT_NAME} PRIVATE
            /DEBUG:FULL
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "ARM64")
        target_link_options(${PROJECT_NAME} PRIVATE
            /DEBUG:FULL
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:Debug>:
                -lboost_filesystem;
                -lboost_system;
                -lboost_iostreams;
                -lboost_regex
            >
            /DEBUG:FULL
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            /DEBUG:FULL
        )
    endif()
endif()

if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_link_directories(${PROJECT_NAME} PUBLIC
        "$<$<CONFIG:Debug>:"
            "/usr/include/boost"
        ">"
    )
endif()

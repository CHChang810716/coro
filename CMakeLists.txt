cmake_minimum_required(VERSION 3.10.0)
include(cmake/HunterGate.cmake)
set(
    HUNTER_CACHE_SERVERS
    "https://github.com/CHChang810716/hunter-binary-cache"
    CACHE
    STRING
    "Hunter cache servers"
)
HunterGate(
    URL "git@github.com:CHChang810716/hunter.git"
    SHA1 dd87828cd0a602394045f3462191b61501ceb49d
    FILEPATH ${CMAKE_CURRENT_LIST_DIR}/cmake/hunter_config.cmake
)

project(CppProjectTemplate
    LANGUAGES C CXX 
    VERSION 0.1.0.0
)
option(BUILD_TEST   "Build project with test"   OFF)
option(INSTALL_DEPS "Install dependensies"      OFF)
set(CMAKE_CXX_STANDARD 17)
include(cmake/packages.cmake)
include(cmake/src.cmake)
include(cmake/ide.cmake)
include(cmake/install.cmake)

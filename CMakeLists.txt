CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(fool2048)
SET(CMAKE_CXX_COMPILER g++)
ADD_DEFINITIONS(-std=c++0x)
ADD_DEFINITIONS(-O3)
SET(CMAKE_CXX_FLAGS "-Wno-unused-result")
SET(CMAKE_CXX_FLAGS "-g")
SET(CMAKE_EXE_LINKER_FLAGS "-g")

SET(GTEST_ROOT /usr/share/gtest-1.7.0)
SET(SRC src)
SET(TEST test)

INCLUDE_DIRECTORIES(${SRC} ${SRC}/board ${SRC}/player test ${GTEST_ROOT} ${GTEST_ROOT}/include)
ADD_SUBDIRECTORY(${SRC} build)

ENABLE_TESTING()

SET(GTEST_MAIN ${GTEST_ROOT}/src/gtest_main.cc)
SET(GTEST_LIBS ${GTEST_ROOT}/libgtest.a ${GTEST_ROOT}/libgtest_main.a /usr/local/lib/liblog4cplus.a rt pthread)

AUX_SOURCE_DIRECTORY(${SRC} SRCS)
AUX_SOURCE_DIRECTORY(${SRC}/board SRCS)
AUX_SOURCE_DIRECTORY(${SRC}/player SRCS)

SET(GTEST_EXECUTABLE ${SRCS} ${TEST} ${TEST}/board/full_board_testable.cc ${GTEST_MAIN})
LIST(REMOVE_ITEM GTEST_EXECUTABLE ${SRC}/main.cc)

ADD_TEST(NAME BoardTest COMMAND BoardTest)
ADD_EXECUTABLE(BoardTest test/board/board_test.cc ${GTEST_EXECUTABLE})
TARGET_LINK_LIBRARIES(BoardTest ${GTEST_LIBS})

ADD_TEST(NAME RandUtilTest COMMAND RandUtilTest)
ADD_EXECUTABLE(RandUtilTest test/rand_util_test.cc ${GTEST_EXECUTABLE})
TARGET_LINK_LIBRARIES(RandUtilTest ${GTEST_LIBS})

ADD_TEST(NAME FullBoardTest COMMAND FullBoardTest)
ADD_EXECUTABLE(FullBoardTest test/board/full_board_test.cc ${GTEST_EXECUTABLE})
TARGET_LINK_LIBRARIES(FullBoardTest ${GTEST_LIBS})

ADD_TEST(NAME DefaultAddingNumberPlayerTest COMMAND DefaultAddingNumberPlayerTest)
ADD_EXECUTABLE(DefaultAddingNumberPlayerTest test/player/default_adding_number_player_test.cc ${GTEST_EXECUTABLE})
TARGET_LINK_LIBRARIES(DefaultAddingNumberPlayerTest ${GTEST_LIBS})

ADD_TEST(NAME BoardHelperTest COMMAND BoardHelperTest)
ADD_EXECUTABLE(BoardHelperTest test/board/board_helper_test.cc ${GTEST_EXECUTABLE})
TARGET_LINK_LIBRARIES(BoardHelperTest ${GTEST_LIBS})
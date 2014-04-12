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

INCLUDE_DIRECTORIES(${SRC} test ${GTEST_ROOT} ${GTEST_ROOT}/include)

ENABLE_TESTING()

SET(GTEST_MAIN ${GTEST_ROOT}/src/gtest_main.cc)
SET(GTEST_LIBS ${GTEST_ROOT}/libgtest.a ${GTEST_ROOT}/libgtest_main.a /usr/local/lib/liblog4cplus.a rt pthread)

AUX_SOURCE_DIRECTORY(${SRC} SRCS)
AUX_SOURCE_DIRECTORY(${SRC}/board SRCS)
AUX_SOURCE_DIRECTORY(${SRC}/player SRCS)
AUX_SOURCE_DIRECTORY(${SRC}/game SRCS)

ADD_EXECUTABLE(fool2048 ${SRCS})
TARGET_LINK_LIBRARIES(fool2048 /usr/local/lib/liblog4cplus.a rt)

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

ADD_TEST(NAME RandomAddingNumberPlayerTest COMMAND RandomAddingNumberPlayerTest)
ADD_EXECUTABLE(RandomAddingNumberPlayerTest test/player/random_adding_number_player_test.cc ${GTEST_EXECUTABLE})
TARGET_LINK_LIBRARIES(RandomAddingNumberPlayerTest ${GTEST_LIBS})

ADD_TEST(NAME LocationHelperTest COMMAND LocationHelperTest)
ADD_EXECUTABLE(LocationHelperTest test/board/location_helper_test.cc ${GTEST_EXECUTABLE})
TARGET_LINK_LIBRARIES(LocationHelperTest ${GTEST_LIBS})

ADD_TEST(NAME FullBoardGameTest COMMAND FullBoardGameTest)
ADD_EXECUTABLE(FullBoardGameTest test/board/full_board_game_test.cc ${GTEST_EXECUTABLE})
TARGET_LINK_LIBRARIES(FullBoardGameTest ${GTEST_LIBS})

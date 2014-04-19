CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(fool2048)
SET(CMAKE_CXX_COMPILER g++)
ADD_DEFINITIONS(-std=c++0x)
ADD_DEFINITIONS(-O3)
SET(CMAKE_CXX_FLAGS "-Wno-unused-result -Wno-deprecated-declarations -g")
SET(CMAKE_EXE_LINKER_FLAGS "-g")

SET(GTEST_ROOT /usr/share/gtest-1.7.0)
SET(SRC src)
SET(TEST test)

INCLUDE_DIRECTORIES(${SRC})
LINK_DIRECTORIES(/opt/gcc-4.8.2/usr/local/gcc-4.8.2/lib64:/opt/gcc-4.8.2/usr/local/gcc-4.8.2/lib64:/usr/local/lib64:)

AUX_SOURCE_DIRECTORY(${SRC} SRCS)
AUX_SOURCE_DIRECTORY(${SRC}/board SRCS)
AUX_SOURCE_DIRECTORY(${SRC}/player SRCS)
AUX_SOURCE_DIRECTORY(${SRC}/game SRCS)

ADD_EXECUTABLE(fool2048 ${SRCS})
TARGET_LINK_LIBRARIES(fool2048 /usr/local/lib/liblog4cplus.a rt)

if (test)
  ENABLE_TESTING()

  INCLUDE_DIRECTORIES(test ${GTEST_ROOT} ${GTEST_ROOT}/include)

  SET(GTEST_MAIN ${GTEST_ROOT}/src/gtest_main.cc)
  SET(GTEST_LIBS ${GTEST_ROOT}/libgtest.a ${GTEST_ROOT}/libgtest_main.a /usr/local/lib/liblog4cplus.a rt pthread)


  SET(TESTS ${SRCS} ${GTEST_MAIN})
  AUX_SOURCE_DIRECTORY(${TEST} TESTS)
  AUX_SOURCE_DIRECTORY(${TEST}/board TESTS)
  AUX_SOURCE_DIRECTORY(${TEST}/player TESTS)
  LIST(REMOVE_ITEM TESTS ${SRC}/main.cc)

  ADD_EXECUTABLE(tests ${TESTS})
  TARGET_LINK_LIBRARIES(tests ${GTEST_LIBS})

  ADD_TEST(NAME BoardTest COMMAND tests)
  ADD_TEST(NAME RandUtilTest COMMAND tests)
  ADD_TEST(NAME FullBoardTest COMMAND tests)
  ADD_TEST(NAME RandomAddingNumberPlayerTest COMMAND tests)
  ADD_TEST(NAME LocationHelperTest COMMAND tests)
  ADD_TEST(NAME FullBoardGameTest COMMAND tests)
endif()

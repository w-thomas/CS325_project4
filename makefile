CXX = g++

CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

SRC1 = nn.cpp
SRC2 = 2opt.cpp
SRC3 = tsp.cpp
SRC4 = main.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4}

HEADER1 = nn.hpp
HEADER2 = 2opt.hpp
HEADER3 = tsp.hpp

PROG1 = tsp

default:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADER1} ${HEADER2} -o ${PROG1}

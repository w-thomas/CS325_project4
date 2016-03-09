CXX = g++

CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors

SRC1 = nn.cpp
SRC2 = 2opt.cpp
SRC3 = main.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

HEADER1 = nn.hpp
HEADER2 = 2opt.hpp

PROG1 = nn

default:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADER1} ${HEADER2} -o ${PROG1}

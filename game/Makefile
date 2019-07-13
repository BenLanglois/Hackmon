CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = game
MODULES = action move statMove debuffMove mobilityMove item potion debuffHeal mobilityHeal
OBJECTS = ${MODULES:=.o}
DEPENDS = ${MODULES:=.d}
ZIPPED = Makefile ${MODULES:=.h} ${MODULES:=.cc}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

${EXEC}.zip: ${ZIPPED}
	zip ${EXEC} ${ZIPPED}

.PHONY: clean debug zip

clean:
	rm -f ${OBJECTS} ${EXEC} ${DEPENDS} ${EXEC}.zip

debug: CXXFLAGS += -g
debug: ${EXEC}

zip: ${EXEC}.zip

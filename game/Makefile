CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = game
MODULES = action move statMove debuffMove mobilityMove item potion debuffHeal mobilityHeal hackmon player species
ADDITIONAL_FILES = game.cc actionInfo.h debuffInfo.h statInfo.h
OBJECTS = ${MODULES:=.o}
DEPENDS = ${MODULES:=.d}
ZIPPED = Makefile ${MODULES:=.h} ${MODULES:=.cc} ${ADDITIONAL_FILES}

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

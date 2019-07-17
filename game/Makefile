CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = game
MODULES = action actionQueue confusion debuff debuffHeal debuffMove family game gameConstants globalConstants hackmon item
MODULES += mobile mobility mobilityHeal mobilityMove move paralysis player potion randomGen sleep species statMove stats switch
ADDITIONAL_FILES = game.cc actionInfo.h debuffInfo.h mobilityInfo.h statInfo.h mobilityUtility.h gameConstants.h globalConstants.h
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

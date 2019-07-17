CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = game
MODULES = action actionQueue confusion debuff debuffHeal debuffInfo debuffMove family game gameConstants globalConstants
MODULES += hackmon item mobile mobility mobilityHeal mobilityInfo mobilityMove move paralysis player potion randomGen
MODULES += sleep species statInfo statMove stats switch type
OBJECTS = ${MODULES:=.o}
DEPENDS = ${MODULES:=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

${EXEC}.zip: ${ZIPPED}
	zip ${EXEC} ${ZIPPED}

.PHONY: clean debug local

clean:
	rm -f ${OBJECTS} ${EXEC} ${DEPENDS} ${EXEC}.zip

debug: CXXFLAGS += -g
debug: ${EXEC}

local: CXX = g++-9

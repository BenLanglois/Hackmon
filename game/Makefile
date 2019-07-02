CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = hackmon
OBJECTS = action.o
DEPENDS = ${OBJECTS:.o=.d}
ZIPPED = Makefile ${OBJECTS:.o=.h} ${OBJECTS:.o=.cc}

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

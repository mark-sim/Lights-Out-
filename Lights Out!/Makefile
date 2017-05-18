CXX=g++-5
CXXFLAGS=-std=c++14 -Werror=vla -MMD
OBJECTS=main.o window.o grid.o subject.o cell.o textdisplay.o graphicsdisplay.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=a4q2b
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11
-include ${DEPENDS}

clean:
	rm *.o main
.PHONY: clean

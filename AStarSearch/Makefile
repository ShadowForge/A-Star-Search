
# CS 480


.SUFFIXES: .o .cpp .x

CFLAGS=-ggdb

OBJECT_FILES= AStarSearch.o Node.o main.o


CS480p2.x: $(OBJECT_FILES)
	g++ $(CFLAGS) -o Project2.x $(OBJECT_FILES)

.cpp.o:
	g++ $(CFLAGS) -c $< -o $@

AStarSearch.o: AStarSearch.cpp AStarSearch.h Node.h
Node.o: Node.cpp Node.h
main.o: main.cpp AStarSearch.h Node.h

clean:
	rm -fr *.o *~ *.x

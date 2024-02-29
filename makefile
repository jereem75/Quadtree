CC = gcc
CFLAGS = -Wall -std=c17 -pedantic
LDLIBS = -lMLV -lm
TOUT = quadtree.o graphique.o arbre.o point.o main.o

quadtree: $(TOUT)
	$(CC) $(CFLAGS) -o quadtree $(TOUT) $(LDLIBS)

arbre.o: arbre.c arbre.h
	$(CC) $(CFLAGS) -c -o $@ $<

graphique.o: graphique.c graphique.h
	$(CC) $(CFLAGS) -c -o $@ $<

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $<

quadtree.o: QuadTree.c QuadTree.h
	$(CC) $(CFLAGS) -c -o $@ $<

point.o: Point.c Point.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	-rm  $(TOUT) quadtree
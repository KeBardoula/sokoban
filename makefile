CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: header

header: main.o game.o move.o win_loss.o
	$(CC) $(CFLAGS) -o header main.o game.o move.o win_loss.o
	
main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c
	
game.o: game.c header.h
	$(CC) $(CFLAGS) -c game.c
	
move.o: move.c header.h
	$(CC) $(CFLAGS) -c move.c

win_loss.o: win_loss.c header.h
	$(CC) $(CFLAGS) -c win_loss.c
	
clean:
	rm -f *.o header

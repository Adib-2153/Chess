CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I C:/raylib/raylib/src
LDFLAGS = -L C:/raylib/raylib/src -lraylib -lopengl32 -lgdi32 -lwinmm
TARGET = chess.exe
OBJS = main.o chess.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

main.o: main.c chess.h
	$(CC) $(CFLAGS) -c main.c

chess.o: chess.c chess.h
	$(CC) $(CFLAGS) -c chess.c

clean:
	rm -f $(OBJS) $(TARGET)


CC = gcc
CFLAGS = -Wall -O2
TARGET = add-nbo
OBJS = add-nbo.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJS): add-nbo.c
	$(CC) $(CFLAGS) -c add-nbo.c

clean:
	rm -f $(TARGET) $(OBJS)

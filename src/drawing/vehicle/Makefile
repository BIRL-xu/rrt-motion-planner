.SUFFIXES: .cpp

CC = g++
CFLAGS  = -Wall -O2 `pkg-config --cflags opencv`
LDLIBS  = -lm `pkg-config --libs opencv`

SRCS    = draw.cpp

OBJECTS = draw.o

TARGET = draw

CLEAN   = $(OBJECTS) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDLIBS)

.cpp.o:
	$(CC) ${CFLAGS} -c $<

run: $(TARGET)
	$(TARGET)

clean:
	/bin/rm -f $(CLEAN)


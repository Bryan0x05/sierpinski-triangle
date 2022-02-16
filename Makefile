CC = g++
CFLAGS = -Wall -Werror -pedantic
EXE = S_tri
LIBS = -lsfml-window -lsfml-system -lsfml-graphics
DEPS = Triangle.h
OBJS = TFractal.o Triangle.o 

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS) $(LIBS)
%.o : %.cpp $(DEPS)
	$(CC) -c  -o $@ $<
clean:
	rm $(EXE) $(OBJS)

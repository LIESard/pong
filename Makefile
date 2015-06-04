CC=c++
SRCDIR=src
FLAGS=-Wall -Werror -std=c++11 -c -g -O
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(notdir $(SRC:.cpp=.o))
OUT=pong

all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(LIBS)

%.o: $(SRCDIR)/%.cpp
	$(CC) $(FLAGS) $<

clean:
	rm -f $(OUT) $(OBJS)

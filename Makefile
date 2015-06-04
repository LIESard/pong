SRCDIR=src
CXXFLAGS=-Wall -Werror -std=c++11 -c -g -O
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SRC=$(wildcard $(SRCDIR)/*.cpp)
OBJS=$(SRC:.cpp=.o)
	OUT=pong
	 
all: $(OUT)
	 
$(OUT): $(OBJS)
		$(CXX) $(OBJS) -o $(OUT) $(LDFLAGS)
		 
clean:
		rm -f $(OUT) $(OBJS)


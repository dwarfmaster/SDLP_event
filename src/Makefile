include ../param.mk

OBJS=event.o myEvent.o anevent.o
DEST=../$(LIB)

CXXFLAGS=-Wall -Wextra `sdl-config --cflags` -fPIC -fsigned-bitfields -std=gnu++0x -g
LDFLAGS=-shared

all : $(OBJS)
	g++ $(CXXFLAGS)    -o $(DEST)	$^ $(LDFLAGS)
	chmod -x $(DEST)

%.o : %.cpp %.hpp
	g++ $(CXXFLAGS) -c -o $@	$<

clean :
	@touch $(OBJS) $(DEST)
	@rm -v $(OBJS) $(DEST)

rec : clean all


CC    =g++
LINK  =g++
DEBUG =-g
CFLAGS=-c -Wall -pedantic
LFLAGS=

CHECK		= cppcheck
CHECK_FLAGS	= --language=c++ --enable=all

# -DDEBUG_TRACE	Will turn on deep trace per function
# -DEXCEPTION	Will use the real exceptions with the 'try' that's in the test harness
CFLAGS += -DDEBUG_TRACE
CFLAGS += -DEXCEPTION

OBJS  = main.o stack.o test01.o poortool.o

all:	stack.exe splint-me

stack.exe:	$(OBJS)
	$(LINK) $(LFLAGS) $(OBJS) -o stack.exe

main.o:		main.cpp
	$(CC) $(CFLAGS) $(DEBUG) main.cpp -o main.o
stack.o:	stack.cpp stack.h
	$(CC) $(CFLAGS) $(DEBUG) stack.cpp -o stack.o
test01.o:	test01.cpp
	$(CC) $(CFLAGS) $(DEBUG) test01.cpp -o test01.o
poortool.o:	poortool.c
	$(CC) $(CFLAGS) $(DEBUG) poortool.c -o poortool.o

splint-me:
	$(CHECK) $(CHECK_FLAGS) .
	
clean:
	rm -f stack.exe
	rm -f stack.o
	rm -f main.o
	rm -f test01.o
	rm -f poortool.o
	rm -f core

#
# Fin
#


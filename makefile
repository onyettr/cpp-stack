#*******************************************************************************
# File name        : makeile
# File description : C++ Simple Stack 
# Author           : ronyett
#*******************************************************************************

SRC_DIR		= 	.
OBJECT_DIR	= 	$(SRC_DIR)/object
MAKE_DIR_CMD	= 	mkdir $(OBJECT_DIR)

#*******************************************************************************
# Tools required
#*******************************************************************************
CC    		=	g++
LINK  		=	g++
DEBUG 		=	-g
CFLAGS		=	-c -Wall -pedantic
LFLAGS=

CHECK		= 	cppcheck
CHECK_FLAGS	= 	--language=c++ --enable=all -igoogletest

# -DDEBUG_TRACE	Will turn on deep trace per function
#CFLAGS += -DDEBUG_TRACE

# Build objects
OBJS  = 	$(OBJECT_DIR)/main.o 	 		\
			$(OBJECT_DIR)/test_pop.o		\
			$(OBJECT_DIR)/test_push.o 		\
			$(OBJECT_DIR)/test_peek.o 		\
			$(OBJECT_DIR)/test_size.o 		\
			$(OBJECT_DIR)/test_empty.o 		\
			$(OBJECT_DIR)/test_display.o	\
			$(OBJECT_DIR)/test_overflow.o 	\
			$(OBJECT_DIR)/test_underflow.o
	
LIBS  = libstack.a

#*******************************************************************************
# Build targets:
# all	Creates object directory, builds executable and runs checker
# lib	Build only the list library, no test harness
#*******************************************************************************
all:	$(OBJECT_DIR) stack.exe splint-me

lib:	$(LIBS)

splint-me:
	$(CHECK) $(CHECK_FLAGS) .

$(OBJECT_DIR):
	-$(MAKE_DIR_CMD)

stack.exe:	$(OBJS) $(LIBS)
	$(LINK) $(LFLAGS) $(OBJS) -L -lstack -o stack.exe

libstack.a:	
#	$(AR) $(ARFLAGS) libstack.a $(OBJECT_DIR)/stack.o 

$(OBJECT_DIR)/main.o:		main.cpp
	$(CC) $(CFLAGS) $(DEBUG) main.cpp -o $(OBJECT_DIR)/main.o

#$(OBJECT_DIR)/stack.o:	stack.cpp stack.h
#	$(CC) $(CFLAGS) $(DEBUG) stack.cpp -o $(OBJECT_DIR)/stack.o


$(OBJECT_DIR)/test_pop.o:	test_pop.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_pop.cpp -o $(OBJECT_DIR)/test_pop.o

$(OBJECT_DIR)/test_push.o:	test_push.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_push.cpp -o $(OBJECT_DIR)/test_push.o

$(OBJECT_DIR)/test_peek.o:	test_peek.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_peek.cpp -o $(OBJECT_DIR)/test_peek.o

$(OBJECT_DIR)/test_size.o:	test_size.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_size.cpp -o $(OBJECT_DIR)/test_size.o

$(OBJECT_DIR)/test_empty.o:	test_empty.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_empty.cpp -o $(OBJECT_DIR)/test_empty.o

$(OBJECT_DIR)/test_display.o:	test_display.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_display.cpp -o $(OBJECT_DIR)/test_display.o

$(OBJECT_DIR)/test_overflow.o:	test_overflow.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_overflow.cpp -o $(OBJECT_DIR)/test_overflow.o

$(OBJECT_DIR)/test_underflow.o:	test_underflow.cpp
	$(CC) $(CFLAGS) $(DEBUG) test_underflow.cpp -o $(OBJECT_DIR)/test_underflow.o

$(OBJECT_DIR)/trap.o:		trap.cpp trap.h
	$(CC) $(CFLAGS) $(DEBUG) trap.cpp -o $(OBJECT_DIR)/trap.o

clean:
	rm -f stack.exe
	rm -f libstack.a
	rm -f $(OBJECT_DIR)/stack.o
	rm -f $(OBJECT_DIR)/main.o
	rm -f $(OBJECT_DIR)/trap.o
	rm -f $(OBJECT_DIR)/test_pop.o
	rm -f $(OBJECT_DIR)/test_push.o
	rm -f $(OBJECT_DIR)/test_peek.o
	rm -f $(OBJECT_DIR)/test_size.o
	rm -f $(OBJECT_DIR)/test_empty.o
	rm -f $(OBJECT_DIR)/test_display.o
	rm -f $(OBJECT_DIR)/test_overflow.o
	rm -f $(OBJECT_DIR)/test_underflow.o
	rm -f core

#
# Fin
#


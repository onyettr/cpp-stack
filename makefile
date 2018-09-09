#*******************************************************************************
# File name        : makeile
# File description : C++ Simple Stack 
# Author           : ronyett
#*******************************************************************************

SRC_DIR		= 	.
OBJECT_DIR	= 	$(SRC_DIR)/object
MAKE_DIR_CMD	= 	mkdir $(OBJECT_DIR)

CC    		=	g++
LINK  		=	g++
DEBUG 		=	-g
CFLAGS		=	-c -Wall -pedantic
LFLAGS=

CHECK		= cppcheck
CHECK_FLAGS	= --language=c++ --enable=all

# -DDEBUG_TRACE	Will turn on deep trace per function
# -DEXCEPTION	Will use the real exceptions with the 'try' that's in the test harness
#CFLAGS += -DDEBUG_TRACE
#CFLAGS += -DEXCEPTION

# Build objects
OBJS  = $(OBJECT_DIR)/main.o 	 	\
	$(OBJECT_DIR)/trap.o		\
	$(OBJECT_DIR)/test01.o 		\
	$(OBJECT_DIR)/test02.o 	

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

$(OBJECT_DIR)/test01.o:	test01.cpp
	$(CC) $(CFLAGS) $(DEBUG) test01.cpp -o $(OBJECT_DIR)/test01.o

$(OBJECT_DIR)/test02.o:	test02.cpp
	$(CC) $(CFLAGS) $(DEBUG) test02.cpp -o $(OBJECT_DIR)/test02.o

$(OBJECT_DIR)/trap.o:		trap.cpp trap.h
	$(CC) $(CFLAGS) $(DEBUG) trap.cpp -o $(OBJECT_DIR)/trap.o

clean:
	rm -f stack.exe
	rm -f libstack.a
	rm -f $(OBJECT_DIR)/stack.o
	rm -f $(OBJECT_DIR)/main.o
	rm -f $(OBJECT_DIR)/trap.o
	rm -f $(OBJECT_DIR)/test01.o
	rm -f $(OBJECT_DIR)/test02.o
	rm -f core

#
# Fin
#


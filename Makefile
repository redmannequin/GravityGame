CXX		= g++
DEL_FILE	= rm -f
DEL_DIR		= rm -r
LINK		= g++
LIBS		= -lSDL2 -lGL -lGLU -lGLEW

CLASS_FLAGS	= -g -c -std=c++11
 
PLAT		= bin/main.o		\
		  bin/window.o
 
TARGET		= GravityGame

$(TARGET): bin clean  $(PLAT)
	$(LINK) -g -o $(TARGET) $(PLAT) $(LIBS)

bin:
	if [ ! -d ./bin ]; then mkdir bin; fi;

clean: 
	-$(DEL_FILE) $(PLAT)
	-$(DEL_FILE) $(TARGET)

#--------------
#  MAIN GAME 
#--------------
bin/main.o:	./src/main.cc ./src/defs.h ./src/game_defs.h
	$(CXX) $(CLASS_FLAGS) -o ./bin/main.o ./src/main.cc

bin/window.o:	./src/window.cc ./src/window.h ./src/defs.h ./src/game_defs.h
	$(CXX) $(CLASS_FLAGS) -o ./bin/window.o ./src/window.cc


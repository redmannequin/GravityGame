CXX		= g++
DEL_FILE	= rm -f
DEL_DIR		= rm -r
LINK		= g++
LIBS		= -lSDL2 -lGL -lGLU -lGLEW
 
PLAT		= bin/main.o		\
		  bin/window.o

GAME		= bin/game.o		\
		  bin/vector2D.o	\
		  bin/physics.o		\
		  bin/polygon.o		\
		  bin/entity.o		\
                  bin/player.o
 
TARGET		= GravityGame

$(TARGET): bin clean  $(PLAT) $(GAME)
	$(LINK) -o $(TARGET) $(PLAT) $(GAME) $(LIBS)

bin:
	if [ ! -d ./bin ]; then mkdir bin; fi;

clean: 
	-$(DEL_FILE) $(PLAT)
	-$(DEL_FILE) $(GAME)
	-$(DEL_FILE) $(TARGET)

#--------------
#  MAIN GAME 
#--------------
bin/main.o:	./src/main.cc ./src/game.h ./src/defs.h ./src/game_defs.h
	$(CXX) -o ./bin/main.o -c ./src/main.cc

bin/window.o:	./src/window.cc ./src/window.h ./src/defs.h ./src/game_defs.h
	$(CXX) -o ./bin/window.o -c ./src/window.cc

bin/game.o:	./src/game.cc ./src/game.h ./src/math/vector2D.h ./src/defs.h ./src/game_defs.h
	$(CXX) -o ./bin/game.o -c ./src/game.cc

#--------
#  MATH
#--------
bin/vector2D.o:	./src/math/vector2D.cc ./src/math/vector2D.h ./src/defs.h
	$(CXX) -o ./bin/vector2D.o -c ./src/math/vector2D.cc

bin/physics.o:	./src/math/physics.cc ./src/math/physics.h ./src/math/vector2D.h
	$(CXX) -o ./bin/physics.o -c ./src/math/physics.cc

#--------------
#     DRAW     
#--------------
bin/polygon.o:	./src/draw/polygon.cc ./src/draw/polygon.h ./src/math/vector2D.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/polygon.o -c ./src/draw/polygon.cc

#---------------
#    ENTITYS  
#---------------
bin/entity.o:	./src/entity/entity.cc ./src/entity/entity.h ./src/math/vector2D.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/entity.o -c ./src/entity/entity.cc

bin/player.o:	./src/entity/player.cc ./src/entity/player.h ./src/math/vector2D.h ./src/math/physics.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/player.o -c ./src/entity/player.cc


CXX		= g++
DEL_FILE	= rm -f
LINK		= g++
LIBS		= -lSDL2 -lSDL2_image -lGL
 
OBJECTS		= bin/main.o		\
		  bin/window.o		\
		  bin/game.o		\
		  bin/vector2D.o	\
		  bin/draw.o		\
		  bin/polygon.o		\
		  bin/image.o		\
		  bin/entity.o		\
                  bin/player.o		\
		  bin/enemy.o		\
		  bin/space_object.o	\
		  bin/planet.o

MAIN		= bin/main.o		\
		  bin/window.o

GAME		= bin/game.o		\
		  bin/vector2D.o	\
		  bin/draw.o		\
		  bin/polygon.o		\
		  bin/image.o		\
		  bin/entity.o		\
                  bin/player.o		\
		  bin/enemy.o		\
		  bin/space_object.o	\
		  bin/planet.o
 
TARGET		= GravityGame
LIBRARIES	= ./lib/libgame.so

$(TARGET): clean bin  $(MAIN) $(LIBRARIES)
	$(LINK) -o $(TARGET) -g $(MAIN) $(LIBS) -lgame -L./lib/ -Wl,-rpath=./lib/

$(LIBRARIES): $(GAME)
	$(LINK) -shared -o ./lib/libgame.so $(GAME)

bin:
	if [ ! -d ./bin ]; then mkdir bin; fi;
	if [ ! -d ./lib ]; then mkdir lib; fi; 

clean: 
	-$(DEL_FILE) $(MAIN)
	-$(DEL_FILE) $(GAME)
	-$(DEL_FILE) $(TARGET)
	-$(DEL_FILE) $(LIBRARIES)

#--------------
#  MAIN GAME 
#--------------
bin/main.o:	./src/main.cc ./src/game.h ./src/defs.h ./src/game_defs.h
	$(CXX) -o ./bin/main.o -c ./src/main.cc

bin/window.o:	./src/window.cc ./src/window.h ./src/defs.h ./src/game_defs.h
	$(CXX) -o ./bin/window.o -c ./src/window.cc

bin/game.o:	./src/game.cc ./src/game.h ./src/vector2D.h ./src/defs.h ./src/game_defs.h
	$(CXX) -o ./bin/game.o -fPIC -c ./src/game.cc

bin/vector2D.o:	./src/vector2D.cc ./src/vector2D.h ./src/defs.h
	$(CXX) -o ./bin/vector2D.o -fPIC -c ./src/vector2D.cc

#--------------
#     DRAW     
#--------------
bin/draw.o:	./src/draw/draw.cc ./src/draw/draw.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/draw.o -fPIC -c ./src/draw/draw.cc

bin/polygon.o:	./src/draw/polygon.cc ./src/draw/polygon.h ./src/draw/draw.h ./src/vector2D.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/polygon.o -fPIC -c ./src/draw/polygon.cc

bin/image.o:	./src/draw/image.cc ./src/draw/image.cc ./src/draw/draw.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/image.o -fPIC -c ./src/draw/image.cc

#---------------
#    ENTITYS  
#---------------
bin/entity.o:	./src/entity/entity.cc ./src/entity/entity.h ./src/draw/draw.h ./src/vector2D.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/entity.o -fPIC -c ./src/entity/entity.cc

bin/player.o:	./src/entity/player.cc ./src/entity/player.h ./src/draw/draw.h ./src/vector2D.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/player.o -fPIC -c ./src/entity/player.cc

bin/enemy.o:	./src/entity/enemy.cc ./src/entity/enemy.h ./src/draw/draw.h ./src/vector2D.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/enemy.o -fPIC -c ./src/entity/enemy.cc

bin/space_object.o: ./src/entity/space_object.cc ./src/entity/space_object.h ./src/entity/entity.h ./src/draw/draw.h ./src/vector2D.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/space_object.o -fPIC -c ./src/entity/space_object.cc

bin/asteroid.o:	./src/entity/space_object/asteroid.cc ./src/entity/space_object/asteroid.h ./src/entity/entity.h ./src/draw/draw.h ./src/vecotr2D.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/entity.o -fPIC -c ./src/entity/entity.cc

bin/planet.o:	./src/entity/space_object/planet.cc ./src/entity/space_object/planet.h ./src/entity/entity.h ./src/draw/draw.h ./src/vector2D.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/planet.o -fPIC -c ./src/entity/space_object/planet.cc

bin/star.o:	./src/entity/space_object/star.cc ./src/entity/space_object/star.h ./src/entity/entity.h ./src/draw/draw.h ./src/vector2D.h ./src/game_defs.h ./src/defs.h
	$(CXX) -o ./bin/star.o -fPIC -c ./src/entity/star.cc

#---------------
#  COLLECTIONS
#---------------
bin/list.o:	./src/collections/list.cc ./src/collections/list.h ./defs.h
	$(CXX) -o ./bin/list.o -c ./src/collections/list.cc

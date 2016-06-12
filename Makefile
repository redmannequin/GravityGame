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
 
TARGET		= GravityGame

$(TARGET): clean bin  $(OBJECTS)
	$(LINK) -o $(TARGET) -g $(OBJECTS) $(LIBS)

bin:
	if [ ! -d ./bin ]; then mkdir bin; fi; 

clean: 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) $(TARGET)

#--------------
#  MAIN GAME 
#--------------
bin/main.o:	./main.cc ./game.h ./defs.h ./game_defs.h
	$(CXX) -o ./bin/main.o -c ./main.cc

bin/window.o:	./window.cc ./window.h ./defs.h ./game_defs.h
	$(CXX) -o ./bin/window.o -c ./window.cc

bin/game.o:	./game.cc ./game.h ./vector2D.h ./defs.h ./game_defs.h
	$(CXX) -o ./bin/game.o -c ./game.cc

bin/vector2D.o:	./vector2D.cc ./vector2D.h ./defs.h
	$(CXX) -o ./bin/vector2D.o -c ./vector2D.cc

#--------------
#     DRAW     
#--------------
bin/draw.o:	./draw/draw.cc ./draw/draw.h ./game_defs.h ./defs.h
	$(CXX) -o ./bin/draw.o -c ./draw/draw.cc

bin/polygon.o:	./draw/polygon.cc ./draw/polygon.h ./draw/draw.h ./vector2D.h ./game_defs.h ./defs.h
	$(CXX) -o ./bin/polygon.o -c ./draw/polygon.cc

bin/image.o:	./draw/image.cc ./draw/image.cc ./draw/draw.h ./game_defs.h ./defs.h
	$(CXX) -o ./bin/image.o -c ./draw/image.cc

#---------------
#    ENTITYS  
#---------------
bin/entity.o:	./entity/entity.cc ./entity/entity.h ./draw/draw.h ./vector2D.h ./game_defs.h ./defs.h
	$(CXX) -o ./bin/entity.o -c ./entity/entity.cc

bin/player.o:	./entity/player.cc ./entity/player.h ./draw/draw.h ./vector2D.h ./game_defs.h ./defs.h
	$(CXX) -o ./bin/player.o -c ./entity/player.cc

bin/enemy.o:	./entity/enemy.cc ./entity/enemy.h ./draw/draw.h ./vector2D.h ./game_defs.h ./defs.h
	$(CXX) -o ./bin/enemy.o -c ./entity/enemy.cc

bin/space_object.o: ./entity/space_object.cc ./entity/space_object.h ./entity/entity.h ./draw/draw.h ./vector2D.h ./game_defs.h ./defs.h
	$(CXX) -o ./bin/space_object.o -c ./entity/space_object.cc

bin/asteroid.o:	./entity/space_object/asteroid.cc ./entity/space_object/asteroid.h ./entity/entity.h ./draw/draw.h ./vecotr2D.h ./game_defs.h ./defs.h
	$(CXX) -o ./bin/entity.o -c ./entity/entity.cc

bin/planet.o:	./entity/space_object/planet.cc ./entity/space_object/planet.h ./entity/entity.h ./draw/draw.h ./vector2D.h ./game_defs.h ./defs.h
	$(CXX) -o ./bin/planet.o -c ./entity/space_object/planet.cc

bin/star.o:	./entity/space_object/star.cc ./entity/space_object/star.h ./entity/entity.h ./draw/draw.h ./vector2D.h ./game_defs.h ./defs.h
	$(CXX) -o ./bin/star.o -c ./entity/star.cc

#---------------
#  COLLECTIONS
#---------------
bin/list.o:	./collections/list.cc ./collections/list.h ./defs.h
	$(CXX) -o ./bin/list.o -c ./collections/list.cc

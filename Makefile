CXX           = g++
DEL_FILE      = rm -f
LINK          = g++
LIBS          = -lSDL2 
 
OBJECTS       = bin/main.o \
		bin/game.o \
		bin/vector2D.o \
		bin/polygon.o
 
TARGET        = GravityGame

$(TARGET): bin  $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS) $(LIBS)

bin:
	if [ ! -d ./bin ]; then mkdir bin; fi; 

clean: 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) $(TARGET)

bin/main.o: ./main.cc ./game.h ./vector2D.h
	$(CXX) -o ./bin/main.o -c ./main.cc

bin/game.o: ./game.cc ./game.h ./vector2D.h ./polygon.h
	$(CXX) -o ./bin/game.o -c ./game.cc

bin/vector2D.o: ./vector2D.cc ./vector2D.h
	$(CXX) -o ./bin/vector2D.o -c ./vector2D.cc

bin/polygon.o: ./polygon.cc ./polygon.h ./vector2D.h
	$(CXX) -o ./bin/polygon.o -c ./polygon.cc


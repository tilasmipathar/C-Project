CC=g++ 
all_sources=menu3.cpp brickbreaker/rungame.cpp brickbreaker/Brickbreaker.cpp brickbreaker/ball.cpp brickbreaker/textures.cpp	#all the .cpp files which are to be compiled
all_objs=$(all_sources:.cpp=.o)					 #object files created from the .cpp files

game: $(all_objs) 					 #creating excutable file
		$(CC) $(all_sources) -lSDL2 -lSDL2main -lSDL2_mixer -lSDL2_ttf -lSDL2_image -g -o game 
%.o: %.c 							 #creating object files
	$(CC) -c $(all_sources) 

clean:								 #removing the executable file and the object file
	rm game brickbreaker/rungame.o brickbreaker/Brickbreaker.o brickbreaker/ball.o brickbreaker/textures.o menu3.o
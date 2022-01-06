CC=g++ 
all_sources=game.cpp Brickbreaker.cpp rungame.cpp textures.cpp ball.cpp	#all the .cpp files which are to be compiled
all_objs=$(all_sources:.cpp=.o)					 #object files created from the .cpp files

brickbreaker: $(all_objs) 					 #creating excutable file
		$(CC) $(all_sources) -lSDL2 -lSDL2main -lSDL2_mixer -lSDL2_ttf -lSDL2_image -g -o brickbreaker 
%.o: %.c 							 #creating object files
	$(CC) -c $(all_sources) 

clean:								 #removing the executable file and the object file
	rm brickbreaker *.o
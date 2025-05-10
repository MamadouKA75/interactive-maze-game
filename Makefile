 
lab: obj/mainpiste.o obj/Piste.o

	g++ -Wall obj/mainpiste.o obj/Piste.o -o lab -L/opt/homebrew/lib -lSDL2 -lSDL2_ttf





obj/Piste.o: src/Piste.h src/Piste.cpp

	g++ -Wall -c src/Piste.cpp -o obj/Piste.o



obj/mainpiste.o: src/mainpiste.cpp src/Piste.h

	g++ -Wall -c src/mainpiste.cpp -o obj/mainpiste.o -I/opt/homebrew/include/SDL2 -L/opt/homebrew/lib -lSDL2 -lSDL2_ttf



clean:

	rm ./obj/*.o

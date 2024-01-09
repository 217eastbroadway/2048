CC = g++
CFLAGS = -lPrism -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -static-libstdc++ -static-libgcc -Wl,-Bstatic -lstdc++ -lpthread -Wl,-Bdynamic -O2 -s -mwindows
INCLUDEPATH = lib/Prism/include
LIBPATH = lib/Prism/lib
BUILDNAME = build/game

game: main.o initPrism.o prismFinder.o moveUpdate.o randGeneration.o gameRenderUpdate.o
	$(CC) main.o initPrism.o prismFinder.o moveUpdate.o randGeneration.o gameRenderUpdate.o -L$(LIBPATH) $(CFLAGS) -o $(BUILDNAME)
	@echo -e "\033[0;32mProject built successfully!\033[0m"

main.o: src/main.cpp
	$(CC) src/main.cpp -I$(INCLUDEPATH) -c

#MISC
initPrism.o: src/misc/initPrism.cpp
	$(CC) src/misc/initPrism.cpp -I$(INCLUDEPATH) -c

prismFinder.o: src/misc/prismFinder.cpp
	$(CC) src/misc/prismFinder.cpp -I$(INCLUDEPATH) -c

#LOGIC
moveUpdate.o: src/logic/moveUpdate.cpp
	$(CC) src/logic/moveUpdate.cpp -I$(INCLUDEPATH) -c

randGeneration.o: src/logic/randGeneration.cpp
	$(CC) src/logic/randGeneration.cpp -I$(INCLUDEPATH) -c

#RENDER
gameRenderUpdate.o: src/render/gameRenderUpdate.cpp
	$(CC) src/render/gameRenderUpdate.cpp -I$(INCLUDEPATH) -c
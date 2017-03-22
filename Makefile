# Project: Test
# Makefile created by Dev-C++ 4.9.9.2

CPP  = g++.exe
CC   = gcc.exe
WINDRES = windres.exe
RES  = 
OBJ  = main.o constante.o vie.o affichageCompteur.o $(RES)
LINKOBJ  = main.o constante.o vie.o affichageCompteur.o $(RES)
LIBS =  -L"C:/Dev-Cpp/lib" -mwindows -lmingw32 -lSDLmain -lSDL -lmingw32 -lSDLmain -lSDL_image -lmingw32 -lSDLmain -lSDL_ttf2  
INCS =  -I"C:/Dev-Cpp/include" 
CXXINCS =  -I"C:/Dev-Cpp/lib/gcc/mingw32/3.4.2/include"  -I"C:/Dev-Cpp/include/c++/3.4.2/backward"  -I"C:/Dev-Cpp/include/c++/3.4.2/mingw32"  -I"C:/Dev-Cpp/include/c++/3.4.2"  -I"C:/Dev-Cpp/include" 
BIN  = Test
CXXFLAGS = $(CXXINCS)  
CFLAGS = $(INCS)  
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before Test.exe all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o "Test.exe" $(LIBS)

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

constante.o: constante.c
	$(CC) -c constante.c -o constante.o $(CFLAGS)

vie.o: vie.c
	$(CC) -c vie.c -o vie.o $(CFLAGS)

affichageCompteur.o: affichageCompteur.c
	$(CC) -c affichageCompteur.c -o affichageCompteur.o $(CFLAGS)

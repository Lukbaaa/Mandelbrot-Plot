all: compile link clean execute 

compile:
	g++ -c main.cpp -I"C:\Users\Lukas\Documents\c++\libraries\SFML-2.5.1\include" -DSFML_STATIC

link:
	g++ main.o -o main -LC:\Users\Lukas\Documents\c++\libraries\SFML-2.5.1\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -lsfml-main

clean:
	del -rf main *.o

execute:
	main


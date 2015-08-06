sfmlLib=-L/usr/lib/x86_64-linux-gnu/ -lsfml-graphics -lsfml-window -lsfml-system
sfmlIncDir=-I/usr/include

lpl: Source.o particle.o program.o
	g++ Source.o particle.o program.o -o lpl $(sfmlLib)

Source.o: Source.cpp program.hpp
	g++ Source.cpp program.hpp -c $(sfmlIncDir)

program.o: program.cpp program.hpp particle.hpp
	g++ program.cpp program.hpp particle.hpp -c $(sfmlIncDir)

particle.o: particle.cpp particle.hpp
	g++ particle.cpp particle.hpp -c $(sfmlIncDir)

clean :
	rm particle.o program.o Source.o

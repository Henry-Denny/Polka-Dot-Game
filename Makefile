Polka_Dot_Game.exe : ./src/*.cpp ./include/*.hpp
	g++ -o ./bin/Polka_Dot_Game.exe ./src/*.cpp ./bin/*.dll -I ./include
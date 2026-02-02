main: main.cpp
	g++ -o main src/Game/GameObject.cpp src/Game/Entity.cpp src/Game/Player.cpp main.cpp -I./include/Game -lraylib
#include "GameWindow.h"

NS_USE;

int main(int argv_count, int* argvs) {
	auto game = GameWindow();
	game.Start();
	game.Loop();
	game.Destroy();
	return 0;
}
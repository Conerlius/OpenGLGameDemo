#include "GameApplication.h"

NS_USE;

int main(int argv_count, int* argvs) {
	auto game = GameApplication();
	game.start();
	game.loop();
	game.destroy();
	return 0;
}
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "cpt_terminal.h"
int main(int argc, char *argv[]) {
	terminal_open(0);
	std::cout << "bla" << std::endl;
	sleep(3);
	terminal_close();
	return EXIT_SUCCESS;
}

#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <cpt_terminal.h>
#include <sys/neutrino.h>
#include <hw/inout.h>
int main(int argc, char *argv[]) {
	if(ThreadCtl(_NTO_TCTL_IO,0) < 0)
		return EXIT_FAILURE;
	while(!(in8(0x302) & 0x20)){
		if (!(in8(0x302) & 0x10)){
			out8(0x300, in8(0x300) | 0x10);
			usleep(1000000);
			out8(0x300, 0x01 | 0x20);
		}else{
			out8(0x300, 0x10 | 0x80);
			usleep(500000);
			out8(0x300, 0x10 | 0x20);
		}
	}
	return EXIT_SUCCESS;
}

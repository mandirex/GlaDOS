#include "../drivers/asm_utils.h"
#include "../drivers/scrn.h"

//80x25

void _start(){
	init_video();
	settextcolor(15,0);
	print_string("Hey!");

}
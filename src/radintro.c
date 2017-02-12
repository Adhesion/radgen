#include <genesis.h>

int main() {
	VDP_drawText("Hello World!!!", 10, 10);
	VDP_drawText("RADMARS is DA BEST", 13, 15);

	while (1) {
		VDP_waitVSync();
	}
	
	return 0;
}

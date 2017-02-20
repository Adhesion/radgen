#include <genesis.h>

#include "resources.h"

Sprite* glassesSprite;

void setupBackground() {
	VDP_drawImage(PLAN_B, &bg, 0, 0);
}

void setupSprites() {
	glassesSprite = SPR_addSprite(&glasses, 126, 106, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));

	// copy in palette from sprite data
	VDP_setPalette(PAL1, glasses.palette->data);
	
	SPR_update();
}

int main() {
	SPR_init(0, 0, 0);
	// set all palette to black
    VDP_setPaletteColors(0, (u16*)palette_black, 64);
	
	setupBackground();
	setupSprites();
	
	while (1) {
		SPR_update();
		VDP_waitVSync();
	}
	
	return 0;
}

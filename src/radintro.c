#include <genesis.h>

#include "resources.h"

#define RADMARS_VOICE_ID 64

Sprite* glassesSprite;
u32 frameCounter = 0;

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

	XGM_startPlay(xgmmusic);
	XGM_setPCM(RADMARS_VOICE_ID, voice, 42752);
	XGM_setLoopNumber(0);

	while (1) {
		SPR_update();

		if (frameCounter == 128) {
			XGM_startPlayPCM(RADMARS_VOICE_ID, 0, 1);
		}

		VDP_waitVSync();
		frameCounter++;
	}
	
	return 0;
}

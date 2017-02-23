#include <genesis.h>

#include "resources.h"

#define RADMARS_VOICE_ID 64
#define THAT_MOMENT 105

Sprite* glassesSprite;
Sprite* textSprite;
u32 frameCounter = 0;
s16 glassesPosX = 126;
s16 glassesPosY = 1;

void setupBackground() {
	VDP_drawImage(PLAN_B, &bg, 0, 0);
}

void setupSprites() {
	glassesSprite = SPR_addSprite(&glasses, glassesPosX, glassesPosY, TILE_ATTR(PAL1, TRUE, FALSE, FALSE));
	textSprite = SPR_addSprite(&radtext, 114, 150, TILE_ATTR(PAL2, TRUE, FALSE, FALSE));

	// copy in palette from sprite data
	VDP_setPalette(PAL1, glasses.palette->data);
	VDP_setPalette(PAL2, radtext.palette->data);
	
	SPR_update();
}

void updateAnimation() {
	if (frameCounter < THAT_MOMENT) {
		glassesPosY++;
		SPR_setPosition(glassesSprite, glassesPosX, glassesPosY);
	}
	else if (frameCounter == THAT_MOMENT) {
		SPR_setAnimAndFrame(glassesSprite, 1, 2);
	}
	else if (frameCounter == THAT_MOMENT + 15) {
		SPR_setAnim(glassesSprite, 0);
	}
	else if (frameCounter == THAT_MOMENT + 30) {
		SPR_setAnim(textSprite, 1);
	}
	else if (frameCounter == THAT_MOMENT + 65) {
		SPR_setAnim(textSprite, 2);
	}
	
	SPR_update();
}

int main() {
	SPR_init(0, 0, 0);
	// set all palette to black
	VDP_setPaletteColors(0, (u16*)palette_black, 64);

	setupBackground();
	setupSprites();

	XGM_startPlay(xgmmusic);
	XGM_setPCM(RADMARS_VOICE_ID, voice, 37376);
	XGM_setLoopNumber(0);

	while (1) {
		updateAnimation();
		
		if (frameCounter == THAT_MOMENT + 55) {
			XGM_startPlayPCM(RADMARS_VOICE_ID, 0, 1);
		}

		VDP_waitVSync();
		frameCounter++;
	}
	
	return 0;
}

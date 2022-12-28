/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Long Nguyen
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <Ucglib.h>
#include <timer.h>

static ucg_t ucg;

int main(void)
{
	SystemCoreClockUpdate();
	TimerInit();

	Ucglib4WireSWSPI_begin(&ucg, UCG_FONT_MODE_SOLID);
	ucg_ClearScreen(&ucg);

	ucg_SetFont(&ucg, ucg_font_10x20_tf);
	ucg_SetColor(&ucg, 0, 255, 255, 255);
	ucg_SetColor(&ucg, 1, 0, 0, 0);
	ucg_SetRotate180(&ucg);
	ucg_DrawDisc(&ucg, 44, 30, 20, UCG_DRAW_UPPER_LEFT);
	ucg_DrawDisc(&ucg, 44, 30, 20, UCG_DRAW_UPPER_RIGHT);

	ucg_DrawDisc(&ucg, 84, 30, 20, UCG_DRAW_UPPER_LEFT);
	ucg_DrawDisc(&ucg, 84, 30, 20, UCG_DRAW_UPPER_RIGHT);

	ucg_DrawTetragon(&ucg, 24, 29, 104, 29, 64, 70, 64, 70);

	while(1){
		processTimerScheduler();
	}
}

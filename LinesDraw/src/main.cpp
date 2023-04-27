/**
 * Jon Durrant.
 *
 * Badger Test - Clock faces
 */

#include "pico/stdlib.h"
#include <stdio.h>
#include <cstring>
#include <string>
#include <algorithm>
#include "pico/time.h"
#include "pico/platform.h"
#include "hardware/adc.h"

#include "common/pimoroni_common.hpp"
#include "badger2040.hpp"

#include "DrJonEA.h"

#include <math.h>



#define DELAY 1000

using namespace pimoroni;

Badger2040 badger;
const int WIDTH = 296;
const int HEIGHT = 128;


void clock(uint8_t x, uint8_t y, uint8_t handLen, uint8_t hour, uint8_t min){


	float handShort = (float)handLen * 0.75;

	float a = (float)hour/12.0 * 6.28319;
	int x2 = sin(a)*  handShort;
	int y2 = cos(a)* handShort;
	badger.line(x, y, x+x2, y-y2);

	a = (float)min/60.0 * 6.28319;
	x2 = sin(a)* (float) handLen;
	y2 = cos(a)* (float) handLen;
	badger.line(x, y, x+x2, y-y2);

}


uint8_t hour, min = 0;

void displayDashboard(){
	badger.pen(15);
	badger.clear();

	badger.thickness(3);

	badger.pen(0);
    badger.rectangle(WIDTH/2, 0, WIDTH/2, HEIGHT);

    clock(WIDTH/4, HEIGHT/2, HEIGHT/2, hour, min );

    min = (min + 5) % 60;
    if (min == 0){
    	hour = (hour + 1) % 12;
    }
    badger.pen(15);
    clock(WIDTH/4*3, HEIGHT/2, HEIGHT/2, hour, min );


    badger.update();
}



int main() {
	int i = 0;

	stdio_init_all();

	sleep_ms(2000);
	printf("GO\n");

	badger.init();

	badger.image(DrJonEA);

	badger.update();
	while (badger.is_busy()) {
		sleep_ms(10);
	}
	sleep_ms(5000);

	for (;;){
		for ( i = 0; i < 12; i++){

			displayDashboard();
			while (badger.is_busy()) {
				sleep_ms(10);
			}
			sleep_ms(1000);

		}
	}



	badger.halt();

}

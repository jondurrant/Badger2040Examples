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

#include "common/pimoroni_common.hpp"
#include "badger2040.hpp"

#include "DrJonEA.h"

#include <math.h>
#include "DS3231.hpp"


#define DELAY 1000

using namespace pimoroni;

Badger2040 badger;
const int WIDTH = 296;
const int HEIGHT = 128;
DS3231 rtc;


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




void displayDashboard(){
	uint8_t hour, min = 0;
	char buf[5];
	badger.pen(15);
	badger.clear();

	hour = rtc.get_hou();
	min =  rtc.get_min();

	badger.thickness(3);

	badger.pen(0);
    clock(WIDTH/4, HEIGHT/2, HEIGHT/2, hour, min );

    float t = rtc.get_temp_f();
    sprintf(buf,"%.2fC", t);
    badger.thickness(4);
    badger.text(buf, WIDTH/2-2, HEIGHT/4, 1.4f);

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
			sleep_ms(30000);

		}
	}



	badger.halt();

}

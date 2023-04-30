/**
 * Jon Durrant.
 *
 * Badger Test
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



#define DELAY 1000

using namespace pimoroni;

Badger2040 badger;
const int WIDTH = 296;
const int HEIGHT = 128;



void displayDashboard(){
	badger.pen(15);
	badger.clear();

	badger.pen(0);
	badger.thickness(4);

    badger.text("Dr Jon", 0, HEIGHT/4, 2.2f);
    badger.text("Durrant", 0, HEIGHT/4*3, 2.0f);
    badger.update();

}



int main() {
	int i = 0;

	stdio_init_all();

	sleep_ms(2000);
	printf("GO\n");

	badger.init();

	for (;;){
		for ( i = 0; i < 12; i++){
			badger.image(DrJonEA);

			badger.update();
			while (badger.is_busy()) {
				sleep_ms(10);
			}
			sleep_ms(5000);

			displayDashboard();
			while (badger.is_busy()) {
				sleep_ms(10);
			}
			sleep_ms(5000);

		}
	}



	badger.halt();

}

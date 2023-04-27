/**
 * Jon Durrant.
 *
 * Badger Slide Show
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

#include "slides.h"

#define DELAY 5000
#define SLIDES 3

using namespace pimoroni;

Badger2040 badger;


const uint8_t * images[]= {
	Slide1,
	Slide2,
	Slide3
};


int main() {
	int i = 0;

	stdio_init_all();

	sleep_ms(2000);
	printf("GO\n");

	badger.init();

	for (;;){
		for ( i = 0; i < SLIDES; i++){
			badger.led(0xFF);
			badger.image(images[i]);

			badger.update();
			while (badger.is_busy()) {
				sleep_ms(10);
			}
			badger.led(0);
			sleep_ms(DELAY);
		}
	}



	badger.halt();

}

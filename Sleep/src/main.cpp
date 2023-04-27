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
#include "hardware/adc.h"

#include "common/pimoroni_common.hpp"
#include "badger2040.hpp"



#define DELAY 1000

using namespace pimoroni;

Badger2040 badger;
const int WIDTH = 296;
const int HEIGHT = 128;





int main() {
	int i = 0;
	int x = WIDTH/2;
	int y = HEIGHT/2;
	char buf[10];

	badger.init();

	if(badger.pressed_to_wake(badger.UP)) {
		sprintf(buf, "Up");
		x= WIDTH/8*3;
	} else if(badger.pressed_to_wake(badger.DOWN)) {
		sprintf(buf, "Down");
		x= WIDTH/8*2;
	} else if(badger.pressed_to_wake(badger.A)) {
		sprintf(buf, "Left");
		x = 10;;
	} else if(badger.pressed_to_wake(badger.C)) {
		sprintf(buf, "Right");
		x= WIDTH/2;
	} else if(badger.pressed_to_wake(badger.B)) {
		sprintf(buf, "Middle");
		x= WIDTH/8*2;
	} else {
		sprintf(buf, "Reset");
		x= WIDTH/8*2;
	}

	badger.pen(15);
	badger.clear();

	badger.pen(0);
	badger.thickness(4);

	badger.text(buf, x, y , 2.2f);
	badger.update();


	while (badger.is_busy()) {
		sleep_ms(10);
	}

	sleep_ms(8000);


	badger.halt();

}

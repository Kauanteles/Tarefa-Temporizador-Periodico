#include <stdio.h>
#include "pico/stdlib.h"

#define PIN_RED 11
#define PIN_YELLOW 12
#define PIN_GREEN 13

int estado = 0;
bool led_ligado = false;

void desliga_leds() {
    gpio_put(PIN_RED, false);
    gpio_put(PIN_YELLOW, false);
    gpio_put(PIN_GREEN, false);
}

bool repeating_timer_callback(struct repeating_timer *t) {
    desliga_leds();

    switch(estado) {
        case 0:
            gpio_put(PIN_RED, true);
            estado = 1;
            break;
        case 1:
            gpio_put(PIN_YELLOW, true);
            estado = 2;
            break;
        case 2:
            gpio_put(PIN_GREEN, true);
            estado = 0;
            break;
    }

    return true;
}

int main() {
    stdio_init_all();
    
    gpio_init(PIN_RED);
    gpio_set_dir(PIN_RED, GPIO_OUT);

    gpio_init(PIN_YELLOW);
    gpio_set_dir(PIN_YELLOW, GPIO_OUT);

    gpio_init(PIN_GREEN);
    gpio_set_dir(PIN_GREEN, GPIO_OUT);

    struct repeating_timer timer;

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while(true) {
        printf("estado atual: %d\n", estado);
        sleep_ms(1000);
    }

    return 0;
}

#include "pico/stdlib.h"

void printDecimalToLEDs(int DECIMAL_NUMBER) {
    int c, k;
    int binary[8] = {0};
    int position = 0;

    for (c = 7; c >= 0; c--)
    {
        k = DECIMAL_NUMBER >> c;

        if (k & 1) {
            binary[position] = 1;
        }
            
        else {
            binary[position] = 0;
        }
        position++;
    }

    for (int i = 0; i <= 7; i++) {
        if (binary[i] == 0) {
            gpio_put(i, 0);
        }
        if (binary[i] == 1) {
            gpio_put(i, 1);
        }
    }
}

int main() {
    int DECIMAL_NUMBER = 0;
    gpio_init(0);
    gpio_init(1);
    gpio_init(2);
    gpio_init(3);
    gpio_init(4);
    gpio_init(5);
    gpio_init(6);
    gpio_init(7);
    gpio_set_dir(0, GPIO_OUT);
    gpio_set_dir(1, GPIO_OUT);
    gpio_set_dir(2, GPIO_OUT);
    gpio_set_dir(3, GPIO_OUT);
    gpio_set_dir(4, GPIO_OUT);
    gpio_set_dir(5, GPIO_OUT);
    gpio_set_dir(6, GPIO_OUT);
    gpio_set_dir(7, GPIO_OUT);
    while (1) {
        if (DECIMAL_NUMBER == 256) {
            DECIMAL_NUMBER = 0;
        }
        printDecimalToLEDs(DECIMAL_NUMBER);
        sleep_ms(150);
        DECIMAL_NUMBER++;
    }
}
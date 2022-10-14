//
// Created by Thomas Spycher on 25.08.22.
//

#include "sound.h"
#include <Arduino.h>

void Sound::play_welcome() {

    tone(piezo_pin, NOTE_E3);
    delay(DELAY_FAST * DELAY_FACTOR);
    tone(piezo_pin, NOTE_F3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(piezo_pin, NOTE_G3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(piezo_pin, NOTE_C4);
    delay(DELAY_LONG * DELAY_FACTOR);

    tone(piezo_pin, NOTE_D3);
    delay(DELAY_FAST * DELAY_FACTOR);
    tone(piezo_pin, NOTE_E3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(piezo_pin, NOTE_F3);
    delay(DELAY_LONG2 * DELAY_FACTOR);

    tone(piezo_pin, NOTE_G3);
    delay(DELAY_FAST * DELAY_FACTOR);
    tone(piezo_pin, NOTE_A3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(piezo_pin, NOTE_B3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(piezo_pin, NOTE_F4);
    delay(DELAY_LONG * DELAY_FACTOR);

    tone(piezo_pin, NOTE_A3);
    delay(DELAY_FAST * DELAY_FACTOR);
    tone(piezo_pin, NOTE_B3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(piezo_pin, NOTE_C4);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(piezo_pin, NOTE_D4);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(piezo_pin, NOTE_E4);
    delay(DELAY_NORMAL * DELAY_FACTOR);

    noTone(piezo_pin);
}

void Sound::play_page_switch() {
    tone(piezo_pin, NOTE_E3);
    delay(DELAY_FAST * DELAY_FACTOR);
    tone(piezo_pin, NOTE_F3);

    noTone(piezo_pin);
}
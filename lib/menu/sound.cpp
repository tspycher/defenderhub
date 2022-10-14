//
// Created by Thomas Spycher on 25.08.22.
//

#include "sound.h"
#include <Arduino.h>

void Sound::play_welcome() {

    tone(PIEZO_PIN, NOTE_E3);
    delay(DELAY_FAST * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_F3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_G3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_C4);
    delay(DELAY_LONG * DELAY_FACTOR);

    tone(PIEZO_PIN, NOTE_D3);
    delay(DELAY_FAST * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_E3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_F3);
    delay(DELAY_LONG2 * DELAY_FACTOR);

    tone(PIEZO_PIN, NOTE_G3);
    delay(DELAY_FAST * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_A3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_B3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_F4);
    delay(DELAY_LONG * DELAY_FACTOR);

    tone(PIEZO_PIN, NOTE_A3);
    delay(DELAY_FAST * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_B3);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_C4);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_D4);
    delay(DELAY_NORMAL * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_E4);
    delay(DELAY_NORMAL * DELAY_FACTOR);

    noTone(PIEZO_PIN);
}

void Sound::play_page_switch() {
    tone(PIEZO_PIN, NOTE_E3);
    delay(DELAY_FAST * DELAY_FACTOR);
    tone(PIEZO_PIN, NOTE_F3);

    noTone(PIEZO_PIN);

}
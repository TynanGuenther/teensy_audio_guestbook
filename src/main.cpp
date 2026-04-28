#include <Arduino.h>
#include "HookSwitch.h"
#include "DialReader.h"
#include "CommandHandler.h"
#include "AudioManager.h"

constexpr uint8_t PIN_HOOK  = 2;
constexpr uint8_t PIN_DIAL  = 3;

AudioManager    audio;
CommandHandler  commands(audio);

void onPickup()            { audio.startRecording(); }
void onHangup()            { audio.stopRecording();  commands.reset(); }
void onDigit(uint8_t d)    { commands.onDigit(d); }

HookSwitch hook(PIN_HOOK, onPickup, onHangup);
DialReader dial(PIN_DIAL, onDigit);

void setup() {
    Serial.begin(115200);
    delay(500);
    Serial.println("=== Audio Guestbook v0.1 ===");

    audio.begin();
    hook.begin();
    dial.begin();
}

void loop() {
    hook.update();
    dial.update();
}

#include "CommandHandler.h"
#include "AudioManager.h"

CommandHandler::CommandHandler(AudioManager& audio)
    : _audio(audio) {}

void CommandHandler::onDigit(uint8_t digit) {
    Serial.print("[CMD] Digit received: ");
    Serial.println(digit);
    dispatch(digit);
}

void CommandHandler::reset() {
    // Reserved for multi-digit command sequences later
}

void CommandHandler::dispatch(uint8_t digit) {
    switch (digit) {
        case 1:
            Serial.println("[CMD] Play last recording");
            _audio.playLast();
            break;
        case 2:
            Serial.println("[CMD] Play all recordings");
            _audio.playAll();
            break;
        case 3:
            Serial.println("[CMD] Delete last recording");
            _audio.deleteLast();
            break;
        case 5:
            Serial.println("[CMD] Play greeting");
            _audio.playGreeting();
            break;
        case 9:
            Serial.println("[CMD] Toggle recording");
            _audio.toggleRecording();
            break;
        case 0:
            Serial.println("[CMD] Play help");
            _audio.playHelp();
            break;
        default:
            Serial.print("[CMD] Unbound digit: ");
            Serial.println(digit);
            break;
    }
}

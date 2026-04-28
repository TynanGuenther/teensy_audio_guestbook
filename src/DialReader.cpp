#include "DialReader.h"

DialReader::DialReader(uint8_t pin, DigitCallback onDigit)
    : _pin(pin), _onDigit(onDigit) {}

void DialReader::begin() {
    pinMode(_pin, INPUT_PULLUP);
    _lastPulseState = digitalRead(_pin);
}

void DialReader::update() {
    bool current = digitalRead(_pin);
    uint32_t now = millis();

    // Detect falling edge (pulse start) with debounce
    if (_lastPulseState == HIGH && current == LOW) {
        if ((now - _lastPulseTime) > DEBOUNCE_MS) {
            _pulseCount++;
            _dialActive    = true;
            _lastPulseTime = now;
        }
    }

    _lastPulseState = current;

    if (_dialActive && (now - _lastPulseTime) >= INTER_DIGIT_MS) {
        _dialActive = false;

        if (_pulseCount > 0 && _pulseCount <= 10) {
            uint8_t digit = (_pulseCount == 10) ? 0 : _pulseCount;
            if (_onDigit) _onDigit(digit);
        }

        _pulseCount = 0;
    }
}

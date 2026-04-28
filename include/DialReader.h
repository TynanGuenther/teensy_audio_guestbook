#pragma once
#include <Arduino.h>

using DigitCallback = void (*)(uint8_t digit);

class DialReader {
public:
    // pin           - GPIO pin connected to dial pulse wire
    // onDigit       - called with the decoded digit (1-9, 0) when a dial completes
    DialReader(uint8_t pin, DigitCallback onDigit);

    void begin();
    void update();  // call every loop iteration

private:
    uint8_t       _pin;
    DigitCallback _onDigit;

    // Pulse counting state
    uint8_t  _pulseCount     = 0;
    bool     _lastPulseState = true;   // HIGH at rest (INPUT_PULLUP)
    uint32_t _lastPulseTime  = 0;
    bool     _dialActive     = false;

    // Timing constants (ms) — tuned for standard rotary phone mechanics
    static constexpr uint32_t DEBOUNCE_MS     = 5;    // pulse debounce
    static constexpr uint32_t INTER_DIGIT_MS  = 300;  // gap = digit complete
    static constexpr uint32_t MIN_PULSE_MS    = 20;   // ignore noise spikes
};

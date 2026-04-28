#include "HookSwitch.h"

HookSwitch::HookSwitch(uint8_t pin, HookCallback onPickup, HookCallback onHangup)
    : _pin(pin), _onPickup(onPickup), _onHangup(onHangup) {}

void HookSwitch::begin() {
    pinMode(_pin, INPUT_PULLUP);
    // Read initial state so we don't run an event on boot
    _lastRaw  = digitalRead(_pin);
    _offHook  = !_lastRaw;  // LOW = off hook with pull-up
}

void HookSwitch::update() {
    bool raw = digitalRead(_pin);

    // Only start the debounce timer when the raw signal changes
    if (raw != _lastRaw) {
        _lastRaw        = raw;
        _lastChangeTime = millis();
    }

    if ((millis() - _lastChangeTime) >= DEBOUNCE_MS) {
        bool stable = !raw;  // LOW = off hook (INPUT_PULLUP logic)

        if (stable != _offHook) {
            _offHook = stable;
            if (_offHook) {
                if (_onPickup) _onPickup();
            } else {
                if (_onHangup) _onHangup();
            }
        }
    }
}

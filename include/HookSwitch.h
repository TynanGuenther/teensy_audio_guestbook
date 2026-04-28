#pragma once
#include <Arduino.h>

// Callback types for hook events
using HookCallback = void (*)();

class HookSwitch {
public:
    // pin        - GPIO pin connected to hook switch
    // onPickup   - called once when handset is lifted
    // onHangup   - called once when handset is replaced
    HookSwitch(uint8_t pin, HookCallback onPickup, HookCallback onHangup);

    void begin();
    void update();  // call every loop iteration

    bool isOffHook() const { return _offHook; }

private:
    uint8_t      _pin;
    HookCallback _onPickup;
    HookCallback _onHangup;
    bool         _offHook        = false;
    bool         _lastRaw        = false;
    uint32_t     _lastChangeTime = 0;

    // Debounce threshold in ms — hook switches are mechanical and noisy
    static constexpr uint32_t DEBOUNCE_MS = 50;
};

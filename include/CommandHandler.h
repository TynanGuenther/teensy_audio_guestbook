#pragma once
#include <Arduino.h>

// Forward declare so CommandHandler doesn't need to know AudioManager internals yet
class AudioManager;

class CommandHandler {
public:
    explicit CommandHandler(AudioManager& audio);

    // Feed a decoded digit into the command buffer
    void onDigit(uint8_t digit);

    // Call on hangup to clear any pending command state
    void reset();

private:
    AudioManager& _audio;

    void dispatch(uint8_t digit);
};

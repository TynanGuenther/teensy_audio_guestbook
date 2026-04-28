#pragma once
#include <Arduino.h>

class AudioManager {
public:
    void begin();

    void startRecording();
    void stopRecording();
    void toggleRecording();

    void playLast();
    void playAll();
    void playGreeting();
    void playHelp();
    void deleteLast();

    bool isRecording() const { return _recording; }

private:
    bool _recording = false;
};

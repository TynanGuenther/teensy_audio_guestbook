#include "AudioManager.h"

void AudioManager::begin() {
    Serial.println("[AUDIO] AudioManager initialized (stub)");
}

void AudioManager::startRecording() {
    _recording = true;
    Serial.println("[AUDIO] Recording started");
}

void AudioManager::stopRecording() {
    _recording = false;
    Serial.println("[AUDIO] Recording stopped");
}

void AudioManager::toggleRecording() {
    _recording ? stopRecording() : startRecording();
}

void AudioManager::playLast()     { Serial.println("[AUDIO] Playing last"); }
void AudioManager::playAll()      { Serial.println("[AUDIO] Playing all"); }
void AudioManager::playGreeting() { Serial.println("[AUDIO] Playing greeting"); }
void AudioManager::playHelp()     { Serial.println("[AUDIO] Playing help"); }
void AudioManager::deleteLast()   { Serial.println("[AUDIO] Deleting last"); }

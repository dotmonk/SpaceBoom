#include "AudioEngine.h"
#include "Renderer.h"
#include <cstring>

Sound::Sound(const std::string& filename, ma_engine* engine)
   : engine(engine) {
   ma_result result = ma_sound_init_from_file(engine, filename.c_str(), MA_SOUND_FLAG_STREAM, NULL, NULL, &sound);
   if (result != MA_SUCCESS) {
      std::cout << "Failed to load sound - " << result << std::endl;
   }
}

Sound::Sound(Sound&& other) noexcept
   : engine(other.engine)
   , sound(other.sound) {
   other.engine = nullptr;
   std::memset(&other.sound, 0, sizeof(ma_sound));
}

Sound& Sound::operator=(Sound&& other) noexcept {
   if (this != &other) {
      if (engine != nullptr) {
         ma_sound_uninit(&sound);
      }
      engine       = other.engine;
      sound        = other.sound;
      other.engine = nullptr;
      std::memset(&other.sound, 0, sizeof(ma_sound));
   }
   return *this;
}

void Sound::play() {
   if (engine != nullptr) {
      ma_sound_start(&sound);
   }
}

Sound::~Sound() {
   if (engine != nullptr) {
      ma_sound_uninit(&sound);
   }
}


AudioEngine::AudioEngine()
   : Walk(getSound("walk1.wav")), 
    /*result =
     ma_sound_init_from_file(&engine, (Renderer::ResPath() + "Sounds/" + "walk1.wav").c_str(), 0, NULL, NULL, &sound);
     ma_sound_start(&sound);*/
    Walk1(getSound("walk2.wav")), 
    Bomb_Sound(getSound("Bomb1.wav")),
    Death_Sound(getSound("Death2.wav"))
     {
}

Sound AudioEngine::getSound(const std::string& name) {
   return Sound(Renderer::ResPath() + "Sounds/" + name, &engine.engine);
}

void AudioEngine::play(Sound& sound) {
   sound.play();
}

AudioEngine& audio() {
   static AudioEngine audioEngine = AudioEngine(); // Initialized first time this function is called
   return audioEngine;
}

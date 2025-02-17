#pragma once
#include "Character.h"

class Player : public Character {
public:
   Player() = default;
   Player(const std::string& name, int x, int y);
   virtual void update() override;
   bool         moved_last_tick = false;
   virtual void tickUpdate() override;
   bool         key_pressed_last_frame = false;
   virtual void move(int new_x, int new_y) override;
   bool         second_step = false;

   // Powerups
   int playerBunnyHopCoolDown = 5;
};

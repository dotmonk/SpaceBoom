#pragma once
#include "SquareObject.h"
#include "Input.h"

class Tile : public SquareObject {
public:
   Tile() = default;
   Tile(const std::string& name, bool wall, bool unbreakable, float x, float y);
   Tile(const std::string& name, float x, float y);
   virtual void update() override;
   virtual void explode();
   bool         wall;
   bool         unbreakable = false;
};

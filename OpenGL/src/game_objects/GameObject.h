#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <optional>
#include <memory>

#include "../Renderer.h"
#include "../VertexBuffer.h"
#include "../VertexBufferLayout.h"
#include "../IndexBuffer.h"
#include "../VertexArray.h"
#include "../Shader.h"

class GameObject {
public:
   GameObject(const std::string& name, int drawPriority, float x, float y);
   GameObject()                           = default;
   GameObject(GameObject&& mE)            = default;
   GameObject& operator=(GameObject&& mE) = default;


   virtual ~GameObject() = default;
   float CreationTime    = (float)glfwGetTime();
   bool  ShouldDestroy   = false;

   virtual void setUpShader(Renderer& renderer);
   virtual void render(Renderer& renderer);
   virtual void update();
   virtual void tickUpdate();


   std::shared_ptr<Shader>       shader;
   std::shared_ptr<VertexArray>  va;
   std::shared_ptr<VertexBuffer> vb;
   std::shared_ptr<IndexBuffer>  ib;

   std::string name;
   int         drawPriority;
   float       x;
   float       y;

private:
   // Add any private members here if needed
};

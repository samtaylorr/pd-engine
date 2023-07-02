#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Component.h"
#include <glm/ext.hpp>
#include <glad/glad.h>
#include <string>
#include <vector>

class GameObject {
public:
  GameObject();
  GameObject(GameObject &&) = default;
  GameObject(const GameObject &) = default;
  GameObject &operator=(GameObject &&) = default;
  GameObject &operator=(const GameObject &) = default;
  ~GameObject();
  void AddComponent(Component c);

private:
  std::vector components;
};

#endif

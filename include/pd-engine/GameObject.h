#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/ext.hpp>
#include <glad/glad.h>
#include <string>
#include <vector>
#include "Component.h"

class GameObject {
public:
  GameObject();
  GameObject(GameObject &&) = default;
  GameObject(const GameObject &) = default;
  GameObject &operator=(GameObject &&) = default;
  GameObject &operator=(const GameObject &) = default;
  ~GameObject();
  void AddComponent(Component *c);
  std::string ListComponents();
private:
  std::vector<Component*> components;
};

#endif

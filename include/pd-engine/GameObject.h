#pragma once

#include <string>
#include <vector>
#include "Component.h"

class GameObject {
public:
  GameObject(){};
  GameObject(GameObject &&) = default;
  GameObject(const GameObject &) = default;
  GameObject &operator=(GameObject &&) = default;
  GameObject &operator=(const GameObject &) = default;
  ~GameObject();
  void AddComponent(Component *c);
  std::string ListComponents();
  void Awake();
  void Update();
private:
  std::vector<Component*> components;
};

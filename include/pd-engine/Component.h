#pragma once

#include <iostream>
#include <string>
#include "Transform.h"

class GameObject;

class Component {
public:
  Component(){};
  Component(Component &&) = default;
  Component(const Component &) = default;
  Component &operator=(Component &&) = default;
  Component &operator=(const Component &) = default;
  ~Component(){};
  virtual void Awake(){};
  virtual void Update(){};
  void Attach(GameObject* g, Transform* t);
  GameObject* gameObject;
  Transform* transform;
};


#pragma once

#include <iostream>
#include <string>

class Component {
public:
  Component(){};
  Component(Component &&) = default;
  Component(const Component &) = default;
  Component &operator=(Component &&) = default;
  Component &operator=(const Component &) = default;
  ~Component();
  void Awake(){};
  void Update(){};
};


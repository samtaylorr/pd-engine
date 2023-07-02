#pragma once

#include <iostream>
#include <string>

class Component {
public:
  Component(std::string name);
  Component(Component &&) = default;
  Component(const Component &) = default;
  Component &operator=(Component &&) = default;
  Component &operator=(const Component &) = default;
  ~Component();
  std::string getName();
  void Awake(){};
  void Update(){};

private:
  std::string name;
};


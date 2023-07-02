#ifndef COMPONENT_H
#define GAMEOBJECT_H

#include <glm/ext.hpp>
#include <glad/glad.h>
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
  void run();
  std::string getName();

private:
  std::string name;
};

#endif

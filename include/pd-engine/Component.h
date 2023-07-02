#ifndef COMPONENT_H
#define GAMEOBJECT_H

#include <glm/ext.hpp>
#include <glad/glad.h>


class Component {
public:
  Component();
  Component(Component &&) = default;
  Component(const Component &) = default;
  Component &operator=(Component &&) = default;
  Component &operator=(const Component &) = default;
  ~Component();
  void run();

private:
  
};

Component::Component() {
}

Component::~Component() {
}

#endif

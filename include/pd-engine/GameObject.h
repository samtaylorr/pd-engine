#pragma once

#include <string>
#include <vector>
#include "components/Transform.h"

class GameObject {
public:
	Transform* transform = new Transform(glm::vec3(0.0f, 0.0f, 0.0f));

  GameObject(glm::vec3 position);
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

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "GameObject.h"
#include "Debug.h"

class Level {
public:
  Level(){};
  Level(Level &&) = default;
  Level(const Level &) = default;
  Level &operator=(Level &&) = default;
  Level &operator=(const Level &) = default;
  ~Level();
  void AddGameObject(GameObject* go);
  std::vector<GameObject*> GameObjects();
  void Awake();
  void Update();
  void Clear();
  glm::mat4 view = glm::mat4(1.0f);
  glm::mat4 projection = glm::mat4(1.0f);
  void SetCamera(glm::mat4 view, glm::mat4 projection);

private:
  std::vector<GameObject*> gameObjects;
};

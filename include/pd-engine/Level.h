#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "GameObject.h"

class Level {
public:
  Level();
  Level(Level &&) = default;
  Level(const Level &) = default;
  Level &operator=(Level &&) = default;
  Level &operator=(const Level &) = default;
  ~Level();
  void AddGameObject(GameObject* go);
  std::vector<GameObject*> GameObjects();

private:
  std::vector<GameObject*> gameObjects;
};

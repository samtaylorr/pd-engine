#include "pd-engine/Level.h"

Level::Level(){
  std::cout << "Building level" << std::endl;
}

void Level::AddGameObject(GameObject* go){
  gameObjects.push_back(go);
}

std::vector<GameObject*> Level::GameObjects(){
  return gameObjects;
}

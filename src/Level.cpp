#include "pd-engine/Level.h"

void Level::AddGameObject(GameObject* go){
  gameObjects.push_back(go);
}

std::vector<GameObject*> Level::GameObjects(){
  return gameObjects;
}

void Level::Awake(){
  for(GameObject* gameObject : gameObjects){
    gameObject->Awake();
  }
}

void Level::Update(){
  for(GameObject* gameObject : gameObjects){
    gameObject->Update();
  }
}



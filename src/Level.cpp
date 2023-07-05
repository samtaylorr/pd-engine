
#include "pd-engine/Level.h"

void Level::AddGameObject(GameObject* go){
  go->level = this;
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

void Level::Clear(){
  GLCall ( glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ); // also clear the depth buffer now! 
  GLCall( glClearColor(0.2f, 0.3f, 0.3, 1.0f) );
}

void Level::SetCamera(glm::mat4 view, glm::mat4 projection){
  this->view = view;
  this->projection = projection;
}

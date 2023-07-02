#include "pd-engine/GameObject.h"
#include <iostream>

GameObject::GameObject(glm::vec3 position){
  transform->position = position;
}

void GameObject::AddComponent(Component *c){
  components.push_back(c);
}

std::string GameObject::ListComponents(){
  std::string list = "";
  for(Component* c : components){
    list += "Added Component\n";
  }

  return list;
}

void GameObject::Awake(){
  for(Component* c : components){
    c->Awake();
  }
}

void GameObject::Update(){
  for(Component* c : components){
    c->Update();
  }
}

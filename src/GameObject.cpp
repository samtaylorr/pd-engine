#include "pd-engine/GameObject.h"
#include <iostream>

void GameObject::AddComponent(Component *c){
  components.push_back(c);
}

std::string GameObject::ListComponents(){
  std::string list = "";
  for(Component* c : components){
    list += "Component: " + c->getName() + "\n";
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

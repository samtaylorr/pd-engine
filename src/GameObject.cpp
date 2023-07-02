#include "pd-engine/GameObject.h"
#include <iostream>

GameObject::GameObject(){
  std::cout << "Creating GameObject";
}

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

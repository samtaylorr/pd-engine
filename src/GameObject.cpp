#include "pd-engine/GameObject.h"
#include "pd-engine/Level.h"
#include <iostream>

GameObject::GameObject(glm::vec3 position){
  transform->position = position;
}

void GameObject::AddComponent(Component *c){
  c->Attach(this, this->transform);  
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
  // Add default components here
  MeshFilter* filter = new MeshFilter(Cube);
  this->AddComponent(filter);
  MeshRenderer *mesh = new MeshRenderer(filter->getVerts().data(), filter->getIndices().data(), filter->getVerts().size() * sizeof(float), 36);
  this->AddComponent(mesh); 
  this->renderer = mesh;

  for(Component* c : components){
    c->Awake();
  }
}

void GameObject::Update(){
  for(Component* c : components){
    c->Update();
  }
}

void GameObject::Draw(){
  renderer->Draw(level->view, level->projection);
}

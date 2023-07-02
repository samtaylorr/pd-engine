#include "pd-engine/Component.h"

Component::Component(std::string name){
  this->name = name;
}

std::string Component::getName(){
  return this->name;
}

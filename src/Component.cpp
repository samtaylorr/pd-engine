#include "pd-engine/Component.h"

void Component::Attach(GameObject* g, Transform* t){
  this->gameObject = g;
  this->transform  = t;
};

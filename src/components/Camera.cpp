#include "pd-engine/components/Camera.h"
#include "pd-engine/Level.h"
#include <iostream>

Camera::Camera(){}

void Camera::Awake(){
  this->view = glm::mat4(1.0f);
  this->projection = glm::mat4(1.0f);

  view = glm::lookAt(
    this->transform->position,
    this->transform->position + -Transform::forward,
    Transform::up
  );

  projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

  this->gameObject->level->SetCamera(view, projection);
};

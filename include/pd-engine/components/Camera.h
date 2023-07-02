#pragma once
#include "pd-engine/Component.h"

class Camera : public Component {
public:
  Camera();
  Camera(Camera &&) = default;
  Camera(const Camera &) = default;
  Camera &operator=(Camera &&) = default;
  Camera &operator=(const Camera &) = default;
  ~Camera();

private:
  
};

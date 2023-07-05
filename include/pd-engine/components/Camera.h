#include "pd-engine/Component.h"

class Level;

class Camera : public Component {
public:
  Camera();
  void Awake();

private:
  glm::mat4 view, projection;
}; 

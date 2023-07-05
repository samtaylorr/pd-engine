#include "glm/ext.hpp"

class Transform {

public:
	Transform(glm::vec3 position);
	glm::vec3 position;
  static constexpr glm::vec3 forward = glm::vec3(0.0f, 0.0f, 1.0f);
  static constexpr glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);


};

#include "pd-engine/Component.h"
#include "glm/ext.hpp"

class Transform : public Component {

public:
	Transform(glm::vec3 position);
	glm::vec3 position;
};

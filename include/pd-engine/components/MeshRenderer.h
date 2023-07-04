#include "pd-engine/Component.h"
#include "pd-engine/Renderer.h"
#include "pd-engine/Texture.h"

class MeshRenderer : public Component {

public:
  MeshRenderer(float positions[], unsigned int indices[], unsigned int vertexCount, unsigned int indicesCount);
  void Draw(glm::mat4 view, glm::mat4 projection);
  void AttachTransform(Transform* t);

private:
  Transform* transform;
  const Texture texture1;
  const Texture texture2;
  Shader shader;
  const VertexArray  va;
  const VertexBuffer vb;
  const IndexBuffer  ib;
  Renderer* r;
};

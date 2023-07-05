#include "pd-engine/Component.h"
#include "pd-engine/Texture.h"
#include "pd-engine/Debug.h"
#include "pd-engine/Shader.h"
#include "pd-engine/VertexArray.h"
#include "pd-engine/VertexBuffer.h"
#include "pd-engine/IndexBuffer.h"

class MeshRenderer : public Component {

public:
  MeshRenderer(float positions[], unsigned int indices[], unsigned int vertexCount, unsigned int indicesCount);
  void Draw(glm::mat4 view, glm::mat4 projection);
  
private:
  const Texture texture1;
  const Texture texture2;
  Shader shader;
  const VertexArray  va;
  const VertexBuffer vb;
  const IndexBuffer  ib;
};

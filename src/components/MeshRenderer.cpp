#include "pd-engine/components/MeshRenderer.h"

MeshRenderer::MeshRenderer(float positions[], unsigned int indices[], unsigned int vertexCount, unsigned int indicesCount) : vb(positions, vertexCount) , ib(indices, 36), texture1("resources/container.jpg"), texture2("resources/awesomeface.png"), shader("shaders/example/Basic.shader") {
        VertexBufferLayout layout;
        layout.AddFloat(3);
        layout.AddFloat(2);
        
        va.AddBuffer(vb, layout);
        shader.Bind();

				shader.SetUniform1i("texture1", 0);
				shader.SetUniform1i("texture2", 1);
        
}

void MeshRenderer::Draw(glm::mat4 view, glm::mat4 projection){ 
  shader.Bind();	
  glm::mat4 model = glm::mat4(1.0f);
  model = glm::translate(model, this->transform->position);
  shader.SetUniformMat4f("view", view);
  shader.SetUniformMat4f("projection", projection);
  shader.SetUniformMat4f("model", model);
  texture1.Bind(0);
  texture2.Bind(1);
  va.Bind();
  ib.Bind();
  GLCall( glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr) );
}

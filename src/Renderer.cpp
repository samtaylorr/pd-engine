#include "pd-engine/Renderer.h"
#include <iostream>

void Renderer::Clear() const
{
        GLCall( glClear( GL_COLOR_BUFFER_BIT ) );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now! 
}

void Renderer::Draw(Level* level, const VertexArray& va, const IndexBuffer& ib, Shader& shader) const
{
        shader.Bind();
				for(GameObject* g : level->GameObjects()){
					glm::mat4 model = glm::mat4(1.0f);
					model = glm::translate(model, g->transform->position);
					shader.SetUniformMat4f("model", model);
					va.Bind();
        	ib.Bind();
        	GLCall( glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr) );
			};
}

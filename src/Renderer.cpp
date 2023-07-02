#include "pd-engine/Renderer.h"
#include <iostream>

void Renderer::Clear() const
{
        GLCall( glClear( GL_COLOR_BUFFER_BIT ) );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now! 
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
        shader.Bind();
        va.Bind();
        ib.Bind();
        GLCall( glDrawArrays(GL_TRIANGLES, 0, 36) );
}


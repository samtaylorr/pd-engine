#pragma once

#include "IndexBuffer.h"
#include "Shader.h"
#include "Level.h"
#include "VertexArray.h"

class Renderer
{
    public:
        void Clear() const;
        void Draw(Level* level, const VertexArray& va, const IndexBuffer& ib, Shader& shader) const;
};

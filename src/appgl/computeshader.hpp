/*
   Copyright 2022 Alexandre Pires (c.alexandre.pires@gmail.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#pragma once
#include "builtins.hpp"

namespace mgl
{
  class ComputeShader
  {
public:
    ~ComputeShader() = default;

    void release();
    bool released();

    const mgl_core::Ref<Uniform> uniform(const mgl_core::String& name) const;
    const mgl_core::Ref<UniformBlock> uniform_block(const mgl_core::String& name) const;

    const mgl_core::StringList uniforms();
    const mgl_core::StringList uniform_blocks();

    size_t num_uniforms();
    size_t num_uniform_blocks();

    void run(int x, int y, int z);

    const mgl_core::Ref<Uniform> operator[](const mgl_core::String& name) const;

private:
    friend class Context;
    ComputeShader() = default;

    Context* m_context;
    int m_program_obj;
    int m_shader_obj;
    UniformsMap m_uniforms_map;
    UniformBlocksMap m_uniform_blocks_map;
    bool m_released;
  };

  inline const mgl_core::Ref<Uniform> ComputeShader::uniform(const mgl_core::String& name) const
  {
    if(m_uniforms_map.find(name) == m_uniforms_map.end())
    {
      return nullptr;
    }
    return m_uniforms_map.at(name);
  }

  inline const mgl_core::Ref<UniformBlock> ComputeShader::uniform_block(const mgl_core::String& name) const
  {
    if(m_uniform_blocks_map.find(name) == m_uniform_blocks_map.end())
    {
      return nullptr;
    }
    return m_uniform_blocks_map.at(name);
  }

  inline size_t ComputeShader::num_uniforms()
  {
    return m_uniforms_map.size();
  }

  inline size_t ComputeShader::num_uniform_blocks()
  {
    return m_uniform_blocks_map.size();
  }

  inline const mgl_core::Ref<Uniform> ComputeShader::operator[](const mgl_core::String& name) const
  {
    return uniform(name);
  }

  inline bool ComputeShader::released()
  {
    return m_released;
  }

} // namespace mgl
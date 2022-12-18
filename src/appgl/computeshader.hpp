/*
   Copyright 2020 Alexandre Pires (c.alexandre.pires@gmail.com)

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
#include "appgl.hpp"

namespace AppGL
{
  class ComputeShader
  {
public:
    ~ComputeShader() { release(); }

    const Context* context() const;
    void release();
    void run(int x, int y, int z);
    const AppCore::Ref<Uniform> uniform(const AppCore::String& name) const;
    const AppCore::Ref<UniformBlock> uniform_block(const AppCore::String& name) const;

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

  inline const Context* ComputeShader::context() const
  {
    return m_context;
  }

  inline const AppCore::Ref<Uniform> ComputeShader::uniform(const AppCore::String& name) const
  {
    return m_uniforms_map.at(name);
  }

  inline const AppCore::Ref<UniformBlock> ComputeShader::uniform_block(const AppCore::String& name) const
  {
    return m_uniform_blocks_map.at(name);
  }

} // namespace AppGL
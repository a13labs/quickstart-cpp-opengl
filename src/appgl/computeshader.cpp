
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
#include "computeshader.hpp"
#include "appcore/log.hpp"
#include "context.hpp"

namespace mgl
{
  void ComputeShader::release()
  {
    MGL_CORE_ASSERT(m_context, "No context");
    MGL_CORE_ASSERT(!m_context->released(), "Context already released");
    const GLMethods& gl = m_context->gl();

    if(m_released)
      return;

    m_released = true;

    gl.DeleteShader(m_shader_obj);
    gl.DeleteProgram(m_program_obj);
  }

  void ComputeShader::run(int x, int y, int z)
  {
    MGL_CORE_ASSERT(!m_released, "Compute Shader already released");
    MGL_CORE_ASSERT(m_context, "No context");
    MGL_CORE_ASSERT(!m_context->released(), "Context already released");
    const GLMethods& gl = m_context->gl();

    gl.UseProgram(m_program_obj);
    gl.DispatchCompute(x, y, z);
  }

  const mgl_core::StringList ComputeShader::uniforms()
  {
    auto result = mgl_core::StringList();

    for(auto&& a : m_uniforms_map)
    {
      result.push_back(a.first);
    }

    return result;
  }

  const mgl_core::StringList ComputeShader::uniform_blocks()
  {
    auto result = mgl_core::StringList();

    for(auto&& a : m_uniform_blocks_map)
    {
      result.push_back(a.first);
    }

    return result;
  }

} // namespace mgl

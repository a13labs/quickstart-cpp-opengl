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
#include "appgl.hpp"

namespace AppGL
{
  struct ShadersSources
  {
    enum Type
    {
      VertexShader,
      FragmentShader,
      GeometryShader,
      TessEvaluationShader,
      TessControlShader,

      ShadersCount,
    };

    AppCore::String sources[ShadersSources::ShadersCount];

    ShadersSources(const AppCore::String& vs_source,
                   const AppCore::String& fs_source,
                   const AppCore::String& gs_source,
                   const AppCore::String& tes_source,
                   const AppCore::String& tcs_source)
        : sources{vs_source, fs_source, gs_source, tes_source, tcs_source}
    { }

    ShadersSources(const AppCore::String& vs_source,
                   const AppCore::String& fs_source,
                   const AppCore::String& gs_source,
                   const AppCore::String& tes_source)
        : sources{vs_source, fs_source, gs_source, tes_source, NoShader}
    { }

    ShadersSources(const AppCore::String& vs_source, const AppCore::String& fs_source, const AppCore::String& gs_source)
        : sources{vs_source, fs_source, gs_source, NoShader, NoShader}
    { }

    ShadersSources(const AppCore::String& vs_source, const AppCore::String& fs_source)
        : sources{vs_source, fs_source, NoShader, NoShader, NoShader}
    { }

    ShadersSources(const AppCore::String& vs_source)
        : sources{vs_source, NoShader, NoShader, NoShader, NoShader}
    { }
  };
} // namespace AppGL
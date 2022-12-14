
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
#ifdef APPGL_GLX

#  include "appcore/log.hpp"
#  include "appgl/context.hpp"
#  include <dlfcn.h>

namespace AppGL
{
  ContextGLX::ContextGLX(ContextMode::Enum mode, int glversion)
  {
    mMode = mode;
    mContext = nullptr;
  }

  ContextGLX::~ContextGLX() { }

  GLFunction ContextGLX::Load(const AppCore::String& method)
  {
    return nullptr;
  }

  void ContextGLX::Enter() { }

  void ContextGLX::Exit() { }

  void ContextGLX::Release() { }

  bool ContextGLX::IsValid()
  {
    return false;
  }

} // namespace AppGL
#endif
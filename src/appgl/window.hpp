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
#include "appcore/application.hpp"
#include "appcore/event.hpp"
#include "appcore/input.hpp"
#include "context.hpp"

namespace AppGL
{
  class Window : public AppCore::Application::BaseWindow
  {

public:
    Window(const AppCore::Application::WindowConfig& config = AppCore::Application::WindowConfig())
        : AppCore::Application::BaseWindow(config)
    { }
    virtual ~Window() = default;

public:
    virtual bool CreateWindow() override;
    virtual void DestroyWindow() override;
    virtual void SwapBuffers() override;

    virtual bool OnWindowResize(AppCore::Events::WindowResizeEvent& event) override;

private:
    SDL_GLContext mContext;
    AppCore::Ref<Context> mSharedContext;
  };
} // namespace AppGL
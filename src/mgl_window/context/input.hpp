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
#include "mgl_core/mgl_core.hpp"

namespace mgl::window
{
  struct key
  {
    enum name
    {
      None = 0,
      Esc,
      Return,
      Tab,
      Space,
      Backspace,
      Up,
      Down,
      Left,
      Right,
      Insert,
      Delete,
      Home,
      End,
      PageUp,
      PageDown,
      Print,
      Plus,
      Minus,
      LeftBracket,
      RightBracket,
      Semicolon,
      Quote,
      Comma,
      Period,
      Slash,
      Backslash,
      Tilde,
      F1,
      F2,
      F3,
      F4,
      F5,
      F6,
      F7,
      F8,
      F9,
      F10,
      F11,
      F12,
      NumPad0,
      NumPad1,
      NumPad2,
      NumPad3,
      NumPad4,
      NumPad5,
      NumPad6,
      NumPad7,
      NumPad8,
      NumPad9,
      NumPadEnter,
      Key0,
      Key1,
      Key2,
      Key3,
      Key4,
      Key5,
      Key6,
      Key7,
      Key8,
      Key9,
      KeyA,
      KeyB,
      KeyC,
      KeyD,
      KeyE,
      KeyF,
      KeyG,
      KeyH,
      KeyI,
      KeyJ,
      KeyK,
      KeyL,
      KeyM,
      KeyN,
      KeyO,
      KeyP,
      KeyQ,
      KeyR,
      KeyS,
      KeyT,
      KeyU,
      KeyV,
      KeyW,
      KeyX,
      KeyY,
      KeyZ,

      LeftAlt,
      RightAlt,
      LeftCtrl,
      RightCtrl,
      LeftShift,
      RightShift,
      LeftMeta,
      RightMeta,

      Count
    };
  };

  struct mouse_button
  {
    enum name
    {
      Left,
      Middle,
      Right,
      None,

      Count
    };
  };

  struct gamepad_axis
  {
    enum name
    {
      LeftX,
      LeftY,
      LeftZ,
      RightX,
      RightY,
      RightZ,

      Count
    };
  };

  struct input_state
  {
    bool pressed_keys[key::Count];
    bool pressed_mouse_buttons[mouse_button::Count];
  };

  extern input_state s_input_state;

  inline bool is_key_pressed(key::name key)
  {
    return s_input_state.pressed_keys[key & 0xff];
  }

  inline bool IsMouseButtonPressed(mouse_button::name button)
  {
    return s_input_state.pressed_mouse_buttons[button & 0xff];
  }

} // namespace  mgl::window

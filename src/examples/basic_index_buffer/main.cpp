
#include "mgl_window/mgl_window.hpp"

class example_window : public mgl_window::window
{

  public:
  virtual void on_draw(float time, float frame_time) override;
  virtual void on_load() override;
  virtual void on_unload() override;

  private:
  mgl_core::ref<mgl_opengl::program> m_program;
  mgl_core::ref<mgl_opengl::buffer> m_vbo;
  mgl_core::ref<mgl_opengl::buffer> m_ibo;
  mgl_core::ref<mgl_opengl::vertex_array> m_vao;
};

void example_window::on_draw(float time, float frame_time)
{
  const auto ctx = context();
  ctx->clear(1.0, 1.0, 1.0);
  m_vao->render();
}

void example_window::on_load()
{
  set_title("Index Buffer");

  const auto ctx = context();
  m_program = ctx->program({
      R"(
                #version 330

                in vec2 in_vert;

                void main() {
                  gl_Position = vec4(in_vert, 0.0, 1.0);
                }
              )",
      R"(
                #version 330

                out vec4 f_color;

                void main() {
                  f_color = vec4(0.3, 0.5, 1.0, 1.0);
                }
            )",

  });

  mgl_core::mem_buffer<float> vertices = {
    0.0,  0.0, //

    -0.6, -0.8, //
    0.6,  -0.8, //

    0.6,  0.8, //
    -0.6, 0.8, //
  };

  mgl_core::mem_buffer<uint32_t> indices = { 0, 1, 2, 0, 3, 4 };

  m_vbo = ctx->buffer(vertices);
  m_ibo = ctx->buffer(indices);
  mgl_opengl::vertex_buffer_list m_content = { { m_vbo, "2f", { "in_vert" } } };

  m_vao = ctx->vertex_array(m_program, m_content, m_ibo);
}

void example_window::on_unload()
{
  m_ibo->release();
  m_vao->release();
  m_vbo->release();
  m_program->release();
}

int main(int argc, char* argv[])
{
  example_window app;
  app.run();

  return 0;
}
#include <groot/groot.hpp>

int main() {
  ge::Engine engine;

  engine.add_material("schwarzchild", ge::MaterialManager::Builder()
    .add_shader(ge::ShaderStage::VertexShader, "shaders/viewport.vert.spv")
    .add_shader(ge::ShaderStage::FragmentShader, "shaders/viewport.frag.spv")
    .add_shader(ge::ShaderStage::ComputeShader, "shaders/schwarzschild.comp.spv")
    .compute_space(128, 128)
    .add_texture("../dat/sky/px.png")
    .add_texture("../dat/sky/nx.png")
    .add_texture("../dat/sky/py.png")
    .add_texture("../dat/sky/ny.png")
    .add_texture("../dat/sky/pz.png")
    .add_texture("../dat/sky/nz.png")
    .add_canvas()
  );

  static_cast<void>(engine.add_object("schwarzchild", "../dat/quad.obj"));

  engine.run();
}
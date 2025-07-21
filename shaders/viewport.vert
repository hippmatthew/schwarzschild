#version 460

layout(binding = 0) readonly buffer transforms {
  layout(row_major) mat4 ge_Models[];
};

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uv_in;
layout(location = 2) in vec3 normal;

layout(location = 0) out vec2 uv_out;

void main() {
  gl_Position = vec4(position, 1.0);
  uv_out = uv_in;
}
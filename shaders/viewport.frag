#version 460

#define GAMMA 2.2
#define DITHER vec3(12.9898, 78.233, 43758.5453)

layout(binding = 8) uniform sampler2D tex;

layout(location = 0) in vec2 uv;

layout(location = 0) out vec4 frag_color;

void main() {
  const ivec2 index = ivec2(uv * vec2(textureSize(tex, 0)));
  vec3 color = texture(tex, uv).rgb;

  const float noise = fract(sin(dot(vec2(index), DITHER.xy)) * DITHER.z);
  color += (noise - 0.5) / 255.0;
  color = clamp(color, 0.0, 1.0);

  color = pow(color, vec3(GAMMA));

  frag_color = vec4(color, 1.0);
}
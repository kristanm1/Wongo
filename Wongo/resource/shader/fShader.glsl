#version 450 core

layout(location = 0) out vec4 a_fragColor;

layout(binding = 0) uniform sampler2D u_texture;

in vec2 v_texCoord;
in vec3 v_position;
in vec4 v_diffuseReflection;

void main()
{
    vec2 longitudeLatitude = vec2((atan(v_position.z, v_position.x) / 3.1415926 + 1.0) * 0.5,
                                  (asin(v_position.y) / 3.1415926 + 0.5));

    a_fragColor = texture(u_texture, longitudeLatitude) * v_diffuseReflection;
    //a_fragColor = vec4(1.0, 0.0, 0.0, 1.0) * v_diffuseReflection;
}

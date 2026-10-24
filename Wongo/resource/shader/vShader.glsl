#version 450 core

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec3 a_normal;
layout(location = 2) in vec2 a_texCoord;

layout(std140, binding = 0) uniform Block
{
    mat4 u_proj;
    mat4 u_view;
};

uniform mat4 u_model;

out vec3 v_position;
out vec4 v_diffuseReflection;

void main()
{

    vec4 lightColor = vec4(1.0, 1.0, 1.0, 1.0);
    vec3 lightDirection = normalize(vec3(2.0, 0.0, 1.0));
    vec3 normalDirection = normalize(mat3(u_model) * a_normal);

    v_diffuseReflection = lightColor * max(0.2, dot(normalDirection, lightDirection));

    vec3 positionNormalized = normalize(a_position);

    v_position = positionNormalized;
    gl_Position = u_proj * u_view * u_model * vec4(positionNormalized, 1.0);
}

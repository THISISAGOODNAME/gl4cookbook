#version 410

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;

out vec3 LightIntensity;

uniform vec4 LightPosition; // Light position in eye coords.
uniform vec3 Kd;            // Diffuse reflectivity
uniform vec3 Ld;            // Diffuse light intensity

uniform mat4 ModelViewMatrix;
uniform mat3 NormalMatrix;
//uniform mat4 ProjectionMatrix;
uniform mat4 MVP;

void main()
{
    // Convert normal and position to eye coords
    vec3 tnorm = normalize(NormalMatrix * VertexNormal);
    vec4 eyeCooeds = ModelViewMatrix * vec4(VertexPosition, 1.0f);
    vec3 s = normalize(vec3(LightPosition - eyeCooeds));

    // The diffuse shading equation
    LightIntensity = Ld * Kd * max(dot(s, tnorm), 0);

    // Convert position to clip coordinates and pass along
    gl_Position = MVP * vec4(VertexPosition, 1.0f);
}

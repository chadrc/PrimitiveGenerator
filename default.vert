#version 430

attribute vec3 position;
attribute vec3 normal;
attribute vec4 color;

uniform mat4 viewProjMat;
uniform mat4 modelMat;

out vec4 fColor;

void main(void)
{
    fColor = color;
    gl_Position = viewProjMat * modelMat * vec4(position, 1);
}


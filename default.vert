#version 430

attribute vec3 position;

uniform mat4 viewProjMat;
uniform mat4 modelMat;

out vec4 fColor;

void main(void)
{
    fColor = vec4(.5, .5, .5, 1);
    gl_Position = viewProjMat * modelMat * vec4(position, 1);
}


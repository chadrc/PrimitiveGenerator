#version 430

attribute vec3 position;
attribute vec3 normal;
attribute vec4 color;

uniform mat4 viewMat;
uniform mat4 projMat;
uniform mat4 modelMat;

out vec3 position_CamSpace;
out vec3 normal_CamSpace;
out vec4 fColor;

void main(void)
{
    position_CamSpace = vec3(viewMat * modelMat * vec4(position, 1));
    normal_CamSpace = vec3(viewMat * modelMat * vec4(normal, 0));
    fColor = color;
    gl_Position =  projMat * viewMat * modelMat * vec4(position, 1);
}


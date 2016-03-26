#version 430

attribute vec3 position;
attribute vec3 normal;
attribute vec4 color;

uniform mat4 viewMat;
uniform mat4 projMat;
uniform mat4 modelMat;

out vec4 fColor;

void main(void)
{
    float ambientLight = .2;
    vec4 lightClr = vec4(1, 1, 1, 1);
    vec4 lightPos = vec4(5,0,5,1);
    vec4 obj_CamSpace = viewMat * modelMat * vec4(position, 1);
    vec4 light_CamSpace = viewMat * lightPos;
    vec4 norm_CamSpace = viewMat * modelMat * vec4(normal, 1);
    vec4 dif = light_CamSpace - obj_CamSpace;
    light_CamSpace.z = 0;
    obj_CamSpace.z = 0;
    norm_CamSpace.z = 0;
    float dist = distance(light_CamSpace, obj_CamSpace);

    float cosTheta = clamp(dot(norm_CamSpace, dif), 0, 1);

    fColor = (color * lightClr * cosTheta) + color * ambientLight;// / (dist*dist);
    gl_Position =  projMat * viewMat * modelMat * vec4(position, 1);
}


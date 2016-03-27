#version 430

uniform mat4 viewMat;

in vec3 position_CamSpace;
in vec3 normal_CamSpace;

vec3 lightPosWorld = vec3(.6, 0, .6);
vec3 ls = vec3 (1.0, 1.0, 1.0);
vec3 ld = vec3 (.7, .7, .7);
vec3 la = vec3 (.2, .2, .2);

vec3 ks = vec3 (1.0, 1.0, 1.0);
vec3 kd = vec3 (1.0, .5, 0.0);
vec3 ka = vec3 (1.0, 1.0, 1.0);

float specExp = 1000.0;

out vec4 fragColor;

void main(void)
{
    vec3 ia = la * ka;

    vec3 light_CamSpace = vec3(viewMat * vec4(lightPosWorld, 1.0));
    vec3 dif = light_CamSpace - position_CamSpace;
    vec3 dir = normalize(dif);
    float theta = dot(dir, normal_CamSpace);
    theta = max(theta, 0.0);

    vec3 id = ld * kd * theta;

    vec3 reflection_CamSpace = reflect(-dir, normal_CamSpace);
    vec3 surfaceToViewerEye = normalize(-position_CamSpace);
    float specTheta = dot(reflection_CamSpace, surfaceToViewerEye);
    specTheta = max(theta, 0.0);
    float specFactor = pow(specTheta, specExp);

    vec3 is = ls * ks * specFactor;

    fragColor = vec4(is + id + ia, 1.0);
}


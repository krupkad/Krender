#version 130
// ^ Change this to version 130 if you have compatibility issues

uniform mat4 u_Model;
uniform mat4 u_ModelInvTr;
uniform mat4 u_ViewProj;
uniform vec3 u_CameraPos;

attribute vec3 vs_Position;
attribute vec3 vs_Normal;

varying vec4 fs_CameraVector;
varying vec4 fs_Normal;

void main() {

    fs_Normal = normalize(u_ModelInvTr * vec4(vs_Normal, 0));

    vec4 modelposition = u_Model * vec4(vs_Position, 1);

    // Set up our vector for the light
    fs_CameraVector = normalize(vec4(u_CameraPos, 1) - modelposition);

    //built-in things to pass down the pipeline
    gl_Position = u_ViewProj * modelposition;
}

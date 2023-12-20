#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TexCoord;

uniform mat4 u_ViewMatrix;
uniform mat4 u_ProjectionMatrix;
uniform mat4 u_TransformMatrix;

out vec2 v_TexCoord;

void main()
{
	v_TexCoord = a_TexCoord * 10.0f;
	gl_Position = u_ProjectionMatrix * u_ViewMatrix * u_TransformMatrix * vec4(a_Position, 1.0f);
}


#type fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform sampler2D u_Texture;
uniform vec4 u_Color;

void main()
{
	color = texture(u_Texture, v_TexCoord) * u_Color;
}
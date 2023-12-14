#pragma once

// 该头文件用于包含所有需要的文件，这样在 Sandbox 中就只用包含 Hazel.h 了

//for use by Hazel applications
#include "Hazel/Application.h"
#include "Hazel/Layer.h"
#include "Hazel/Log.h"

#include "Hazel/Core/Timestep.h"

#include "Hazel/Input.h"
#include "Hazel/KeyCodes.h"
#include "Hazel/MouseButtonCodes.h"
#include "Hazel/OrthoGraphicCameraController.h"

#include "Hazel/ImGui/ImGuiLayer.h"

//----Renderer------------------------------
#include "Hazel/Renderer/Renderer.h"
#include "Hazel/Renderer/RenderCommand.h"

#include "Hazel/Renderer/Buffer.h"
#include "Hazel/Renderer/Shader.h"
#include "Hazel/Renderer/Texture.h"
#include "Hazel/Renderer/VertexArray.h"

#include "Hazel/Renderer/OrthoGraphicCamera.h"
//------------------------------------------

//----Entry Point---------------------------
#include "Hazel/EntryPoint.h"
//------------------------------------------



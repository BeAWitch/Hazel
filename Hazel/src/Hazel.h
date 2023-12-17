#pragma once

// 该头文件用于包含所有需要的文件，这样在 Sandbox 中就只用包含 Hazel.h 了

//for use by Hazel applications
#include "Hazel/Core/Application.h"
#include "Hazel/Core/Layer.h"
#include "Hazel/Core/Log.h"

#include "Hazel/Core/Timestep.h"

#include "Hazel/Core/Input.h"
#include "Hazel/Core/KeyCodes.h"
#include "Hazel/Core/MouseButtonCodes.h"
#include "Hazel/Renderer/OrthoGraphicCameraController.h"

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
#include "Hazel/Core/EntryPoint.h"
//------------------------------------------



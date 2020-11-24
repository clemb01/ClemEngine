#include "cepch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace ClemEngine
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}
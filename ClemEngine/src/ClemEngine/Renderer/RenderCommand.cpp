#include "cepch.h"
#include "RenderCommand.h"

namespace ClemEngine
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}
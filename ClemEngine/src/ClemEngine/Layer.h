#pragma once

#include "ClemEngine/Core.h"
#include "ClemEngine/Core/Timestep.h"
#include "ClemEngine/Events/Event.h"

namespace ClemEngine {

	class CLEMENGINE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}
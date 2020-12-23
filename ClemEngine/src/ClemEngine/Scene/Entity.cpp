#include "cepch.h"
#include "Entity.h"

namespace ClemEngine
{
	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{ }
}
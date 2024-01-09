#include "hzpch.h"
#include "Scene.h"

#include "Entity.h"
#include "Component.h"
#include "Hazel/Renderer/Renderer2D.h"

namespace Hazel {

	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
	}

	Entity Scene::CreateEntity(const std::string& name)
	{
		// 创建并初始化Entity，添加默认Component
		Entity entity = { m_Registry.create(), this };
		entity.AddComponent<TransformComponent>();
		auto& tag = entity.AddComponent<TagComponent>();
		tag = name.empty() ? "Entity" : name;

		return entity;
	}

	void Scene::OnUpdate(Timestep ts)
	{
		auto group = m_Registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
		for (auto entity : group)
		{
			auto& [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);

			Renderer2D::DrawQuad(transform, sprite.Color);
		}
	}

}
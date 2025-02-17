#pragma once
#include <vector>
#include <memory>
#include <typeindex>
#include <unordered_map>
#include "Transform.h"
#include "Component.h"

namespace dae
{
	class Texture2D;

	// TODO :: should become final
	class GameObject
	{
	public:
		virtual void FixedUpdate(float fixedTimeStep);
		virtual void Update(float deltaTime);
		virtual void Render() const;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		template <typename T, typename... Args>
		T* AddComponent(Args&&... args);

		template <typename T>
		void RemoveComponent();

		template <typename T>
		T* GetComponent() const;

		template <typename T>
		bool HasComponent() const;

	private:
		Transform m_transform{};
		std::shared_ptr<Texture2D> m_texture{};
		std::vector<std::unique_ptr<Component>> m_Components;
		std::unordered_map<std::type_index, Component*> m_ComponentMap;
	};

	template <typename T, typename... Args>
	T* GameObject::AddComponent(Args&&... args)
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

		auto component = std::make_unique<T>(std::forward<Args>(args)...);
		component->SetOwner(this);
		T* componentPtr = component.get();
		m_Components.push_back(std::move(component));
		m_ComponentMap[std::type_index(typeid(T))] = componentPtr;
		return componentPtr;
	}

	template <typename T>
	void GameObject::RemoveComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

		auto it = std::remove_if(m_Components.begin(), m_Components.end(),
			[](const std::unique_ptr<Component>& component)
			{
				return typeid(*component) == typeid(T);
			});

		if (it != m_Components.end())
		{
			m_ComponentMap.erase(std::type_index(typeid(T)));
			m_Components.erase(it, m_Components.end());
		}
	}

	template <typename T>
	T* GameObject::GetComponent() const
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

		auto it = m_ComponentMap.find(std::type_index(typeid(T)));
		if (it != m_ComponentMap.end())
		{
			return static_cast<T*>(it->second);
		}
		return nullptr;
	}

	template <typename T>
	bool GameObject::HasComponent() const
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

		return m_ComponentMap.find(std::type_index(typeid(T))) != m_ComponentMap.end();
	}
}


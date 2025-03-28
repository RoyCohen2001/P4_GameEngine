#include "RenderComponent.h"
#include "Renderer.h"

dae::RenderComponent::RenderComponent(GameObject* owner,const std::shared_ptr<Texture2D>& texture)
	: Component(owner),
	m_Texture{ texture }
{
}

void dae::RenderComponent::Render() const
{
	if (m_Texture)
	{
		auto owner = GetOwner();
		if (owner)
		{
			const auto& pos = GetOwner()->GetTransform().GetPosition();
			Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
		}
	}
}

void dae::RenderComponent::SetTexture(std::shared_ptr<Texture2D> texture)
{
	m_Texture = texture;
}

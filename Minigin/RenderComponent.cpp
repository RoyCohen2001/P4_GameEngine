#include "RenderComponent.h"
#include "Renderer.h"

dae::RenderComponent::RenderComponent(std::shared_ptr<Texture2D> texture)
	: m_Texture{ texture }
{
}

void dae::RenderComponent::Render() const
{
	if (m_Texture)
	{
		const auto& pos = GetOwner()->GetTransform().GetPosition();
		Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
	}
}

void dae::RenderComponent::SetTexture(std::shared_ptr<Texture2D> texture)
{
	m_Texture = texture;
}

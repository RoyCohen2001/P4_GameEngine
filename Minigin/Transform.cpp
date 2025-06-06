#include "Transform.h"

void dae::Transform::SetPosition(const float x, const float y, const float z)
{
	m_position.x = x;
	m_position.y = y;
	m_position.z = z;
}

void dae::Transform::SetPosition(const glm::vec3& position)
{
	m_position = position;
}

void dae::Transform::SetX(float x)
{
	m_position.x = x; 
}

void dae::Transform::SetY(float y)
{
	m_position.y = y;
}

#include "stdafx.h"
#include "Object.h"
#include<math.h>
#include<float.h>

Object::Object()
{
	m_position.x = m_position.y = 0.0f, m_position.z = 0.5f;
	m_size.x = m_size.y = 0.5f;
	m_color.r = m_color.g = m_color.b = 1.0f; m_color.a = 1.0f;

	m_Velocity = Vector(0.0f, 0.0f, 0.0f);
	m_MaxVelocity = Vector(0.5f, 0.5f, 0.0f);
	m_Acceleration = Vector(0.0f, 0.0f, 0.0f);

	m_Mass = 10.0f;
	m_CoefFrict = 0.5f;
}

Object::~Object()
{
}

void Object::ApplyForce(float x, float y)
{
	m_Force = m_Force + Vector(x, y, 0.0f);

	// 가속도 = 힘 / 질량
	m_Acceleration = m_Force / m_Mass;
}

void Object::Update(float ElapsedTime)
{
	// 마찰력
	// 정규화
	float magVel = sqrtf(m_Velocity.x * m_Velocity.x + m_Velocity.y * m_Velocity.y);
	float Velx = m_Velocity.x / magVel;
	float Vely = m_Velocity.y / magVel;

	// 마찰력의 방향
	float Fricx = -Velx;
	float Fricy = -Vely;

	// 마찰력
	float Friction = m_CoefFrict * m_Mass * 9.8f;

	Fricx *= Friction;
	Fricy *= Friction;

	if (magVel < FLT_EPSILON)
	{
		m_Velocity.x = m_Velocity.y = 0;
	}
	else
	{
		float Accelerationx = Fricx / m_Mass;
		float Accelerationy = Fricy / m_Mass;

		float AfterVelx = m_Velocity.x + (Accelerationx * ElapsedTime);
		float AfterVely = m_Velocity.y + (Accelerationy * ElapsedTime);

		if (AfterVelx * m_Velocity.x < 0.0f)  m_Velocity.x = 0;
		else m_Velocity.x = AfterVelx;

		if (AfterVely * m_Velocity.y < 0.0f)  m_Velocity.y = 0;
		else m_Velocity.y = AfterVely;
	}

	// 속도 = 이전 속도 + 가속도 * 시간
	m_Velocity.x = m_Velocity.x + (m_Acceleration.x * ElapsedTime);
	m_Velocity.y = m_Velocity.y + (m_Acceleration.y * ElapsedTime);

	// 위치 = 이전 위치 + 속도 * 시간
	m_position.x = m_position.x + (m_Velocity.x * ElapsedTime);
	m_position.y = m_position.y + (m_Velocity.y * ElapsedTime);

	if (m_position.x > 2.5f) m_position.x = -2.5f;
	else if (m_position.x < -2.5f) m_position.x = 2.5f;

	if (m_position.y > 2.5f) m_position.y = -2.5f;
	else if (m_position.y < -2.5f) m_position.y = 2.5f;

	m_Acceleration = Vector(0.0f, 0.0f, 0.0f);
}
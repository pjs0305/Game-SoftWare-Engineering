#pragma once

struct Vector
{
	float x, y, z;
public:
	Vector() : x(0.0f), y(0.0f), z(0.0f) {};
	Vector(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}
	Vector(const Vector& p) : x(p.x), y(p.y), z(p.z) {}
	const Vector& operator=(const Vector& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;

		return v;
	}
	~Vector() {};

	const Vector& operator*(float scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;

		return Vector(x, y, z);
	}
	const Vector& operator+(const Vector& p)
	{
		x += p.x;
		y += p.y;
		z += p.z;

		return *this;
	}
	const Vector& operator+(float scalar)
	{
		x += scalar;
		y += scalar;
		z += scalar;

		return *this;
	}
	const Vector& operator/(float scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;

		return *this;
	}
};

struct Size
{
	float x, y;
public:
	Size() {};
	Size(float xx, float yy) : x(xx), y(yy) {}
	~Size() {};
};

struct Color
{
	float r, g, b, a;
public:
	Color() {};
	Color(float rr, float gg, float bb, float aa) : r(rr), g(gg), b(bb), a(aa) {}
	~Color() {};
};

class Object
{
private:
	Vector m_position;
	Size m_size;
	Color m_color;

	Vector m_Velocity; // 속도
	Vector m_MaxVelocity; // 속도
	Vector m_Acceleration; // 가속도

	Vector m_Force; // 힘
	float m_Mass; // 중력

	float m_CoefFrict; // 마찰계수

public:
	Object();
	virtual ~Object();

	Vector GetPosition() { return m_position; }
	void SetPosition(float x, float y, float z) { m_position.x = x; m_position.y = y; m_position.z = z; }
	void SetPosition(Vector& position) { m_position = position; }

	Size GetSize() { return m_size; }
	void SetSize(Size size) { m_size = size; }

	float GetMass() { return m_Mass; }
	void SetMass(float Mass) { m_Mass = Mass; }

	float GetCoefFrict() { return m_CoefFrict; }
	void SetCoefFrict(float CoefFrict) { m_CoefFrict = CoefFrict; }

	Color GetColor() { return m_color; }
	void SetColor(float r, float g, float b, float a) { m_color.r = r; m_color.g = g; m_color.b = b; m_color.a = a; }
	void SetColor(Color& color) { m_color = color; }

	Vector GetVelocity() { return m_Velocity; }
	void SetVelocity(Vector Velocity) { m_Velocity = Velocity; }

	Vector GetAcceleration() { return m_Acceleration; }
	void SetAcceleration(Vector Acceleration) { m_Acceleration = Acceleration; }

	void Move(Vector Direction, float Distance);
	void ApplyForce(float x, float y);

	virtual void Update(float ElapsedTime);
};


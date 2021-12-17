#ifndef VECTOR3_H
#define VECTOR3_H

#include "Math.h"
#include <iostream>

namespace My {
	struct Vector3 {
	public:
		float x;
		float y;
		float z;

		static Vector3 zero;
		static Vector3 one;
		static Vector3 forward;
		static Vector3 back;
		static Vector3 right;
		static Vector3 left;
		static Vector3 up;
		static Vector3 down;

		Vector3();
		Vector3(float x, float y, float z = 1);
		Vector3(const Vector3& vector);
		//Vector3(const Vector2& vector2); para despues

		//static methods
		static float Angle(Vector3 from, Vector3 to) noexcept;
		static Vector3 ClampMagnitude(Vector3 vector, float maxLength) noexcept;
		static float Magnitude(Vector3 vector) noexcept;
		static float Magnitude(float x, float y, float z) noexcept;
		static Vector3 Cross(Vector3 a, Vector3 b) noexcept;
		static float Distance(Vector3 a, Vector3 b) noexcept;
		static float Dot(Vector3 a, Vector3 b) noexcept;
		static Vector3 Lerp(Vector3 a, Vector3 b, float t) noexcept;
		static Vector3 LerpUnclamped(Vector3 a, Vector3 b, float t) noexcept;
		static Vector3 Max(Vector3 a, Vector3 b) noexcept;
		static Vector3 Min(Vector3 a, Vector3 b) noexcept;
		static float SqrMagnitude(Vector3 vector) noexcept;
		static Vector3 Normalize(Vector3& vector) noexcept;
		static Vector3 Project(Vector3 vector, Vector3 onNormal) noexcept;
		static Vector3 Reflect(Vector3 inDirection, Vector3 inNormal) noexcept;

		// methods
		void Set(float newX, float newY, float newZ) noexcept;
		void Scale(Vector3 scale) noexcept;
		void Normalize() noexcept;
		Vector3 Normalized() noexcept;

		// operators 
		Vector3& operator = (const Vector3& p);

		friend std::ostream& operator << (std::ostream& o, const Vector3& p)
		{
			o << "[" << p.x << ", " << p.y << ", " << p.z << "]";
			return o;
		}
		friend std::istream& operator >> (std::istream& i, Vector3& p)
		{
			i >> p.x >> p.y >> p.z;
			i.ignore();
			return i;
		}
	};

	// extern operators
	Vector3 operator + (Vector3 a, Vector3 b);
	Vector3 operator - (Vector3 a, Vector3 b);
	Vector3 operator * (Vector3 a, Vector3 b);
	Vector3 operator * (Vector3 a, float b);
	Vector3 operator * (float b, Vector3 a);
	Vector3 operator * (Vector3 a, double b);
	Vector3 operator * (double b, Vector3 a);
	Vector3 operator / (Vector3 a, float b);
	bool operator ==(Vector3 a, Vector3 b);
	bool operator !=(Vector3 a, Vector3 b);
}

#endif // !VECTOR3_H

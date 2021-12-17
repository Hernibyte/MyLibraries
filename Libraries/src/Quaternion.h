#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"

namespace My {
	struct Quaternion {
		float x;
		float y;
		float z;
		float w;

		float Get(int index);
		void Set(int index, float value);

		static Quaternion identity;

		Quaternion Normalized() noexcept;

		Vector3 EulerAngles() noexcept;
		void EulerAngles(Vector3 value) noexcept;

		Quaternion();
		Quaternion(float x, float y, float z, float w);
		Quaternion(const Quaternion& quaternion);
		Quaternion(Vector3 vector, float w);

		void Set(float x, float y, float z, float w) noexcept;
		void Set(Quaternion quaternion) noexcept;

		void Normalize() noexcept;

		void SetFromToRotation(Vector3 fromDirection, Vector3 toDirection) noexcept;

		void SetLookRotation(Vector3 view) noexcept;
		void SetLookRotation(Vector3 view, Vector3 up) noexcept;

		//void ToAngleAxis();

		//Static methods
		static float Angle(Quaternion a, Quaternion b) noexcept;

		static Quaternion AngleAxis(float angle, Vector3 axis) noexcept;

		static float Dot(Quaternion a, Quaternion b) noexcept;

		static Quaternion Euler(Vector3 euler) noexcept;

		static Quaternion FromToRotation(Vector3 fromDirection, Vector3 toDirection) noexcept;

		static Quaternion Inverse(Quaternion& rotation) noexcept;

		static Quaternion Lerp(Quaternion a, Quaternion b, float t) noexcept;

		static Quaternion LerpUnclamped(Quaternion a, Quaternion b, float t) noexcept;

		static Quaternion LookRotation(Vector3 forward);
		static Quaternion LookRotation(Vector3& forward, Vector3& up);

		static Quaternion Normalize(Quaternion& quaternion) noexcept;

		static Quaternion RotateTowards(Quaternion from, Quaternion to, float maxDegreesDelta) noexcept;

		static Quaternion Slerp(Quaternion a, Quaternion b, float t) noexcept;

		static Quaternion SlerpUnclamped(Quaternion a, Quaternion b, float t) noexcept;

		// Operators
		void operator=(const Quaternion& quaternion);
	};

	//Vector3 operator*(Quaternion a, Quaternion b);
	Quaternion operator*(Quaternion a, Quaternion b);
	bool operator==(Quaternion a, Quaternion b);
	bool operator!=(Quaternion a, Quaternion b);
}

#endif // !QUATERNION_H

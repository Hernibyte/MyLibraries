#include "Quaternion.h"

float My::Quaternion::Get(int index)
{
	switch (index)
	{
	case 0:
		return this->x;
		break;
	case 1:
		return this->y;
		break;
	case 2:
		return this->z;
		break;
	case 3:
		return this->w;
		break;
	default:
		throw "Out of range: Use 0, 1, 2 or 3";
		break;
	}
}

void My::Quaternion::Set(int index, float value)
{
	switch (index)
	{
	case 0:
		this->x = value;
		break;
	case 1:
		this->y = value;
		break;
	case 2:
		this->z = value;
		break;
	case 3:
		this->w = value;
		break;
	default:
		throw "Out of range: Use 0, 1, 2 or 3";
		break;
	}
}

My::Quaternion My::Quaternion::identity = Quaternion(0.0f, 0.0f, 0.0f, 1.0f);

My::Quaternion My::Quaternion::Normalized() noexcept
{
	float mag = Sqrt(x * x + y * y + z * z + w * w);
	Quaternion quaternion{ x / mag, y / mag, z / mag, w / mag };
	return Quaternion(quaternion.x, quaternion.y, quaternion.z, quaternion.w);
}

My::Vector3 My::Quaternion::EulerAngles() noexcept
{
	Vector3 qAsVec3;
	qAsVec3.x = radToDeg * Asin(x * 2);
	qAsVec3.y = radToDeg * Asin(y * 2);
	qAsVec3.z = radToDeg * Asin(z * 2);
	return qAsVec3;
}
void My::Quaternion::EulerAngles(Vector3 value) noexcept
{
	Quaternion quaternion = Euler(value);
	x = quaternion.x;
	y = quaternion.y;
	z = quaternion.z;
	w = quaternion.w;
}

My::Quaternion::Quaternion() {
	Quaternion::x = 0.0f;
	Quaternion::y = 0.0f;
	Quaternion::z = 0.0f;
	Quaternion::w = 0.0f;
}

My::Quaternion::Quaternion(float x, float y, float z, float w)
{
	Quaternion::x = x;
	Quaternion::y = y;
	Quaternion::z = z;
	Quaternion::w = w;
}
My::Quaternion::Quaternion(const Quaternion& quaternion)
{
	Quaternion::x = quaternion.x;
	Quaternion::y = quaternion.y;
	Quaternion::z = quaternion.z;
	Quaternion::w = quaternion.w;
}
My::Quaternion::Quaternion(Vector3 vector, float w)
{
	Quaternion::x = vector.x;
	Quaternion::y = vector.y;
	Quaternion::z = vector.z;
	Quaternion::w = w;
}

void My::Quaternion::Set(float x, float y, float z, float w) noexcept
{
	Quaternion::x = x;
	Quaternion::y = y;
	Quaternion::z = z;
	Quaternion::w = w;
}

void My::Quaternion::Set(Quaternion quaternion) noexcept
{
	Quaternion::x = quaternion.x;
	Quaternion::y = quaternion.y;
	Quaternion::z = quaternion.z;
	Quaternion::w = quaternion.w;
}

void My::Quaternion::Normalize() noexcept
{
	Quaternion normal = Quaternion(Normalized());
	x = normal.x;
	y = normal.y;
	z = normal.z;
	w = normal.w;
}

void My::Quaternion::SetFromToRotation(Vector3 fromDirection, Vector3 toDirection) noexcept
{
	Quaternion quaternion = FromToRotation(fromDirection, toDirection);
	x = quaternion.x;
	y = quaternion.y;
	z = quaternion.z;
	w = quaternion.w;
}

void My::Quaternion::SetLookRotation(Vector3 view) noexcept
{
	Vector3 up = Vector3::up;
	SetLookRotation(view, up);
}
void My::Quaternion::SetLookRotation(Vector3 view, Vector3 up) noexcept
{
	this->Set(LookRotation(view, up));
}

float My::Quaternion::Angle(Quaternion a, Quaternion b) noexcept
{
	float f = Dot(a, b);
	return Acos(Min(Abs(f), 1.0f)) * 2.0f * radToDeg;
}

My::Quaternion My::Quaternion::AngleAxis(float angle, Vector3 axis) noexcept
{
	if (Vector3::SqrMagnitude(axis) == 0.0f)
		return identity;

	angle *= degToRad * 0.5f;
	axis.Normalize();
	Quaternion result = identity;
	axis = axis * Sin(angle);
	result.x = axis.x;
	result.y = axis.y;
	result.z = axis.z;
	result.w = Cos(angle);

	return Normalize(result);
}

float My::Quaternion::Dot(Quaternion a, Quaternion b) noexcept
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

My::Quaternion My::Quaternion::Euler(Vector3 euler) noexcept
{
	Quaternion quaternionX = identity;
	Quaternion quaternionY = identity;
	Quaternion quaternionZ = identity;

	float sin = Sin(degToRad * euler.x * 0.5f);
	float cos = Cos(degToRad * euler.x * 0.5f);
	quaternionX.Set(sin, 0.0f, 0.0f, cos);

	sin = Sin(degToRad * euler.y * 0.5f);
	cos = Cos(degToRad * euler.y * 0.5f);
	quaternionY.Set(0.0f, sin, 0.0f, cos);

	sin = Sin(degToRad * euler.z * 0.5f);
	cos = Cos(degToRad * euler.z * 0.5f);
	quaternionZ.Set(0.0f, 0.0f, sin, cos);

	return Quaternion(quaternionX * quaternionY * quaternionZ);
}

My::Quaternion My::Quaternion::FromToRotation(Vector3 fromDirection, Vector3 toDirection) noexcept
{
	Vector3 cross = Vector3::Cross(fromDirection, toDirection);
	Quaternion quaternion = identity;
	quaternion.x = cross.x;
	quaternion.y = cross.y;
	quaternion.z = cross.z;
	quaternion.w = Vector3::Magnitude(fromDirection) * Vector3::Magnitude(toDirection) + Vector3::Dot(fromDirection, toDirection);
	quaternion.Normalize();
	return quaternion;
}

My::Quaternion My::Quaternion::Inverse(Quaternion& rotation) noexcept
{
	return Quaternion(-rotation.x, -rotation.y, -rotation.z, rotation.w);
}

My::Quaternion My::Quaternion::Lerp(Quaternion a, Quaternion b, float t) noexcept
{
	if (t > 1) t = 1;
	if (t < 0) t = 0;
	return LerpUnclamped(a, b, t);
}

My::Quaternion My::Quaternion::LerpUnclamped(Quaternion a, Quaternion b, float t) noexcept
{
	Quaternion resultInterpolated = identity;

	if (t >= 1)
		resultInterpolated = b;
	else if (t <= 0)
		resultInterpolated = a;
	else {
		Quaternion difference = Quaternion(b.x - a.x, b.y - a.y, b.z - a.z, b.w - b.w);
		Quaternion differenceLerped = Quaternion(difference.x * t, difference.y * t, difference.z * t, difference.w * t);

		resultInterpolated = Quaternion(a.x + differenceLerped.x, a.y + differenceLerped.y, a.z + differenceLerped.z, a.w + differenceLerped.w);
	}
	return resultInterpolated.Normalized();
}

My::Quaternion My::Quaternion::LookRotation(Vector3 forward)
{
	Vector3 up = Vector3::up;
	return Quaternion::LookRotation(forward, up);
}
My::Quaternion My::Quaternion::LookRotation(Vector3& forward, Vector3& up)
{
	throw "Not Implemented";
}

My::Quaternion My::Quaternion::Normalize(Quaternion& quaternion) noexcept
{
	return Quaternion(quaternion.Normalized());
}

My::Quaternion My::Quaternion::RotateTowards(Quaternion from, Quaternion to, float maxDegreesDelta) noexcept
{
	float num = Quaternion::Angle(from, to);
	if (num == 0.0f)
		return to;
	float t = Min(1.0f, maxDegreesDelta / num);
	return Quaternion::SlerpUnclamped(from, to, t);
}

My::Quaternion My::Quaternion::Slerp(Quaternion a, Quaternion b, float t) noexcept
{
	if (t > 1) t = 1;
	if (t < 0) t = 0;
	return SlerpUnclamped(a, b, t);
}

My::Quaternion My::Quaternion::SlerpUnclamped(Quaternion a, Quaternion b, float t) noexcept
{
	Quaternion resultInterpolated = identity;

	float cosHalfTheta = Dot(a, b);
	if (Abs(cosHalfTheta) >= 1.0f) {
		resultInterpolated.Set(a.x, a.y, a.z, a.w);
		return resultInterpolated;
	}

	float halfTheta = Acos(cosHalfTheta);
	float sinHalfTheta = Sqrt(1 - cosHalfTheta * cosHalfTheta);
	if (Abs(sinHalfTheta) < 0.001f) {
		resultInterpolated.w = (a.w * 0.5f + b.w * 0.5f);
		resultInterpolated.x = (a.x * 0.5f + b.x * 0.5f);
		resultInterpolated.y = (a.y * 0.5f + b.y * 0.5f);
		resultInterpolated.z = (a.z * 0.5f + b.z * 0.5f);
		return resultInterpolated;
	}

	float ratioA = Sin((1 - t) * halfTheta) / sinHalfTheta;
	float ratioB = Sin(t * halfTheta) / sinHalfTheta;
	resultInterpolated.w = (a.w * ratioA + b.w * ratioB);
	resultInterpolated.x = (a.x * ratioA + b.x * ratioB);
	resultInterpolated.y = (a.y * ratioA + b.y * ratioB);
	resultInterpolated.z = (a.z * ratioA + b.z * ratioB);
	return resultInterpolated;
}

void My::Quaternion::operator=(const Quaternion& quaternion) {
	this->x = quaternion.x;
	this->y = quaternion.y;
	this->z = quaternion.z;
	this->w = quaternion.w;
}

My::Quaternion My::operator*(Quaternion a, Quaternion b)
{
	float awXbw = a.w * b.w;
	float awXbx = a.w * b.x;
	float awXby = a.w * b.y;
	float awXbz = a.w * b.z;

	float axXbw = a.x * b.w;
	float axXbx = a.x * b.x;
	float axXby = a.x * b.y;
	float axXbz = a.x * b.z;

	float ayXbw = a.y * b.w;
	float ayXbx = a.y * b.x;
	float ayXby = a.y * b.y;
	float ayXbz = a.y * b.z;

	float azXbw = a.z * b.w;
	float azXbx = a.z * b.x;
	float azXby = a.z * b.y;
	float azXbz = a.z * b.z;


	float rowRealResult = (awXbw - axXbx - ayXby - azXbz);
	float rowIResult = (awXbx + axXbw + ayXbz - azXby);
	float rowJResult = (awXby - axXbz + ayXbw + azXbx);
	float rowKResult = (awXbz + axXby - ayXbx + azXbw);

	return Quaternion(rowIResult, rowJResult, rowKResult, rowRealResult);
}

bool My::operator==(Quaternion a, Quaternion b)
{
	return Quaternion::Dot(a, b) > 0.999999f;
}

bool My::operator!=(Quaternion a, Quaternion b)
{
	return Quaternion::Dot(a, b) <= 0.999999f;
}
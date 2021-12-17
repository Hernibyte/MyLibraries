#include "Vector3.h"

My::Vector3 My::Vector3::zero    = My::Vector3();
My::Vector3 My::Vector3::one     = My::Vector3(1.0f, 1.0f, 1.0f);
My::Vector3 My::Vector3::forward = My::Vector3(1.0f, 0.0f, 1.0f);
My::Vector3 My::Vector3::back    = My::Vector3(1.0f, 0.0f, -1.0f);
My::Vector3 My::Vector3::right   = My::Vector3(1.0f, 0.0f, 0.0f);
My::Vector3 My::Vector3::left    = My::Vector3(-1.0f, 0.0f, 0.0f);
My::Vector3 My::Vector3::up      = My::Vector3(0.0f, 1.0f, 0.0f);
My::Vector3 My::Vector3::down    = My::Vector3(0.0f, -1.0f, 0.0f);


My::Vector3::Vector3() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}
My::Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
My::Vector3::Vector3(const Vector3& vector) {
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}

float My::Vector3::Angle(Vector3 from, Vector3 to) noexcept
{
	float dotResult = Dot(from, to);
	float magProduct = Magnitude(from) * Magnitude(to);
	float arcosTitha = Acos(dotResult / magProduct);
	return (arcosTitha) / (3.14159265358979323846f / 180);
}
My::Vector3 My::Vector3::ClampMagnitude(Vector3 vector, float maxLength) noexcept
{
	if (Magnitude(vector) > maxLength)
		return vector.Normalized() * maxLength;
	else
		return vector;
}
float My::Vector3::Magnitude(float x, float y, float z) noexcept
{
	return Sqrt(
		Pow(x, 2) +
		Pow(y, 2) +
		Pow(z, 2));
}
float My::Vector3::Magnitude(Vector3 vector) noexcept
{
	return Magnitude(vector.x, vector.y, vector.z);
}
My::Vector3 My::Vector3::Cross(Vector3 a, Vector3 b) noexcept
{
	Vector3 result;
	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return result;
}
float My::Vector3::Distance(Vector3 a, Vector3 b) noexcept
{
	return Sqrt(
		Pow((a.x - b.x), 2) +
		Pow((a.y - b.y), 2) +
		Pow((a.z - b.z), 2));
}
float My::Vector3::Dot(Vector3 a, Vector3 b) noexcept
{
	return a.x * b.x +
		a.y * b.y +
		a.z * b.z;
}
My::Vector3 My::Vector3::Lerp(Vector3 a, Vector3 b, float t) noexcept
{
	if (t < 0.0f)
		t = 0.0f;
	else if (t > 1.0f)
		t = 1.0f;
	return LerpUnclamped(a, b, t);
}
My::Vector3 My::Vector3::LerpUnclamped(Vector3 a, Vector3 b, float t) noexcept
{
	Vector3 result;
	result.x = a.x + (b.x - a.x) * t;
	result.y = a.y + (b.y - a.y) * t;
	result.z = a.z + (b.z - a.z) * t;
	return result;
}
My::Vector3 My::Vector3::Max(Vector3 a, Vector3 b) noexcept
{
	Vector3 result;
	result.x = (a.x > b.x) ? a.x : b.x;
	result.y = (a.y > b.y) ? a.y : b.y;
	result.z = (a.z > b.z) ? a.z : b.z;
	return result;
}
My::Vector3 My::Vector3::Min(Vector3 a, Vector3 b) noexcept
{
	Vector3 result;
	result.x = (a.x < b.x) ? a.x : b.x;
	result.y = (a.y < b.y) ? a.y : b.y;
	result.z = (a.z < b.z) ? a.z : b.z;
	return result;
}
float My::Vector3::SqrMagnitude(Vector3 vector) noexcept
{
	return Sqrt(Magnitude(vector));
}
My::Vector3 My::Vector3::Normalize(Vector3& vector) noexcept
{
	vector.x = vector.x / Magnitude(vector.x, vector.y, vector.z);
	vector.y = vector.y / Magnitude(vector.x, vector.y, vector.z);
	vector.z = vector.z / Magnitude(vector.x, vector.y, vector.z);
	return vector;
}

My::Vector3 My::Vector3::Project(Vector3 vector, Vector3 onNormal) noexcept
{
	return (Dot(vector, onNormal) / Pow(Magnitude(onNormal), 2) * onNormal);
}
My::Vector3 My::Vector3::Reflect(Vector3 inDirection, Vector3 inNormal) noexcept
{
	inNormal.Normalize();
	return inDirection - 2 * (Dot(inDirection, inNormal)) * inNormal;
}

void My::Vector3::Set(float x, float y, float z) noexcept
{
	Vector3::x = x;
	Vector3::y = y;
	Vector3::z = z;
}
void My::Vector3::Scale(Vector3 scale) noexcept
{
	Set(x * scale.x, y * scale.y, z * scale.z);
}
void My::Vector3::Normalize() noexcept
{
	Vector3::x = Vector3::x / Magnitude(Vector3::x, Vector3::y, Vector3::z);
	Vector3::y = Vector3::y / Magnitude(Vector3::x, Vector3::y, Vector3::z);
	Vector3::z = Vector3::z / Magnitude(Vector3::x, Vector3::y, Vector3::z);
}
My::Vector3 My::Vector3::Normalized() noexcept
{
	Vector3 result;
	result.x = Vector3::x / Magnitude(Vector3::x, Vector3::y, Vector3::z);
	result.y = Vector3::y / Magnitude(Vector3::x, Vector3::y, Vector3::z);
	result.z = Vector3::z / Magnitude(Vector3::x, Vector3::y, Vector3::z);
	return result;
}

My::Vector3& My::Vector3::operator=(const Vector3& p)
{
	if (this != &p) {
		this->x = p.x;
		this->y = p.y;
		this->z = p.z;
	}
	return *this;
}

My::Vector3 My::operator+(Vector3 a, Vector3 b)
{
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

My::Vector3 My::operator-(Vector3 a, Vector3 b)
{
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

My::Vector3 My::operator*(Vector3 a, Vector3 b)
{
	return Vector3(a.x * b.x, a.y * b.y, a.z * b.z);
}

My::Vector3 My::operator*(Vector3 a, float b)
{
	return Vector3(a.x * b, a.y * b, a.z * b);
}

My::Vector3 My::operator*(float b, Vector3 a)
{
	return Vector3(a.x * b, a.y * b, a.z * b);
}

My::Vector3 My::operator*(Vector3 a, double b)
{
	return Vector3(a.x * (float)b, a.y * (float)b, a.z * (float)b);
}

My::Vector3 My::operator*(double b, Vector3 a)
{
	return Vector3(a.x * (float)b, a.y * (float)b, a.z * (float)b);
}

My::Vector3 My::operator/(Vector3 a, float b)
{
	return Vector3(b * (-a.x), b * (-a.y), b * (-a.z));
}

bool My::operator==(Vector3 a, Vector3 b)
{
	float diff_x = a.x - b.x;
	float diff_y = a.y - b.y;
	float diff_z = a.z - b.z;
	float sqrmag = diff_x * diff_x + diff_y * diff_y + diff_z * diff_z;
	return sqrmag < kEpsilon* kEpsilon;
}

bool My::operator!=(Vector3 a, Vector3 b)
{
	return !(a == b);
}
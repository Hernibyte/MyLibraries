#ifndef MATH_H
#define MATH_H

#include <math.h>

namespace My {
	const float PI = 3.14159265358979323846f;
	const float Infinity = INFINITY;
	const float NaN = NAN;
	const float radToDeg = (180.0f / PI);
	const float degToRad = (PI / 180.0f);
	const float kEpsilon = 1e-05f;

	float Cos(float value)
	{
		return cosf(value);
	}
	double Cos(double value)
	{
		return cos(value);
	}

	float Sin(float value)
	{
		return sinf(value);
	}
	double Sin(double value)
	{
		return sin(value);
	}

	float Tan(float value)
	{
		return tanf(value);
	}
	double Tan(double value)
	{
		return tan(value);
	}

	float Acos(float value)
	{
		return acosf(value);
	}
	double Acos(double value)
	{
		return acos(value);
	}

	float Asin(float value)
	{
		return asinf(value);
	}
	double Asin(double value)
	{
		return asin(value);
	}

	float Atan(float value)
	{
		return atanf(value);
	}
	double Atan(double value)
	{
		return atan(value);
	}

	float Atan2(float firstValue, float secondValue)
	{
		return atan2f(firstValue, secondValue);
	}
	double Atan2(double firstValue, double secondValue)
	{
		return atan2(firstValue, secondValue);
	}

	float Cosh(float value)
	{
		return coshf(value);
	}
	double Cosh(double value)
	{
		return cosh(value);
	}

	float Sinh(float value)
	{
		return sinhf(value);
	}
	double Sinh(double value)
	{
		return sinh(value);
	}

	float Tanh(float value)
	{
		return tanhf(value);
	}
	double Tanh(double value)
	{
		return tanh(value);
	}

	float Acosh(float value)
	{
		return acoshf(value);
	}
	double Acosh(double value)
	{
		return acosh(value);
	}

	float Asinh(float value)
	{
		return asinhf(value);
	}
	double Asinh(double value)
	{
		return asinh(value);
	}

	float Atanh(float value)
	{
		return atanhf(value);
	}
	double Atanh(double value)
	{
		return atanh(value);
	}

	float Exp(float value)
	{
		return expf(value);
	}
	double Exp(double value)
	{
		return exp(value);
	}

	float Frexp(float x, int* y)
	{
		return frexpf(x, y);
	}
	double Frexp(double x, int* y)
	{
		return frexp(x, y);
	}

	float Ldexp(float x, int y)
	{
		return ldexpf(x, y);
	}
	double Ldexp(double x, int y)
	{
		return ldexp(x, y);
	}

	float Log(float value)
	{
		return logf(value);
	}
	double Log(double value)
	{
		return log(value);
	}

	float Log10(float value)
	{
		return log10f(value);
	}
	double Log10(double value)
	{
		return log10(value);
	}

	float Modf(float x, float* y)
	{
		return modff(x, y);
	}
	double Modf(double x, double* y)
	{
		return modf(x, y);
	}

	float Exp2(float value)
	{
		return exp2f(value);
	}
	double Exp2(double value)
	{
		return exp2(value);
	}

	float Expm1(float value)
	{
		return expm1f(value);
	}
	double Expm1(double value)
	{
		return expm1(value);
	}

	int Ilogb(float value)
	{
		return ilogbf(value);
	}
	double Ilogb(double value)
	{
		return ilogb(value);
	}

	float Log1p(float value)
	{
		return log1pf(value);
	}
	double Log1p(double value)
	{
		return log1p(value);
	}

	float Log2(float value)
	{
		return log2f(value);
	}
	double Log2(double value) {
		return log2(value);
	}

	float Logb(float value)
	{
		return logbf(value);
	}
	double Logb(double value)
	{
		return logb(value);
	}

	float Scalbln(float x, long y) {
		return scalblnf(x, y);
	}
	double Scalbln(double x, long y)
	{
		return scalbln(x, y);
	}

	float Scalbn(float x, int y)
	{
		return scalbnf(x, y);
	}
	double Scalbn(double x, int y)
	{
		return scalbn(x, y);
	}

	float Pow(float x, float y)
	{
		return powf(x, y);
	}
	double Pow(double x, double y)
	{
		return pow(x, y);
	}

	float Sqrt(float value)
	{
		return sqrtf(value);
	}
	double Sqrt(double value)
	{
		return sqrt(value);
	}

	float Cbrt(float value)
	{
		return cbrtf(value);
	}
	double Cbrt(double value)
	{
		return cbrt(value);
	}

	float Hypot(float x, float y)
	{
		return hypotf(x, y);
	}
	double Hypot(double x, double y)
	{
		return hypot(x, y);
	}

	float Erf(float value)
	{
		return erff(value);
	}
	double Erf(double value)
	{
		return erf(value);
	}

	float Erfc(float value)
	{
		return erfcf(value);
	}
	double Erfc(double value)
	{
		return erfc(value);
	}

	float Tgamma(float value)
	{
		return tgammaf(value);
	}
	double Tgamma(double value)
	{
		return tgamma(value);
	}

	float Lgamma(float value)
	{
		return lgammaf(value);
	}
	double Lgamma(double value)
	{
		return lgamma(value);
	}

	float Copysing(float number, float sing)
	{
		return copysignf(number, sing);
	}
	double Copysing(double number, double sing)
	{
		return copysign(number, sing);
	}

	float Nanf(const char* value)
	{
		return nanf(value);
	}
	double Nan(const char* value)
	{
		return nan(value);
	}

	float Nextafter(float x, float y)
	{
		return nextafterf(x, y);
	}
	double Nextafter(double x, double y)
	{
		return nextafter(x, y);
	}

	float Nexttoward(float x, float y)
	{
		return nexttowardf(x, y);
	}
	double Nexttoward(double x, double y)
	{
		return nexttoward(x, y);
	}

	float Dif(float x, float y)
	{
		return fdimf(x, y);
	}
	double Dif(double x, double y)
	{
		return fdim(x, y);
	}

	float Max(float x, float y)
	{
		return fmaxf(x, y);
	}
	double Max(double x, double y)
	{
		return fmax(x, y);
	}

	float Min(float x, float y)
	{
		return fminf(x, y);
	}
	double Min(double x, double y)
	{
		return fmin(x, y);
	}

	int Abs(int value)
	{
		return abs(value);
	}
	float Abs(float value)
	{
		return fabsf(value);
	}
	double Abs(double value)
	{
		return fabs(value);
	}

	float Fma(float x, float y, float z)
	{
		return fmaf(x, y, z);
	}
	double Fma(double x, double y, double z)
	{
		return fma(x, y, z);
	}

	template<class T> bool IsFinite(T)
	{
		return isfinite(T);
	}

	template<class T> bool IsInfinite(T)
	{
		return isinf(T);
	}

	template<class T> bool IsNaN(T)
	{
		return isnan(T);
	}

	template<class T> bool IsNormal(T)
	{
		return isnormal(T);
	}
}

#endif // !MATH_H

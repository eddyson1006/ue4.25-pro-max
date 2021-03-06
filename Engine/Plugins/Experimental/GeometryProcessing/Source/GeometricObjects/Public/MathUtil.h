// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreTypes.h"   // required for GEOMETRICOBJECTS_API macro
#include <cmath>
#include <cfloat>


/**
 * Math constants and utility functions, templated on float/double type
 */
template<typename RealType>
struct TMathUtilConstants;

template<>
struct TMathUtilConstants<float>
{
	/** Machine Epsilon - float approx 1e-7, double approx 2e-16 */
	GEOMETRICOBJECTS_API static constexpr float Epsilon = FLT_EPSILON;
	/** Zero tolerance for math operations (eg like parallel tests) - float 1e-6, double 1e-8 */
	GEOMETRICOBJECTS_API static constexpr float ZeroTolerance = 1e-06f;

	/** largest possible number for type */
	GEOMETRICOBJECTS_API static constexpr float MaxReal = FLT_MAX;

	/** 3.14159... */
	GEOMETRICOBJECTS_API static constexpr float Pi = 3.1415926535897932384626433832795f;
	GEOMETRICOBJECTS_API static constexpr float FourPi = 4.0f * Pi;
	GEOMETRICOBJECTS_API static constexpr float TwoPi = 2.0f*Pi;
	GEOMETRICOBJECTS_API static constexpr float HalfPi = 0.5f*Pi;

	/** 1.0 / Pi */
	GEOMETRICOBJECTS_API static constexpr float InvPi = 1.0f / Pi;
	/** 1.0 / (2*Pi) */
	GEOMETRICOBJECTS_API static constexpr float InvTwoPi = 1.0f / TwoPi;

	/** pi / 180 */
	GEOMETRICOBJECTS_API static constexpr float DegToRad = Pi / 180.0f;
	/** 180 / pi */
	GEOMETRICOBJECTS_API static constexpr float RadToDeg = 180.0f / Pi;

	//static constexpr float LN_2;
	//static constexpr float LN_10;
	//static constexpr float INV_LN_2;
	//static constexpr float INV_LN_10;

	GEOMETRICOBJECTS_API static constexpr float Sqrt2 = 1.4142135623730950488016887242097f;
	GEOMETRICOBJECTS_API static constexpr float InvSqrt2 = 1.0f / Sqrt2;
	GEOMETRICOBJECTS_API static constexpr float Sqrt3 = 1.7320508075688772935274463415059f;
	GEOMETRICOBJECTS_API static constexpr float InvSqrt3 = 1.0f / Sqrt3;
};

template<>
struct TMathUtilConstants<double>
{
	/** Machine Epsilon - float approx 1e-7, double approx 2e-16 */
	GEOMETRICOBJECTS_API static constexpr double Epsilon = DBL_EPSILON;
	/** Zero tolerance for math operations (eg like parallel tests) - float 1e-6, double 1e-8 */
	GEOMETRICOBJECTS_API static constexpr double ZeroTolerance = 1e-08;

	/** largest possible number for type */
	GEOMETRICOBJECTS_API static constexpr double MaxReal = DBL_MAX;

	/** 3.14159... */
	GEOMETRICOBJECTS_API static constexpr double Pi = 3.1415926535897932384626433832795;
	GEOMETRICOBJECTS_API static constexpr double FourPi = 4.0 * Pi;
	GEOMETRICOBJECTS_API static constexpr double TwoPi = 2.0 * Pi;
	GEOMETRICOBJECTS_API static constexpr double HalfPi = 0.5 * Pi;

	/** 1.0 / Pi */
	GEOMETRICOBJECTS_API static constexpr double InvPi = 1.0 / Pi;
	/** 1.0 / (2*Pi) */
	GEOMETRICOBJECTS_API static constexpr double InvTwoPi = 1.0 / TwoPi;

	/** pi / 180 */
	GEOMETRICOBJECTS_API static constexpr double DegToRad = Pi / 180.0;
	/** 180 / pi */
	GEOMETRICOBJECTS_API static constexpr double RadToDeg = 180.0 / Pi;

	//static constexpr double LN_2;
	//static constexpr double LN_10;
	//static constexpr double INV_LN_2;
	//static constexpr double INV_LN_10;

	GEOMETRICOBJECTS_API static constexpr double Sqrt2 = 1.4142135623730950488016887242097;
	GEOMETRICOBJECTS_API static constexpr double InvSqrt2 = 1.0 / Sqrt2;
	GEOMETRICOBJECTS_API static constexpr double Sqrt3 = 1.7320508075688772935274463415059;
	GEOMETRICOBJECTS_API static constexpr double InvSqrt3 = 1.0 / Sqrt3;
};


// we use TMathUtil<int> so we need to define these nonsense constants
template<>
struct TMathUtilConstants<int32>
{
	GEOMETRICOBJECTS_API static constexpr int32 Epsilon = 0;
	GEOMETRICOBJECTS_API static constexpr int32 ZeroTolerance = 0;
	GEOMETRICOBJECTS_API static constexpr int32 MaxReal = 2147483647;
	GEOMETRICOBJECTS_API static constexpr int32 Pi = 3;
	GEOMETRICOBJECTS_API static constexpr int32 FourPi = 4 * Pi;
	GEOMETRICOBJECTS_API static constexpr int32 TwoPi = 2 * Pi;
	GEOMETRICOBJECTS_API static constexpr int32 HalfPi = 1;
	GEOMETRICOBJECTS_API static constexpr int32 InvPi = 1;
	GEOMETRICOBJECTS_API static constexpr int32 InvTwoPi = 1;
	GEOMETRICOBJECTS_API static constexpr int32 DegToRad = 1;
	GEOMETRICOBJECTS_API static constexpr int32 RadToDeg = 1;
	GEOMETRICOBJECTS_API static constexpr int32 Sqrt2 = 1;
	GEOMETRICOBJECTS_API static constexpr int32 InvSqrt2 = 1;
	GEOMETRICOBJECTS_API static constexpr int32 Sqrt3 = 2;
	GEOMETRICOBJECTS_API static constexpr int32 InvSqrt3 = 1;
};



template<typename RealType>
class TMathUtil : public TMathUtilConstants<RealType>
{
public:
	static inline bool IsNaN(const RealType Value);
	static inline bool IsFinite(const RealType Value);
	static inline RealType Abs(const RealType Value);
	static inline RealType Clamp(const RealType Value, const RealType ClampMin, const RealType ClampMax);
	static inline RealType Sign(const RealType Value);
	static inline RealType SignNonZero(const RealType Value);
	static inline RealType Max(const RealType A, const RealType B);
	static inline RealType Max3(const RealType A, const RealType B, const RealType C);
	static inline RealType Min(const RealType A, const RealType B);
	static inline RealType Min3(const RealType A, const RealType B, const RealType C);
	static inline RealType Sqrt(const RealType Value);
	static inline RealType Atan2(const RealType ValueY, const RealType ValueX);
	static inline RealType Sin(const RealType Value);
	static inline RealType Cos(const RealType Value);
	static inline RealType ACos(const RealType Value);
	static inline RealType Floor(const RealType Value);
	static inline RealType Ceil(const RealType Value);
	static inline RealType Pow(const RealType Value, const RealType Power);
	static inline RealType Lerp(const RealType A, const RealType B, RealType Alpha);


	/**
	 * @return result of Atan2 shifted to [0,2pi]  (normal ATan2 returns in range [-pi,pi])
	 */
	static inline RealType Atan2Positive(const RealType Y, const RealType X);

private:
	TMathUtil() = delete;
};
typedef TMathUtil<float> FMathf;
typedef TMathUtil<double> FMathd;


template<typename RealType>
bool TMathUtil<RealType>::IsNaN(const RealType Value)
{
	return std::isnan(Value);
}


template<typename RealType>
bool TMathUtil<RealType>::IsFinite(const RealType Value)
{
	return std::isfinite(Value);
}


template<typename RealType>
RealType TMathUtil<RealType>::Abs(const RealType Value)
{
	return (Value >= (RealType)0) ? Value : -Value;
}


template<typename RealType>
RealType TMathUtil<RealType>::Clamp(const RealType Value, const RealType ClampMin, const RealType ClampMax)
{
	return (Value < ClampMin) ? ClampMin : ((Value > ClampMax) ? ClampMax : Value);
}


template<typename RealType>
RealType TMathUtil<RealType>::Sign(const RealType Value)
{
	return (Value > (RealType)0) ? (RealType)1 : ((Value < (RealType)0) ? (RealType)-1 : (RealType)0);
}

template<typename RealType>
RealType TMathUtil<RealType>::SignNonZero(const RealType Value)
{
	return (Value < (RealType)0) ? (RealType)-1 : (RealType)1;
}

template<typename RealType>
RealType TMathUtil<RealType>::Max(const RealType A, const RealType B)
{
	return (A >= B) ? A : B;
}

template<typename RealType>
RealType TMathUtil<RealType>::Max3(const RealType A, const RealType B, const RealType C)
{
	return Max(Max(A, B), C);
}

template<typename RealType>
RealType TMathUtil<RealType>::Min(const RealType A, const RealType B)
{
	return (A <= B) ? A : B;
}

template<typename RealType>
RealType TMathUtil<RealType>::Min3(const RealType A, const RealType B, const RealType C)
{
	return Min(Min(A, B), C);
}

template<typename RealType>
RealType TMathUtil<RealType>::Sqrt(const RealType Value)
{
	return sqrt(Value);
}

template<typename RealType>
RealType TMathUtil<RealType>::Atan2(const RealType ValueY, const RealType ValueX)
{
	return atan2(ValueY, ValueX);
}

template<typename RealType>
RealType TMathUtil<RealType>::Sin(const RealType Value)
{
	return sin(Value);
}

template<typename RealType>
RealType TMathUtil<RealType>::Cos(const RealType Value)
{
	return cos(Value);
}

template<typename RealType>
RealType TMathUtil<RealType>::ACos(const RealType Value)
{
	return acos(Value);
}

template<typename RealType>
RealType TMathUtil<RealType>::Floor(const RealType Value)
{
	return floor(Value);
}

template<typename RealType>
RealType TMathUtil<RealType>::Ceil(const RealType Value)
{
	return ceil(Value);
}

template<typename RealType>
RealType TMathUtil<RealType>::Pow(const RealType Value, const RealType Power)
{
	return pow(Value, Power);
}

template<typename RealType>
RealType TMathUtil<RealType>::Lerp(const RealType A, const RealType B, RealType Alpha)
{
	Alpha = Clamp(Alpha, (RealType)0, (RealType)1);
	return ((RealType)1 - Alpha)*A + (Alpha)*B;
}

template<typename RealType>
RealType TMathUtil<RealType>::Atan2Positive(const RealType Y, const RealType X)
{
	// @todo this is a float atan2 !!
	RealType Theta = TMathUtil<RealType>::Atan2(Y, X);
	if (Theta < 0)
	{
		return ((RealType)2 * TMathUtil<RealType>::Pi) + Theta;
	}
	return Theta;
}

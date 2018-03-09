
/*
*   Copyright © 2018 Luxon Jean-Pierre
*   https://gumichan01.github.io/
*
*   This library is under the MIT license
*
*   Luxon Jean-Pierre (Gumichan01)
*   luxon.jean.pierre@gmail.com
*/

#ifndef FLOAT_HPP
#define FLOAT_HPP

#include <cmath>
#include <type_traits>


struct Float
{
    float v;
    /// Unboxing ≡ static_cast<float>(Float)
    operator float() const noexcept;
};

namespace FloatBox
{

template <typename N>
using Ftype = typename std::enable_if< std::is_arithmetic<N>::value &&
              !std::is_same<N,float>::value >::type;

/// Boxing
template <typename N>
inline constexpr Float fbox(Ftype<N> x) noexcept
{
    return Float{static_cast<float>(x)};
}

inline constexpr Float fbox(float x) noexcept
{
    return Float{ x };
}

}

Float& operator ++(Float& x) noexcept;
Float operator ++(Float& x, int) noexcept;
Float& operator --(Float& x) noexcept;
Float operator --(Float& x, int) noexcept;


constexpr Float operator -(const Float& x) noexcept
{
    return Float{ -x.v };
}

constexpr Float operator +(const Float& x, const Float& y) noexcept
{
    return Float{ x.v + y.v };
}

constexpr Float operator -(const Float& x, const Float& y) noexcept
{
    return Float{ x.v - y.v };
}

constexpr Float operator *(const Float& x, const Float& y) noexcept
{
    return Float{ x.v * y.v };
}

constexpr Float operator /(const Float& x, const Float& y) noexcept
{
    return Float{ x.v / y.v };
}


Float& operator +=(Float& x, const Float& y) noexcept;
Float& operator -=(Float& x, const Float& y) noexcept;
Float& operator *=(Float& x, const Float& y) noexcept;
Float& operator /=(Float& x, const Float& y) noexcept;

bool operator ==(const Float& x, const Float& y) noexcept;
bool operator !=(const Float& x, const Float& y) noexcept;


namespace FloatMath
{

inline constexpr Float abs(const Float& f) noexcept
{
    return FloatBox::fbox(std::abs(f.v));
}

inline constexpr Float acos(const Float& f) noexcept
{
    return FloatBox::fbox(std::acos(f.v));
}

inline constexpr Float asin(const Float& f) noexcept
{
    return FloatBox::fbox(std::asin(f.v));
}

inline constexpr Float atan(const Float& f) noexcept
{
    return FloatBox::fbox(std::atan(f.v));
}

inline constexpr Float ceil(const Float& f) noexcept
{
    return FloatBox::fbox(std::ceil(f.v));
}

inline constexpr Float cos(const Float& f) noexcept
{
    return FloatBox::fbox(std::cos(f.v));
}

inline constexpr Float cosh(const Float& f) noexcept
{
    return FloatBox::fbox(std::cosh(f.v));
}

inline constexpr Float exp(const Float& f) noexcept
{
    return FloatBox::fbox(std::exp(f.v));
}


inline constexpr Float floor(const Float& f) noexcept
{
    return FloatBox::fbox(std::floor(f.v));
}


inline constexpr Float log(const Float& f) noexcept
{
    return FloatBox::fbox(std::log(f.v));
}

inline constexpr Float log10(const Float& f) noexcept
{
    return FloatBox::fbox(std::log10(f.v));
}

inline constexpr Float pow(Float& f, const Float& p) noexcept
{
    return FloatBox::fbox(std::pow(f.v, p.v));
}

inline constexpr Float sin(const Float& f) noexcept
{
    return FloatBox::fbox(std::sin(f.v));
}

inline constexpr Float sinh(const Float& f) noexcept
{
    return FloatBox::fbox(std::sinh(f.v));
}

inline constexpr Float sqrt(const Float& f) noexcept
{
    return FloatBox::fbox(std::sqrt(f.v));
}

inline constexpr Float tan(const Float& f) noexcept
{
    return FloatBox::fbox(std::tan(f.v));
}

inline constexpr Float tanh(const Float& f) noexcept
{
    return FloatBox::fbox(std::tanh(f.v));
}

}

#endif // FLOAT_HPP

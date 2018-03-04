
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

#include <type_traits>

struct Float
{
    float v;
    /// Unboxing ≡ static_cast<float>(Float)
    operator float() const;
};

namespace FloatBox
{
/// Boxing
template <typename N>
inline constexpr Float
fbox(typename std::enable_if<std::is_arithmetic<N>::value, N>::type x) noexcept
{
    return Float{static_cast<float>(x)};
}

inline constexpr Float fobxf(float x) noexcept
{
    return Float{x};
}

inline constexpr Float fobxi(float x) noexcept
{
    return fbox<int>(x);
}

}

Float operator -(const Float& x);
Float& operator ++(Float& x);
Float operator ++(Float& x, int);
Float& operator --(Float& x);
Float operator --(Float& x, int);

Float operator +(const Float& x, const Float& y);
Float operator -(const Float& x, const Float& y);
Float operator *(const Float& x, const Float& y);
Float operator /(const Float& x, const Float& y);

Float& operator +=(Float& x, const Float& y);
Float& operator -=(Float& x, const Float& y);
Float& operator *=(Float& x, const Float& y);
Float& operator /=(Float& x, const Float& y);

bool operator ==(const Float& x, const Float& y);
bool operator !=(const Float& x, const Float& y);
bool operator <(const Float& x, const Float& y);
bool operator >(const Float& x, const Float& y);
bool operator <=(const Float& x, const Float& y);
bool operator >=(const Float& x, const Float& y);

namespace FloatMath
{

Float& abs(Float& f) noexcept;

Float& acos(Float& f) noexcept;
Float& asin(Float& f) noexcept;
Float& atan(Float& f) noexcept;

Float& cos(Float& f) noexcept;
Float& cosh(Float& f) noexcept;

Float& sin(Float& f) noexcept;
Float& sinh(Float& f) noexcept;

Float& tan(Float& f) noexcept;
Float& tanh(Float& f) noexcept;

Float& ceil(Float& f) noexcept;
Float& floor(Float& f) noexcept;

Float& exp(Float& f) noexcept;
Float& log(Float& f) noexcept;
Float& log10(Float& f) noexcept;

Float& pow(Float& f) noexcept;
Float& sqrt(Float& f) noexcept;

}

#endif // FLOAT_HPP

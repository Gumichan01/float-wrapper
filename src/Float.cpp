
#include "Float.hpp"

#include <cmath>
#include <algorithm>
#include <limits>

Float::operator float() const
{
    return v;
}

Float operator +(const Float x, const Float y)
{
    return Float{ x.v + y.v };
}

Float operator -(const Float x, const Float y)
{
    return Float{ x.v - y.v };
}

Float operator *(const Float x, const Float y)
{
    return Float{ x.v * y.v };
}

Float operator /(const Float x, const Float y)
{
    return Float{ x.v / y.v };
}


bool operator ==(const Float& x, const Float& y)
{
    static const float EPSILON = std::numeric_limits<float>::epsilon();
    float abs_x = fabsf(x);
    float abs_y = fabsf(y);
    float diff  = fabsf(x - y);

    if(x == y)
    {
        return true;
    }
    else if(x == 0.0f || y == 0.0f || diff < std::numeric_limits<float>::min())
    {
        return diff < (EPSILON * std::numeric_limits<float>::min());
    }
    else
    {
        return (diff / std::min((abs_x + abs_y),
                                std::numeric_limits<float>::max())) < EPSILON;
    }
}




struct Float
{
    float v;

    operator float();
};

Float operator -(const Float& x);
Float operator ++(Float& x);
Float operator ++(Float& x, int);
Float operator --(Float& x);
Float operator --(Float& x, int);

Float operator +(const Float x, const Float y);
Float operator -(const Float x, const Float y);
Float operator *(const Float x, const Float y);
Float operator /(const Float x, const Float y);

Float operator +=(const Float& x, const Float y);
Float operator -=(const Float& x, const Float y);
Float operator *=(const Float& x, const Float y);
Float operator /=(const Float& x, const Float y);

bool operator ==(const Float& x, const Float& y);
bool operator !=(const Float& x, const Float& y);
bool operator <(const Float& x, const Float& y);
bool operator >(const Float& x, const Float& y);
bool operator <=(const Float& x, const Float& y);
bool operator >=(const Float& x, const Float& y);

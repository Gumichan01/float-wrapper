

#include "../src/float.hpp"

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    constexpr double PI = 3.14159265358979323846;
    cout << "Hello World!\n";

    // Initialization + static_cast
    {
        Float f{4.2f};
        Float g{3.2f};
        float vf = static_cast<float>(g);
        cout << "-" << f << " " << vf << endl;
    }

    // Opposite value
    {
        Float f{4.2f};
        Float fe{-4.2f};

        if((-f).v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 1;
        }
    }

    // postfix '+'
    {
        Float f{4.2f};
        Float fe{4.2f};
        Float fee{f.v + 1.0f};

        if((f++).v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 2;
        }

        if(f != fee)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 3;
        }
    }

    // prefix '+'
    {
        Float f{4.2f};
        Float fe{f.v + 1.0f};

        if((++f).v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 4;
        }
    }

    // postfix '-'
    {
        Float f{4.2f};
        Float fe{4.2f};
        Float fee{f.v - 1.0f};

        if((f--).v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 5;
        }

        if(f != fee)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 6;
        }
    }

    // prefix '-'
    {
        Float f{4.2f};
        Float fe{f.v - 1.0f};

        if((--f).v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 7;
        }
    }

    // '+'
    {
        Float f{4.2f};
        Float fe{4.2f + 4.2f};

        if((f + f).v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 8;
        }
    }

    // '-'
    {
        Float f{4.2f};
        Float fe{4.2f - 4.2f};

        if((f - f).v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 9;
        }
    }

    // '*'
    {
        Float f{4.2f};
        Float fe{4.2f * 4.2f};

        if((f * f).v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 10;
        }
    }

    // '/'
    {
        Float f{10.0f};
        Float fe{10.0f / 2.0f};

        if((f / Float{2.0f}).v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 11;
        }
    }

    // '+='
    {
        Float f{4.2f};
        Float fe{4.2f + 4.2f};

        f += f;

        if(f.v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 12;
        }
    }

    // '-='
    {
        Float f{4.2f};
        Float fe{4.2f - 4.2f};

        f -= f;

        if(f.v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 13;
        }
    }

    // '*='
    {
        Float f{4.2f};
        Float fe{4.2f * 4.2f};

        f *= f;

        if(f.v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 14;
        }
    }

    // '/='
    {
        Float f{10.0f};
        Float fe{10.0f / 2.0f};

        f /= Float{2.0f};

        if(f.v != fe.v)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 15;
        }
    }

    // '==' easy
    {
        Float f{4.2f};
        Float fe{4.2f};
        bool res = (fe == f);

        if(!res)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 16;
        }
    }

    // '==' medium
    {
        Float f{0.3333333333f};
        Float fe{(1.0f / 3.0f)};
        bool res = (fe == f);

        if(!res)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 17;
        }
    }

    // '==' hard
    {
        Float f = FloatBox::fbox<decltype(PI)>(PI);
        Float fe{static_cast<float>(PI)};
        bool res = (fe == f);

        if(!res)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 18;
        }
    }

    // '!=' easy
    {
        Float f{4.2f};
        Float fe{4.3f};
        bool res = (fe != f);

        if(!res)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 19;
        }
    }

    // '!=' medium
    {
        Float f{0.3334343333f};
        Float fe{(1.0f/3.0f)};
        bool res = (fe != f);

        if(!res)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 20;
        }
    }

    // '!=' hard
    {
        Float f = FloatBox::fbox<decltype(PI)>(PI);
        Float fe{static_cast<float>(PI) + static_cast<float>(1.0 / PI)};
        bool res = (fe != f);

        if(!res)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 21;
        }
    }

    // '<'
    {
        Float f{4.2f};
        Float fe{4.1f};
        bool res = (fe < f);

        if(!res)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 22;
        }
    }

    // '>'
    {
        Float f{4.2f};
        Float fe{4.3f};
        bool res = (fe > f);

        if(!res)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 23;
        }
    }

    // '<='
    {
        Float f{4.2f};
        Float fe{4.1f};
        bool res = (fe <= f);

        if(!res)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 24;
        }
    }

    // '>='
    {
        Float f{4.2f};
        Float fe{4.3f};
        bool res = (fe >= f);

        if(!res)
        {
            cerr << "failure @" << __FILE__ << ":" << __LINE__ << "\n";
            return 25;
        }
    }

    // fbox
    {
        using namespace FloatBox;
        float x = 3.14f;
        Float f1 = fbox(x);
        Float f2 = fbox(42);
        ///Float wrong = fbox("hello"); // must not compile

        cout << f1 << " " << f2 << "\n";
    }

    cout << "SUCCESS\n";
    return 0;
}



#include "../src/Float.hpp"

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!\n";

    // Initialization + static_cast
    {
        Float f{4.2f};
        cout << f << endl;
        Float g{3.2f};
        float vf = static_cast<float>(g);
        cout << vf << endl;
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

        if((f++) != fe)
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

        if((++f) != fe)
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

        if((f--) != fe)
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
            return 8;
        }
    }

    cout << "SUCCESS\n";
    return 0;
}

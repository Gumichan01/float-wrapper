

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

    


    return 0;
}

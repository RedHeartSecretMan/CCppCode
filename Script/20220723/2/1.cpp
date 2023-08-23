
#include <iostream>
using namespace std;

class Test
{
    static int x;

public:
    Test()
    {
        x++;
    }
    static int getX()
    {
        return x;
    }
};
int Test::x = 0;
int main()
{
    cout << Test::getX() << " ";
    Test t[5];
    cout << Test::getX();
}
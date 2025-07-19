#include <iostream>
#include <bitset>
#include <iomanip>
#include <limits>

int a = 1;
class Pos{
    public:
    int x = 0;
    int y = 0;

};

int main(void)
{
    Pos pos;

    std::cout << pos.x <<  std::endl;

    pos.x = 10;

    std::cout << pos.x <<  std::endl;


}


#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
using namespace std;

int main(void) {
    struct Monster{
        int hp;
        string name;
        int atk;
        int def;
        int id;

    };

    Monster monster;

    monster.atk = 10;
    int *a = new int[5];

    int *ptr = a;

    for(int i=0;i<5;i++){
        *(ptr + i) = i+1;
        cout << *(ptr+i) << endl;
    }
    delete a;

    return 0;
}


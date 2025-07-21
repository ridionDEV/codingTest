#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
using namespace std;

struct Person{
    string name;
    int age;
    float height;
    float weight;
    int id;
};

int getNewId(){
    static int id = 0;
    id++;

    return id;
}

void Func_2(Person *_person){
    if((_person)->age >= 25) // (*_person).age 와 같음
        cout << _person->name << endl;
        cout << _person->age << endl;
}

void Swap(int &a,int &b){
    int temp = a;
    a = b;
    b =temp;
}

int main(void) {

    int a =10;
    int b = 20;


    Swap(a,b);
    cout << a << b;
    return 0;
}


#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

int main(void) {
    int month;
    int day;
    cout << "월을 입력하세요. : ";
    cin >> month;
    cout << "일을 입력하세요. : ";
    cin >> day;
    try{
        if(month<1 || month>12)
            throw out_of_range("월은 1~12의 정수여야 합니다.");
        if(day < 1 || day > 31)
            throw out_of_range("일은 1~31의 정수여야 합니다.");
    } catch(out_of_range& e){
        cerr << "예외 발생 : " << e.what() << endl;
        return 0;
    }
    string season;

    if(month<6)
        season = "봄";
    if(month>5&&month<9)
        season = "여름";
    if(month>8&&month<12)
        season = "가을";
    if(month>11&&month<3)
        season = "겨울";
    cout << "입력하신 날짜의 계절은 "<< season<<" 입니다."<<endl;

    return 0;
}


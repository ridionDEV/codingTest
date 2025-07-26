#include <iostream>
#include <random>
#include <limits>
using namespace std;

int main(void){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,100);
    int answer = dist(gen);

    bool is_correct = false;
    while(!is_correct){
        try{
            static int a;
            static int count = 0;

            cout << "숫자를 입력하세요. 남은 기회("<<6-count<<") : ";
            cin >> a;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                throw invalid_argument("숫자를 입력하세요.");
                continue;
            }
            if(a<=0 || a>100){
                throw out_of_range("1~100 사이의 숫자를 입력하세요.");
                continue;
            }

            if(a < answer){
                cout << "너무 낮아요!" << endl;
                count++;
            }
            else if(a>answer){
                cout << "너무 높아요!" << endl;
                count++;
            }
            else if(a==answer)
            {
                cout << "축하합니다!" << endl;
                is_correct = true;
            }

            if(count >= 6)
            {
                cout << "실패.. 정답은 " << answer << " 입니다." << endl;
                break;
            }
        }
        catch(const exception& e){
            cerr << e.what() << endl;
        }
    }

    return 0;
}
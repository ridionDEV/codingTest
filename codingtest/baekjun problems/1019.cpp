#include <iostream>
#include <string>

using namespace std;

long long n;
long long value = 10;
string num;


long long result[10] = {0};

void func1(){

    for(int i=1;i<=num.length();i++){
        


        for(int j=0;j<10;j++){

            if(j==0 && i == num.length()) continue;

            if((n/value)!=0 && j==0 && value !=10){

                result[j] += (n/value - 1) * (value/10);

            }
            else if((n/value) != 0){

                result[j] += n/value * value/10;

            }

            if(j==0 && value == 10) continue;
            

            if(j < num[num.length()-i] - '0'){

                result[j] += (value/10);

            }
            else if(j == num[num.length()-i] - '0'){

                if(value == 10)
                    result[j] += value/10;
                else{
                    string temp;
                    for(int k=num.length()-i+1;k<num.length();k++){
                        temp += num[k];
                    }
                    result[j] += stoi(temp) + 1;
                }
            }
        }

        value *=10;
    }
}

int main(void){

    cin >> n;

    num = to_string(n);

    func1();

    for(int i=0;i<10;i++){
        cout << result[i] << " ";
    }
    
    return 0;
}
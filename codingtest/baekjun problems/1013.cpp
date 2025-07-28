#include <iostream>
#include <string>
using namespace std;

int main(void){

    int t;
    cin >> t;
    for(int i=0;i<t;i++){
        string input;
        bool isTrue = true;
        string str(202,'2');
        cin >> input;
        for(int k=0;k<input.length();k++){
            str[k]=input[k];
        }
        for(int j=0;j<input.length();j++){

            if(str[j]=='1'){
                if(str[j+1]!='0' || str[j+2]!='0'){
                    isTrue = false;
                    break;
                }
                int count = j+3;

                if(str[count]=='2'){ isTrue=false; break;}

                while(str[count]=='0'){
                    count++;
                    if(str[count]=='2'){
                        isTrue = false;
                        break;
                    }
                }
                if(str[count]!='2')
                    count++;
                while(str[count]=='1'){
                    count++;
                    if(str[count]=='2') break;
                    if(str[count]=='0' && str[count+1]=='0'){
                        count--;
                        break;
                    }
                }
                j = count -1 ;

            }
            else if(str[j]=='0'){
                if(str[j+1]!='1'){
                    isTrue = false;
                    break;
                }

                j++;
            }
            
        }
        if(isTrue) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
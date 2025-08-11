#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<string> words,puzzle;
    string input;

    while(cin >> input && input != "-"){
        words.push_back(input);
    }

    while(cin >> input && input != "#"){
        puzzle.push_back(input);
    }

    for(string puz : puzzle){
        int p[26] = {0};
        int f[26] = {0};
        
        for(char c : puz) p[c - 'A']++;
        
        for(string word : words){

            int w[26] = {0};
            bool isTrue = true;

            for(char c : word) w[c - 'A']++;

            for(int i=0;i<26;i++){
                if(p[i] < w[i]){
                    isTrue = false;
                    break;
                };
            }

            if(isTrue){
                for(int i=0;i<26;i++){
                    if(w[i] != 0)
                        f[i]++;
                }
            }
        }

        int minCount = 98765432;
        int maxCount = 0;
        string min_s,max_s;

        for(int i=0;i<26;i++){
            if(p[i]!=0){
                if(minCount > f[i]){
                    min_s = (char)(i + 'A');
                    minCount = f[i];
                } 
                else if(minCount == f[i] ){
                    min_s += (char)(i + 'A');
                }

                if(maxCount < f[i]){
                    max_s = (char)(i + 'A');
                    maxCount = f[i];
                }
                else if(maxCount == f[i]){
                    max_s += (char)(i + 'A');
                }
            }
        }
        
        
        cout << min_s << " " << minCount << " " << max_s << " " << maxCount << endl;
    }
    



    return 0;
}
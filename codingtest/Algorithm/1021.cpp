#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> queue(n);
    for(int i=0;i<n;i++){
        queue[i] = 0; //모든 값 0으로 초기화
    }

    for(int i=0;i<m;i++){
        int r;
        cin >> r;
        queue[r-1] = i+1; //요소의 위치와 뽑아내는 순서(1,2,3...) 정해주기
    }

    int count =0;

    for(int i=1;i<m+1;i++){
        for(int j=0;j<n;j++){
            if(queue[j]==i)
                if(j==0){ //원하는 요소가 맨 앞에 있을때
                    queue.erase(queue.begin()); //맨 앞 요소 삭제
                    n--; //배열 크기 -1
                    break;
                }
                else{
                    int k;
                    k = min(j, n-j); //왼쪽과 오른쪽 회전중 최솟값 
                    count += k;
                    if(k==j) //왼쪽회전일 경우
                        rotate(queue.begin(),queue.begin()+k,queue.end());
                    else //오른쪽회전일 경우
                        rotate(queue.begin(),queue.end()-k,queue.end());

                    queue.erase(queue.begin()); //맨 앞 요소 삭제
                    n--; // 배열 크기 -1
                    break;
                }
        }
        
    }

    cout << count << endl;
    return 0;
}
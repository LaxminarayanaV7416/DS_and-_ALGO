#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;


int sumOfMultiples3And5(int range){
    int finalSum = 0;
    for(int i=1;i<range;i++){
        if(i%3==0){
            finalSum+=i;
        } else if(i%5==0){
            finalSum+=i;
        }
    }
    return finalSum;
}

int main(){
    int ans = sumOfMultiples3And5(1000);
    cout << ans << " is the answer " << endl;
}

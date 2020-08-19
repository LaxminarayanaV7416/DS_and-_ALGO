#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

long long int smallestNumberRemainZero(long long int start,long long int end_,long long int largest){
    long long int output = 0;
    for(long long int i=start;i<largest;i++){
        bool isRemainZeroForAll = true;
        for(long long int j=start;j<=end_;j++){
            if(i%j!=0){
                isRemainZeroForAll = false;
                break;
            }
        }
        if(isRemainZeroForAll){
            output = i;
            break;
        }
    }
    return output;
}

int main(){
    long long int x = smallestNumberRemainZero(1,20,100000000000);
    cout << x << endl;
}

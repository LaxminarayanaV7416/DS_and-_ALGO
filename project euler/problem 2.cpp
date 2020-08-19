#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int fibnocciSequence(int number){
    int output;
    if(number==0){
        output = 0;
    } else if(number==1){
        output = 1;
    } else{
        int sumOf = fibnocciSequence(number-1)+fibnocciSequence(number-2);
        output = sumOf;
    }
    return output;
}

int main(){
    int counter=0;
    int sumOf = 0;
    while(true){
        counter++;
        int result = fibnocciSequence(counter);
        if(result%2==0){
            cout << result << " ";
            sumOf+=result;
            if(sumOf>4000000){
                cout << "Sum is " << sumOf << endl;
                break;
            }
        }
    }
}

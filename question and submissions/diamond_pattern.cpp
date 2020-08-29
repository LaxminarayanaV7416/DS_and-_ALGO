#include <iostream>
#include <cmath>

using namespace std;

void print(int start,int endp,int range_number){
    for(int i=0;i<=range_number;i++){
        if(start<=i && i<=endp){
            cout << "*" << " ";
        } else {
            cout << " " << " ";
        }
    }
}


void pattern(int number){
    if(number%2==0){
        number = number+1;
    }

    int midValue = (number/2)+1;

    int i=0;
    while(number+1>=i){

        if(i<midValue){
            // increment
            int temp=i+midValue;
            if(temp==midValue){
                int start = midValue, endp = midValue;
                print(start,endp,number);

            } else{
                int start = midValue-i, endp = midValue+i;
                print(start,endp,number);
            }
        } else if(i==midValue) {
            print(0,number+1,number+1);
        } else {

            int x =i-midValue;

            //decrement
            if(i==number+1){
                print(midValue,midValue,number);
            } else{
                int start = x, endp = 2*midValue-start;
                print(start,endp,number);
            }
        }

        i++;
        cout << endl;
    }
}


int main()
{
    pattern(10);
}
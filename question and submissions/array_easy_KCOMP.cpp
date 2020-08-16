#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int rotations;
    cin >> rotations;

    int finalOutput[rotations] = {0};
    for(int rotation=0; rotation<rotations;rotation++){
        // Now lets take in the input and ka value

        long long int n,k;
        cin >> n >> k;

        long long int outputArray[n];
        bool isNegativePresent = false;

        for(int i=0;i<(n);i++){
            cin >> outputArray[i];
            if(outputArray[i]<0){
                isNegativePresent = true;
            }
        }
        long long int output = 0;

        if(isNegativePresent==0){

            int totalSum =0;
            for(int i=0;i<n; i++){
                totalSum+=outputArray[i];
            }
            output = totalSum*k;

        } else{
            int newArray[n*2];
            int counter = 0;

            int tempArray[n*2] = {0};
            long long int totalSum = 0;

            for(int i=0;i<2; i++){
                for(int j=0; j<n; j++){
                    newArray[counter] = outputArray[j];
                    if(outputArray[j]>=0){
                        totalSum+=outputArray[j];
                    } else {
                        tempArray[counter] = totalSum;
                        totalSum = 0;
                    }
                    counter++;
                }
            }
            long long int lala = *max_element(tempArray,tempArray+(n*2));
            output = lala;
        }
        finalOutput[rotation] = output;
    }

    for(int i=0;i<rotations;i++){
        cout << finalOutput[i] << endl;
    }

    return 0;
}

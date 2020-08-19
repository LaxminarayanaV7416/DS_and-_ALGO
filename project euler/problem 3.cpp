// #include <iostream>
// #include <set>
// #include <vector>
// #include <algorithm>
// #include <list>
// #include <cmath>
// using namespace std;

// bool isPrimeNumber(long long int number){
//     long long int root = sqrt(number)+1;
//     bool isPrime = true;
//     for(long long int i=2;i<root;i++){
//         if(number%i==0){
//             isPrime = false;
//             break;
//         }
//     }
//     return isPrime;
// }

// list<long long int> primeNumberGenerator(long long int number){
//     list<long long int> primeList;
//     for(long long int i=2;i<number;i++){
//         if(isPrimeNumber(i)){
//             primeList.push_back(i);
//         }
//     }
//     return primeList;
// }

// int main(){
//     long long int x;
//     cin >> x;
//     list<long long int> primeList = primeNumberGenerator(x);
//     for(auto numb:primeList){
//         if(x%numb ==0){
//             cout << numb << " ** ";
//         }
//     }
// }


#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;

bool isPrimeNumber(long long int number){
    long long int root = sqrt(number)+1;
    bool isPrime = true;
    for(long long int i=2;i<root;i++){
        if(number%i==0){
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int main(){
    long long int x;
    cin >> x;
    for(long long int i=2;i<=x;i++){
        if(x%i ==0 && isPrimeNumber(i)){
            cout << i << " ** ";
        }
    }
}

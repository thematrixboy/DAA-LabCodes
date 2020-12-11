#include <iostream>
using namespace std;

class EuclidA {
    public:
        int a , b;    
    EuclidA(){
        cout<<"Enter the values of a and b "<<endl;
        cin>>a>>b;
        cout<<"GCD of "<< a <<" and "<< b <<" is "<< gcd(a, b)<<endl;
    }
    
    int gcd(int a, int b) {
        if (b == 0)
        return a;
        return gcd(b, a % b);
    }
};
int main() {
    
    EuclidA e;
    return 0;
}

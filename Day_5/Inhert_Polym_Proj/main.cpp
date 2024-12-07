#include <iostream>

using namespace std;


class Base {
protected:
 int a ;
 int b ;

 public :

 Base(){
 cout << "Base constructor called " << endl;
 }

 Base(int a , int b ){
  cout << "Base Parametrized Constructor called .." << endl;
 this->a = a ;
 this->b = b ;
 }

  ~Base() {
        cout << "Base Destructor called .." << endl;
        cout<<"-----------------------------"<<endl;

    }

 int sum(int a , int b ){
 return a + b ;
 }

};


class Derived : public Base {
protected:
    int c;

public:
    Derived() : Base() {
        cout << "Derived Constructor called..." << endl;
    }

    Derived(int a, int b, int c) : Base(a, b) {
        this->c = c;
        cout << "Derived Parameterized Constructor called..." << endl;
    }

    ~Derived() {
        cout << "Derived Destructor called..." << endl;
        cout << "-----------------------------" << endl;
    }

    int getC() {
        return c;
    }

    int sum(int a, int b, int c) {
        return Base::sum(a, b) + c;
    }
};



class SecondDerived : public Derived {
protected:
    int z;

public:
    SecondDerived() : Derived() {
        cout << "SecondDerived Constructor called..." << endl;
    }

    SecondDerived(int a, int b, int c, int z) : Derived(a, b,c) {
        this->z = z;
        cout << "SecondDerived Parameterized Constructor called..." << endl;
    }

    ~SecondDerived() {
        cout << "SecondDerived Destructor called..." << endl;
        cout << "-----------------------------" << endl;
    }

    int getZ() {
        return z;
    }

    int sum(int a, int b, int c, int z) {
        return Base::sum(a, b) + z;
    }
};

/// standalone Method
void prntLine_m (){
    cout<<"-------------------------------------------------"<<endl;
}




int main()
{

 Derived e;
    prntLine_m();

    Derived d(10, 20, 30);
    cout << "Summation  = " << d.sum(10, 20, 30) << endl;
    prntLine_m();

    Base b(100, 200);
    Derived d1(10, 20, 40);
    cout << "Summation of Derived = " << d1.sum(10, 20, 40) << endl; // 70
    prntLine_m();

    SecondDerived d2(11, 20, 30, 50);
    cout << "Summation of SecondDerived = " << d2.sum(11, 20, 30, 50) << endl; // 111


    return 0;
}

#include <iostream>

using namespace std;

// Function to swap using pass by value
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByValue: a = " << a << ", b = " << b << endl;
}

// Function to swap using pass by address
void swapByAddress(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "Inside swapByAddress: a = " << *a << ", b = " << *b << endl;
}

// Function to swap using pass by reference
void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByReference: a = " << a << ", b = " << b << endl;
}

int main()
{
  int x = 10, y = 20;

    cout << "Before swapping: x = " << x << ", y = " << y << endl;

    // Swap by value
    swapByValue(x, y);
    cout << "After ByValue: x = " << x << ", y = " << y << endl;

    // Swap by address
    swapByAddress(&x, &y);
    cout << "After ByAddress: x = " << x << ", y = " << y << endl;

    // Swap by reference
    swapByReference(x, y);
    cout << "after ByReference: x = " << x << ", y = " << y << endl;


        complex_num c;
    c.set_real(-10.0);
    c.set_img(-15.0);


    complex_num x;
    x.set_real(10);
    x.set_img(15);


    complex_num v = c.add(x);


    v.display();
    int k=1;
    int m=2;
    swap2(k,m);
    cout<<k<<" "<<m;
    return 0;
}













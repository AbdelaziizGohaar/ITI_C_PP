#include <iostream>
using namespace std;

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
/////////////////////////////////////// Parameterized Constructor with Default Arguments
    ComplexNumber(double realData = 0, double imaginaryData = 0) {
        this->real = realData;
        this->imaginary = imaginaryData;
    }

/////////////////////////////////////////////////////////////// Setters for Real
    void setReal() {
        cout << "Enter a valid real number: ";
        cin >> real;
    }

    void setReal(int realData) {
        if (realData > 0) {
            real = realData;
        }
    }


    double getReal() {
        return real;
    }

 //////////////////////////////////////////////////////// Setters for Imaginary
    void setImaginary() {
        cout << "Enter a valid imaginary number: ";
        cin >> imaginary;
    }

    void setImaginary(int imgData) {
        if (imgData > 0) {
            imaginary = imgData;
        }
    }


    double getImaginary() {
        return imaginary;
    }

////////////////////////////////////////////// Arithmetic Operations
    ComplexNumber Add(ComplexNumber c) {
        ComplexNumber result;
        result.real = this->real + c.real;
        result.imaginary = this->imaginary + c.imaginary;
        return result;
    }

    ComplexNumber Subb(ComplexNumber c) {
        ComplexNumber result;
        result.real = this->real - c.real;
        result.imaginary = this->imaginary - c.imaginary;
        return result;
    }

//////////////////////////////////////// Display Method
    void display_2() {
        if (real != 0 || imaginary != 0) {
            cout << real;
            if (imaginary >= 0) {
                cout << "+";
            }
            cout << imaginary << "i" << endl;
        } else {
            cout << "0" << endl;
        }
    }

/////////////////////////////////////////////////////////// Operator Methods

//////// Plus

    ComplexNumber operator+(ComplexNumber c) {  //// plus c+c2
        ComplexNumber result;
        result.real = this->real + c.real;
        result.imaginary = this->imaginary + c.imaginary;
        return result;
    }

    ComplexNumber operator++() { // Prefix ---> ++c
        this->real++;
        this->imaginary++;
        return *this;
    }

    ComplexNumber operator++(int) { // Postfix--->  c++
        ComplexNumber c = *this;
        ++(*this);
        return c;
    }

    ComplexNumber operator+(int x) { //////////// Add Int   c+5
        ComplexNumber result;
        result.real = this->real + x;
        result.imaginary = this->imaginary + x;
        return result;
    }


  //////// Minus

    ComplexNumber operator-(ComplexNumber c) {  //// minus c-c2
        ComplexNumber result;
        result.real = this->real - c.real;
        result.imaginary = this->imaginary - c.imaginary;
        return result;
    }

    ComplexNumber operator--() { // Prefix ---> --c
        this->real--;
        this->imaginary--;
        return *this;
    }

    ComplexNumber operator--(int) { // Postfix--->  c--
        ComplexNumber c = *this;
        --(*this);
        return c;
    }

    ComplexNumber operator-(int x) { //////////// subtr Int   c-5
        ComplexNumber result;
        result.real = this->real - x;
        result.imaginary = this->imaginary - x;
        return result;
    }


    /////////////////////////////////////// ==
    bool operator==(ComplexNumber c1){
         if(this->real ==c1.real && this->imaginary ==c1.imaginary )
         {
           return true ;
         }else
         {
           return false ;
         }
    }



//////////////////////////////////////   +-
   ComplexNumber operator+=(ComplexNumber c){
         ComplexNumber result;
        result.real = this->real += c.real;
        result.imaginary = this->imaginary += c.imaginary;
        return result ;
    }



//////////////////////// float operator


};

// Standalone Method: 5 + c
ComplexNumber operator+(int x, ComplexNumber c) {
    ComplexNumber result;
    result.setReal(c.getReal() + x);
    result.setImaginary(c.getImaginary());
    return result;
}

// Standalone Method: 5 - c
ComplexNumber operator-(int x, ComplexNumber c) {
    ComplexNumber result;
    result.setReal(c.getReal() - x);
    result.setImaginary(c.getImaginary());
    return result;
}



int main() {

    // in the first create complex  objects
    ComplexNumber c1(3, 4); // 3 + 4i
    ComplexNumber c2(1, 2); // 1 + 2i

    // Display complex values  values
    cout << "-----------------------Initial Complex Numbers----------------------" << endl;
    cout << "c1: "; c1.display_2();
    cout << "c2: "; c2.display_2();

    // Test + operator (c1 + c2)
    ComplexNumber sum = c1 + c2;
    cout << "c1 + c2: "; sum.display_2();

    // Test - operator (c1 - c2)
    ComplexNumber diff = c1 - c2;
    cout << "c1 - c2: "; diff.display_2();

    // Test += operator (c1 += c2)
    c1 += c2;
    cout << "c1 += c2: "; c1.display_2();

    // Test prefix ++ operator (++c1)
    ++c1;
    cout << "++c1: "; c1.display_2();

    // Test postfix ++ operator (c1++)
    ComplexNumber temp = c1++;
    cout << "c1++ (before increment): "; temp.display_2();
    cout << "c1 (after increment): "; c1.display_2();

    // Test prefix -- operator (--c1)
    --c1;
    cout << "--c1: "; c1.display_2();

    // Test postfix -- operator (c1--)
    temp = c1--;
    cout << "c1-- (before decrement): "; temp.display_2();
    cout << "c1 (after decrement): "; c1.display_2();

    // Test + int operator (c1 + 5)
    ComplexNumber plusInt = c1 + 5;
    cout << "c1 + 5: "; plusInt.display_2();

    // Test - int operator (c1 - 5)
    ComplexNumber minusInt = c1 - 5;
    cout << "c1 - 5: "; minusInt.display_2();

    // Test int + ComplexNumber operator (5 + c1)
    ComplexNumber intPlus = 5 + c1;
    cout << "5 + c1: "; intPlus.display_2();

    // Test int - ComplexNumber operator (5 - c1)
    ComplexNumber intMinus = 5 - c1;
    cout << "5 - c1: "; intMinus.display_2();

    // Test == operator
    cout << "c1 == c2: " << (c1 == c2 ? "true" : "false") << endl;

    // Arithmetic Operations (Add, Subb methods)
    ComplexNumber addResult = c1.Add(c2);
    cout << "c1.Add(c2): "; addResult.display_2();

    ComplexNumber subResult = c1.Subb(c2);
    cout << "c1.Subb(c2): "; subResult.display_2();

    return 0;
}











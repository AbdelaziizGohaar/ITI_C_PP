#include <iostream>
#include <limits>

using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "here byvalue : a = " << a << ", b = " << b << endl;
}


void swapByAddress(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "here byaddres   a = " << *a << ", b = " << *b << endl;
}


void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "here byreferenceees :: a = " << a << ", b = " << b << endl;
}


///////////////////////////   class ///////////////////////////////////////////////////////

class ComplexNumber
{
   private : double real;
   private : double imaginary;


 public :


    void setReal()
    {
        cout << "Enter a valid real number  ";
        while (!isValidInput()) {
            cout << "Invalid input! Please enter a valid real number: ";
        }
        cin >> real;
    }


    double getReal()
    {
        return real;
    }

/*
   void setImaginary(double imaginaryData)
    {
        imaginary = imaginaryData;
    }
*/

    void setImaginary() {
        cout << "Enter a valid imaginary number  ";
        while (!isValidInput()) {
            cout << "Invalid input! Please enter a valid imaginary number: ";
        }
        cin >> imaginary;
    }


    double getImaginary()
    {
        return imaginary;
    }

    ComplexNumber Add(ComplexNumber c)
    {
        ComplexNumber x;
        x.real = this->real + c.real;
        x.imaginary = this->imaginary + c.imaginary;
        return x;
    }




   ComplexNumber Subb (ComplexNumber c)
    {
        ComplexNumber x;
        x.real = this->real - c.real;
        x.imaginary = this->imaginary - c.imaginary;
        return x;
    }


    void display()
    {
        if (real != 0)
        {
           cout<< "real Number" <<real << endl;
        }else
        {
         cout<<"error in Real Number";
        }
        if (imaginary > 0)
        {
            cout<<"Imaginary Number "<<imaginary<<endl;
        }else if(imaginary < 0)
        {
            cout<<"Imaginary Number " <<imaginary<<endl;
        }
    }


    bool isValidInput() {
        double num;
        cin >> num;
        if (cin.fail()) {
            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        return true;
    } // dah end of validation

}; // end of class


int main()
{

    ComplexNumber aziz;
   // aziz.setReal(10);
   // aziz.setImaginary(20);

    aziz.setReal();
    aziz.setImaginary();


    ComplexNumber gohar;
   // gohar.setReal(100);
  //  gohar.setImaginary(200);

    gohar.setReal();
    gohar.setImaginary();



    ComplexNumber sum = aziz.Add(gohar) ;
    ComplexNumber subb = aziz.Subb(gohar) ;

   // aziz.display();

    cout << "Sum: "<<endl;
    sum.display();


    cout << "minuss : " <<endl;
    subb.display();




    return 0;
}













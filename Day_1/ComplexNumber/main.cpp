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


    void setReal_2()
    {
        cout << "Enter a valid real number  ";
        cin >> real;
        ///this.real =
    }


void setReal()
{
    double temp; // Temporary variable to hold input.
    cout << "Enter a valid real number: ";
    cin>> temp;

    while (!isValidInput(temp))
    { // Use validation method.
        cout << "Invalid input! Please enter a valid real number: ";
    }
    real = temp; // Assign the valid input to the real variable.
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

    void setImaginary_2() {
       double temp ;
        cout << "Enter a valid imaginary number  ";
        cin>>temp ;
         imaginary;
    }

    void setImaginary() {
       double temp ;
        cout << "Enter a valid imaginary number  ";
        cin>>temp ;
        while (!isValidInput(temp))
        {
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




    void display_2()
    {

        if (real != 0)
        {
           cout<<real;
        }
        if (imaginary > 0)
        {
            cout<<"+"<<imaginary<<"i"<<endl;
        }else if(imaginary < 0)
        {
            cout<<imaginary<<"i"<<endl;
        }
    }




    bool isValidInput_2()
    {
        double num;
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        return true;
    } // dah end of validation


bool isValidInput(double &num) {
    cin >> num;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}






}; // end of class


int main()
{

    ComplexNumber aziz;
   // aziz.setReal(10);
   // aziz.setImaginary(20);

    aziz.setReal_2();
    aziz.setImaginary_2();


    ComplexNumber gohar;
   // gohar.setReal(100);
  //  gohar.setImaginary(200);

    gohar.setReal_2();
    gohar.setImaginary_2();



    ComplexNumber sum = aziz.Add(gohar) ;
    ComplexNumber subb = aziz.Subb(gohar) ;

   // aziz.display();

    cout << "Sum: "<<endl;
    sum.display_2();


    cout << "minuss : " <<endl;
    subb.display_2();



    return 0;
}













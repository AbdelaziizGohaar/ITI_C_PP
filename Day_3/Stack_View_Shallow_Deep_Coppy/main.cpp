#include <iostream>

using namespace std;

/////////////////////////////////////////////////// class stack


class Stack
{

private :
    int Top ;
    int Size;
    int *Items ;
    static int counter ;
public :

    Stack(int Size)
    {
        this->Size = Size ;
        Top = -1 ;
        Items = new int [Size] ;
       Stack::counter ++ ;
        cout<<"main Constractor" <<"counter ="<< counter <<endl;
    } // constructor end


///// copy constractor
    Stack(Stack &s)
    {
        this->Size = s.Size;
        this->Top = s.Top;
        this->Items = new int[s.Size];
        for (int i = 0; i <= s.Top; i++)
        {
            this->Items[i] = s.Items[i];
        }
        counter++;
        cout << "Copy Constructor counter = " << counter << endl;
    }


    ~Stack()
    {
        delete[] Items;
        counter -- ;
        cout<<"destractor called" <<"counter ="<< counter <<endl;
    } // end of destruc


    Stack& operator=(Stack& s)
    {
        delete[] this->Items;
        this->Size = s.Size;
        this->Top = s.Top;
        this->Items = new int[s.Size];
        for (int i = 0; i <= s.Top; i++)
        {
            this->Items[i] = s.Items[i];
        }
        counter++;
        cout << "Equal Operator = " << counter << endl;
        return *this ;
    }

    int push (int data)
    {
        if(Top == Size -1)
        {
            return 0 ;
        }
        Top ++ ;
        Items[Top] = data;
        cout<<"data pushed is "<< data<<endl;
        return 1 ;
    } // end of push



    int pop()
    {
        if(Top == -1)
        {
         //   throw runtime_error("Stack is empty!");
            cout<<"astck is empty"<<endl;
        }
        int data = Items[Top] ;
        Top --;
        return data ;
    } // end of pop


    int peek()
    {
        return Top ;
    } // end of peek


    int getSize()
    {
        return Top+1 ;
    } // end of peek

   static int getCounter() {
        return counter;
    }

    void display_2()
    {
        if (Top == -1)
        {
            throw runtime_error("Stack is empty!");
        }
        else
        {
            int data ;
            while(Top >= 0 )
            {
                data = Items[Top] ;
                cout<<"employee id "<< data <<endl;

                Top -- ;
            }
        }
    } // end of peek



    void display()
    {
        if (Top == -1)
        {
            throw runtime_error("Stack is empty!");
        }
        else
        {
            cout << "Stack contents (from top to bottom):\n";
            for (int i = Top; i >= 0; i--)
            {
                int data = Items[i];
                cout << "Employee Salary: " << data << endl;
                cout << "--------------------------\n";
            }
        }
    }

      void display_3 (){
        int dis =Top;
        if (dis == -1){
            cout<<"Stack is empty \n";
            return;
        }
        for(int i=dis; i>=0; i--){
            cout << Items[i] << " "<<endl;
        }


    }


};  //// Stack class end

//// byValue View

//void byValue_view(Stack s)
//{
//    try
//    {
//         while (s.pop()) {
//     cout << "Popped byvalue method int value is : " <<s.pop() << endl;
//    }
//
//    }
//    catch (const runtime_error& e)
//    {
//        cerr << "Error: " << e.what() << endl;
//    }
//}

//
//////  View

void viewByrefrence(Stack &s)
{
   while (s.pop()) {
       cout << "Popped byRefrence method int value is : " <<s.pop() << endl;
    }


}


////// Deep View

//void viewDeep(Stack s)
//{
//  try
//  {
//    while (s.pop())
//    {
//        cout << "Popped byConstructor method int value is : " <<s.pop() << endl;
//    }
//  }
//    catch (const runtime_error& e)
//    {
//        cerr << "Error: " << e.what() << endl;
//    }
//}
//


 int Stack::counter = 0 ;

int main()
{
    Stack myStack(20) ;
//
//    myStack.push(40);
//    myStack.push(30);
//    myStack.push(20);
//    myStack.push(10);
//    myStack.push(90);
//
//    myStack.display_3();
//       // Check the number of stack objects
//    cout << "Number of active Stack objects: " << Stack::getCounter() << endl;
//
//
// //   byValue_view(myStack);
//
//
//    viewByrefrence(myStack);
//    myStack.display_3();
//
//
////    viewDeep(myStack);

/////////////////////////////////////////////////rahmaaa

    myStack.push(90)?cout<<"Success Push \n" : cout<<"Failure push \n";
    myStack.push(30)?cout<<"Success Push \n" : cout<<"Failure push \n";
    myStack.push(20)?cout<<"Success Push \n" : cout<<"Failure push \n";
    myStack.push(70)?cout<<"Success Push \n" : cout<<"Failure push \n";
    myStack.push(50)?cout<<"Success Push \n" : cout<<"Failure push \n";
    myStack.push(10)?cout<<"Success Push \n" : cout<<"Failure push \n";

    //pop 50 70 20 30 90
    // Check the number of stack objects
   cout << "Number of active Stack objects: " << Stack::getCounter() << endl;


 //   byValue_view(myStack);
 //   byValue_view(myStack);


    viewByrefrence(myStack);
    viewByrefrence(myStack);

//    viewDeep(myStack);
//    viewDeep(myStack);


    return 0;
}







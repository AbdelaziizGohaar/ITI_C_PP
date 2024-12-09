#include <iostream>

using namespace std;


template <class azizType>
/////////////////////////////////////////////////// class stack
class Stack
{

private :
    int Top ;
    int Size;
    azizType *Items ;
public :

    Stack(int Size)
    {
        this->Size = Size ;
        Top = -1 ;
        Items = new azizType[Size] ;
    } // constructor end



    ~Stack()
    {
        delete[] Items;
    } // end of destruc




    azizType push (azizType data)
    {
        if(Top == Size -1)
        {
            return 0 ;
        }
        Top ++ ;
        Items[Top] = data;
        return 1 ;
    } // end of push



    azizType pop()
    {
        if(Top == -1)
        {
            throw runtime_error("Stack is empty!");
        }
        azizType data = Items[Top] ;
        Top --;
        return data ;
    } // end of pop


    azizType peek()
    {
        return Top ;
    } // end of peek


    azizType getSize()
    {
        return Top+1 ;
    } // end of peek



    void display_2()
    {
        if (Top == -1)
        {
            throw runtime_error("Stack is empty!");
        }
        else
        {
            azizType data ;
            while(Top >= 0 )
            {
                data = Items[Top] ;
                cout<<"data id "<< data <<endl;
                Top -- ;
            }
        }
    } // end of peek



     void display() {
        if (Top == -1) {
            throw runtime_error("Stack is empty!");
        } else {
            cout << "Stack contents (from top to bottom):\n";
            for (int i = Top; i >= 0; i--) {
                int data = Items[i];
                cout << "Data "<< i << "is"<< data << endl;
                cout << "--------------------------\n";
            }
        }
    }




};





int main()
{

    try
    {
        Stack <int> IntStack(10);
        cout<<" integer Stack"<<endl;

        IntStack.push(1);
        IntStack.push(2);

        IntStack.display();


        Stack <float> floatStack(5);
        cout<<" float Stack"<<endl;
        floatStack.push(1.5);
        floatStack.push(2.9);

        floatStack.display();

        cout << "Popped IntStack: " << IntStack.pop() << endl;
        cout << "Popped IntStack: " << IntStack.pop() << endl;
        cout << "Popped Employee: " << floatStack.pop() << endl;

               IntStack.display();
       cout << "intstack: " << endl;

       cout << "Float Stack: " << endl;
       floatStack.display_2();

    }
    catch (const runtime_error& e)
    {
        cerr << "Error: " << e.what() << endl;
    }



    return 0;
}

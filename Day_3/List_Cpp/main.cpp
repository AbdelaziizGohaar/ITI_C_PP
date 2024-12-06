#include <iostream>

using namespace std;

////////////////////////////////// Stack Class
 class Lists {

private :
          int Top ;
          int Size;
          int *Items;
          int last ;

public :

   Lists()
  {
    this->Size = Size ;
    Top = -1 ;
    last = Top ;
    Items = new int [Size] ;

   } // constructor end


   ~Lists() {
        delete[] Items;

    } // end of destruc




 int push (int data)
 {
   if(Top == Size -1){
     return 0 ;
   }
    Top ++ ;
    Items[Top] = data;
    cout<<"data pushed is "<< data<<endl;
    return 1 ;
 } // end of push



 int pop()
 {
   if(Top == -1){
  throw runtime_error("Lists is empty!");
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



 void display_2()
 {
    if (Top == -1)
    {
        throw runtime_error("List is empty!");
    }else
    {
      int data ;
       while(Top >= 0 )
       {
          data = Items[Top] ;
         cout<<"List id "<< data <<endl;

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
           cout << "Employee Salary: " << data << endl;
            cout << "--------------------------\n";
        }
    }
}

};  //// Stack class end



int main()
{



    return 0;
}

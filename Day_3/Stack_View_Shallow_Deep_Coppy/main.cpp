#include <iostream>

using namespace std;
/////////////////////////////////////////////////// class stack
 class Stack {

private :
          int Top ;
          int Size;
          Employee *Items ;
public :

   Stack(int Size)
  {
    this->Size = Size ;
    Top = -1 ;
    Items = new Employee[Size] ;
   } // constructor end



   ~Stack() {
        delete[] Items;
    } // end of destruc




 int push (Employee data)
 {
   if(Top == Size -1){
     return 0 ;
   }
    Top ++ ;
    Items[Top] = data;
    return 1 ;
 } // end of push



 string pop()
 {
   if(Top == -1){
  throw runtime_error("Stack is empty!");
   }
   string data = Items[Top].getName() ;
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
        throw runtime_error("Stack is empty!");
    }else
    {
      Employee data ;
       while(Top >= 0 )
       {
          data = Items[Top] ;
         cout<<"employee id "<< data.getId() <<endl;
         cout<<"employee name "<< data.getName() <<endl;
         cout<<"employee salary "<< data.getSalary() <<endl;

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
            Employee data = Items[i];
            cout << "Employee ID: " << data.getId() << endl;
            cout << "Employee Name: " << data.getName() << endl;
            cout << "Employee Salary: " << data.getSalary() << endl;
            cout << "--------------------------\n";
        }
    }
}

};  //// Stack class end


int main()
{



    return 0;
}

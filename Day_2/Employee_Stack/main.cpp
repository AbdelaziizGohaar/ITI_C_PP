#include <iostream>
#include <stdexcept>

#include "conio.h"
#define RIGHT 67
#define LEFT 68
#define UP 65
#define DOWN 66
#define ENTER 10
#define EXIT 113
#define EMP_SIZE 10
#define clear() printf("\033[H\033[J")


using namespace std;


 class Employee {
 private:
      int id ;
      string name;
      int salary ;

public:
 /////// Id Data
  void setId(int empId)
  {
    id = empId ;
  }

 int getId()
  {
   return id;
  }

//////// Name Data


  void setName(string empName)
  {
    name = empName ;
  }

 string getName()
  {
   return name;
  }

  //////// Salary Data
  void setSalary(int empSalary)
  {
    salary = empSalary ;
  }

 int getSalary()
  {
   return salary;
  }


 };



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

};



int main()
{

 Stack empStack(10);
/*
    Employee emp1, emp2;
    emp1.setId(1);
    emp1.setName("Alice");
    emp1.setSalary(5000);

    emp2.setId(2);
    emp2.setName("Bob");
    emp2.setSalary(6000);

    // Push employees to the stack
    empStack.push(emp1);
    empStack.push(emp2);

    // Pop employees from the stack
    try {
        cout << "Popped Employee: " << empStack.pop() << endl; // Outputs: Bob
        cout << "Popped Employee: " << empStack.pop() << endl; // Outputs: Alice
        cout << "Popped Employee: " << empStack.pop() << endl; // Throws exception
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
*/



    return 0;
}













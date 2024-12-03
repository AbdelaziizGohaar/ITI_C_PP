#include <iostream>

using namespace std;

//////////////////////////////////// class emp
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



 void display()
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


};





int main()
{

 Stack empStack(10);

    Employee emp1;
    Employee  emp2;

    emp1.setId(1) ;
    emp1.setName("Alice")  ;
    emp1.setSalary(5000) ;

    emp2.setId(2);
    emp2.setName("Bob") ;
    emp2.setSalary(6000) ;


    empStack.push(emp1);
    empStack.push(emp2);

    try {
        cout << "Popped Employee: " << empStack.pop() << endl;
        cout << "Popped Employee: " << empStack.pop() << endl;
        cout << "Popped Employee: " << empStack.pop() << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }



    return 0;
}

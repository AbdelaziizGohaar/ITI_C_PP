#include <iostream>
#include <stdexcept>
#include <string>


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


 void pushEmp_void( Stack &empStack );
 void showMenuAfterExitNew() ;
 void popEmp_void(Stack &empStack) ;
 void Display_void(Stack &empStack) ;


int main()
{
 int input;
 // int index = 0;
 int currentPos = 5;
 int EntryPos = 0;
// struct Employee emp[EMP_SIZE]={0};
 int currentEmpIndex = 0;
 int storedIds [EMP_SIZE] = {0};
 int idCounts = 0 ;

 int stackSize ;


 cout<< "Enter the size of Stack ";
 cin>> stackSize ;

 Stack empStack(stackSize);

 getch();
 clear();

///////////////////////////////////////////////////////////////////// Menu Code Begans


    gotoxy(25, 5); // Move cursor to column 10, row 5
    textcolor(BLUE);
    printf("Push");
   textcolor(WHITE);

    gotoxy(25, 10); // Move cursor to column 20, row 8
    printf("Pop");

    gotoxy(25, 15); // Move cursor to column 0, row 10
    printf("Exit");

    gotoxy(25, 20); // Move cursor to column 0, row 10
    printf("Display");

    while(1){


     char ch =0 ;
    ch = getch();

     if(ch ==27 ){
       ch = getch();
       ch = getch();

       //// enter switch here ya aziz

        switch (ch) {
        case DOWN: {
            // clear();
			// print("%d\n")
            if(currentPos == 5){

            gotoxy(25, 5);
           // setTextColor(stdout, TC_WHITE);
           printf("Push");

            gotoxy(25, 10);
           // setTextColor(stdout, TC_BLUE);
            textcolor(BLUE);
            printf("Pop");
             textcolor(WHITE);

            gotoxy(25, 15);
            //setTextColor(stdout, TC_WHITE);
            printf("Exit");

            gotoxy(25, 20); // Move cursor to column 0, row 10
            printf("Display");

            currentPos = 10;
            int EntryPos = 0;

            } else if(currentPos == 10){

            gotoxy(25, 5);
           // setTextColor(stdout, TC_WHITE);
           printf("Push");

            gotoxy(25, 10);
           // setTextColor(stdout, TC_WHITE);
            printf("Pop");


            gotoxy(25, 15);
            //setTextColor(stdout, TC_BLUE);
            textcolor(BLUE);
            printf("Exit");

            textcolor(WHITE);
            gotoxy(25, 20); // Move cursor to column 0, row 10
            printf("Display");


             currentPos = 15;
            }else if(currentPos == 15){

            gotoxy(25, 5);
           // setTextColor(stdout, TC_WHITE);
           printf("Push");

            gotoxy(25, 10);
           // setTextColor(stdout, TC_WHITE);
            printf("Pop");


            gotoxy(25, 15);
            //setTextColor(stdout, TC_BLUE);
            textcolor(WHITE);
            printf("Exit");

            textcolor(BLUE);
            gotoxy(25, 20); // Move cursor to column 0, row 10
            printf("Display");


             currentPos = 20;
            }
            else if(currentPos = 20){

         //   printf("This is the Last menuItem press another Key");

            }
            break;
        }
//      case UP: printf("\n Up arrow : \n"); break;
         case UP: {
            clear();

         if(currentPos == 20){

            gotoxy(25, 5);
          textcolor(WHITE);
           printf("Push");

            gotoxy(25, 10);
            textcolor(WHITE);
            printf("Pop");


            gotoxy(25, 15);
            textcolor(BLUE);
            printf("Exit");

            textcolor(WHITE);
            gotoxy(25, 20); // Move cursor to column 0, row 10
            printf("Display");


            currentPos = 15;

            } else
            if(currentPos == 15){

            gotoxy(25, 5);
          textcolor(WHITE);
           printf("Push");

            gotoxy(25, 10);
            textcolor(BLUE);
            printf("Pop");


            gotoxy(25, 15);
            textcolor(WHITE);
            printf("Exit");


            textcolor(WHITE);
            gotoxy(25, 20); // Move cursor to column 0, row 10
            printf("Display");


            currentPos = 10;

            } else if(currentPos == 10){

            gotoxy(25, 5);
           textcolor(BLUE);
           printf("Push");

            gotoxy(25, 10);
            textcolor(WHITE);
            printf("Pop");


            gotoxy(25, 15);
         textcolor(WHITE);
            printf("Exit");


            textcolor(WHITE);
            gotoxy(25, 20); // Move cursor to column 0, row 10
            printf("Display");


             currentPos = 5;
            }else if(currentPos == 5){

                gotoxy(25, 5);
           textcolor(BLUE);
           printf("Push");

            gotoxy(25, 10);
            textcolor(WHITE);
            printf("Pop");


            gotoxy(25, 15);
         textcolor(WHITE);
            printf("Exit");


            textcolor(WHITE);
            gotoxy(25, 20); // Move cursor to column 0, row 10
            printf("Display");


             currentPos = 5;
         //   printf("This is the first menuItem press another Key");

            }
            break;
        }
        default:  printf("\n  \n");
    }

}

   if(ch == ENTER || ch == EXIT  )
   {

         switch (ch) {
           case ENTER: {
            clear();

          if(currentPos == 20)  ///////////////////////////////////////////////////////////// Display Method
          {
              Display_void(empStack) ;

           EntryPos = 1;
          }else
            if(currentPos == 15){ /// EXIT
              exit(0);
             EntryPos = 1;
            } else if(currentPos == 10){ /// pop

           popEmp_void(empStack) ;  ////// pop

             EntryPos = 1;

            }else if(currentPos == 5){   /// New

             EntryPos = 1;

              pushEmp_void(empStack) ; ////////////////////////////////////////////////  method of enter employees /////////////////////////////////////////////////////////////////

             // void pushEmp_void(Stack &empStack)

             clear();

             showMenuAfterExitNew();  /// show meues again
            }

           break;
        }
           case EXIT: {
            clear();
      if(EntryPos == 1){

             gotoxy(25, 5); // Move cursor to column 10, row 5
             textcolor(BLUE);
             printf("Push");

            textcolor(WHITE);

            gotoxy(25, 10); // Move cursor to column 20, row 8
            printf("Pop");

            gotoxy(25, 15); // Move cursor to column 0, row 10
            printf("Exit");

            gotoxy(25, 20); // Move cursor to column 0, row 10
            printf("Display");


             EntryPos = 0 ;
            } else if(currentPos == 0){
             // printf("we already in main Screen");
                   // Close the terminal
                 exit(0);
            }
            break;
        }
        default:  printf("\n  \n");
}

        }


}
//////



//////////////////////////////////////////////////////////////////// Menue Code Ends
    return 0;
}




///////////////////////////////////////////// Here enter new Emp Data


 void pushEmp_void(Stack &empStack) {
    char decision = 'y';


    while (decision == 'y')
    {
        clear(); // Clear the screen if required.
        printf(" \n Do you want to enter a new user? (y/n): \n");

        decision = getch();

        if (decision == 'y' || decision == 'Y')
        {
           Employee e ;
           int eId ;
           string ename ;
           int eSal;


           cout<< "Please enter the Employee ID "<< endl;
           cin>> eId;
            e.setId(eId);

           cout<< "Please enter the Employee Name"<< endl;
           cin>> ename;
            e.setName(ename);

           cout<< "Please enter the Employee Salary"<< endl;
           cin>> eSal;
            e.setSalary(eSal);

            empStack.push(e);

           // getch();

         }else
             if (decision == 'n' || decision == 'N')
            {
               decision = 'n'; // Exit the loop since no more entries can be made.
            } else
            {
                printf("Invalid . Please answer with 'y' or 'n'.\n");
            }
            //getch();
      }
}


/////////////////////////////////////////// End of New Emp Data


//////////////////////////////////////////////////////////


void showMenuAfterExitNew()
 {

    gotoxy(25, 5); // Move cursor new
    textcolor(BLUE);
    printf("Push");
   textcolor(WHITE);

    gotoxy(25, 10); // Move cursor Dis
    printf("Pop");

    gotoxy(25, 15); // Move cursor to exxit
    printf("Exit");

    gotoxy(25, 20); // Move cursor to column 0, row 10
    printf("Display");


 }

////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////begin pop


void popEmp_void(Stack &empStack)
{

   string delEmp ;

   try{
      delEmp = empStack.pop() ;
     cout<<"Delete User is "<<delEmp <<endl;

   }catch(const std::exception& e)
   {
     cout<<"empty Stack  ";
   }

}

////////////////////////////////////////////////////////////// end pop

 void Display_void(Stack &empStack)
{
 try
 {
    empStack.display();
 }catch (const std::exception& e)
 {
   cout<<"The Stack is empty"<<endl;

 }


}







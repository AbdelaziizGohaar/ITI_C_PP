#include <iostream>

using namespace std;


template<class azizType>
////////////////////////////////// Stack Class
 class Lists {

private :
          int Size;
          azizType *Items;

public :

   Lists()
  {
    Size = 0 ;
    Items = NULL ;

   } // constructor end


   ~Lists() {
        delete[] Items;

    } // end of destruc




 azizType push (azizType data)
 {

   int *arr = new int [Size +1] ;

   for(int i =0 ; i < Size ;i++)
   {
     arr[i] = Items[i];
   }

   arr[Size] = data ;

   delete[] Items ;
   Items = arr;
   Size ++;

    return 1 ;
 } // end of push



 azizType pop()
 {
   if(Size == 0){
//  throw runtime_error("Lists is empty!");
   cout<<"List is Empty" <<endl;
   }
   int data = Items[Size] ;
   Size --;
    return data ;
 } // end of pop


 azizType peek()
 {
    return Size ;
 } // end of peek


 azizType getSize()
 {
    return Size ;
 } // end of GetSize


//
// void display_2()
// {
//    if (Top == -1)
//    {
//        throw runtime_error("List is empty!");
//    }else
//    {
//      int data ;
//       while(Top >= 0 )
//       {
//          data = Items[Top] ;
//         cout<<"List id "<< data <<endl;
//
//          Top -- ;
//       }
//    }
// } // end of dis
//



  void display_3 (){
       int t = Size-1 ;
        if (t == -1){
            cout<<"List is empty "<<endl;
            return;
        }
        for(int i=t; i>=0; i--){
            cout << Items[i] << " "<<endl;
        }

    }






};  //// Stack class end



int main()
{
         Lists <int> Goo;
        cout<<" integer list"<<endl;


 //  Lists Goo ;

    Goo.push(10);
    Goo.push(20);
    Goo.push(30);
    Goo.push(40);
    Goo.push(50);

    cout<<"Display of data after push" <<endl;

  Goo.display_3();

  cout<<"lenght of GOO is = "<< Goo.getSize() <<endl;

    Goo.pop();
    Goo.pop();

    cout<<"Display of data after pop " <<endl;
    Goo.display_3();

    cout<<"lenght of GOO is  = "<< Goo.getSize() <<endl;


    return 0;
}

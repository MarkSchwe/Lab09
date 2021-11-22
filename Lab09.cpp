#include <iostream>

#include <iostream>
using namespace std;

class dynamicClass
{

   public:
         // constructor
         dynamicClass(int m1, int m2);
         // copy constructor
         dynamicClass(const dynamicClass& obj);
         // destructor
         ~dynamicClass();
         // assignment operator
         dynamicClass& operator= (const dynamicClass& obj);
         //print
         void print();

   private:
         // data of int and a pointer to data of int
         int member1;
         int *member2;
};

// use constructor initialization list to give member1 the
// value m1 and allocate dynamic memory associated with member2
// and initialize it to with the value m2

dynamicClass::dynamicClass(int m1, int m2): member1(m1)
{
    member2 = new int(m2);
}


// initialize new object to have the
// same data as obj. use constructor initialization
// list to give member1 the value member1 of obj and
// allocate dynamic memory associated with member2 and
// initialize it with the value pointed by member2 of obj.

dynamicClass::dynamicClass(const dynamicClass& obj): member1(obj.member1)
{
member2 = new int(*obj.member2);
}


// destructor. deallocates the dynamic memory allocated
// by the constructor and display “Destructor is called
//

dynamicClass::~dynamicClass()
{
    
cout << "Destructor is called\n";
member2 = nullptr;
delete member2;
}


// overloaded assignment operator=. returns a reference to
// current object.
// copy static data member from obj to the current object
// contents of dynamic memory must be same as that of obj

dynamicClass& dynamicClass::operator=(const dynamicClass& obj)              
{
member1 = obj.member1;
member2 = new int(*obj.member2);
return *this;          
}


void dynamicClass::print(){
    cout << member1 << endl;
    cout << *member2 << endl;
}



int main(){
dynamicClass a(1,2);
a.print();
dynamicClass b(3,4);
b.print();
a = b;
a.print();
b.print();
dynamicClass c(b);
c.print();

return 0;
}
//Output:


/*1
2
3
4
3
4
3
4
3
4
Destructor is called
Destructor is called
Destructor is called
*/

#include <iostream>


#include "dynClass.h"


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

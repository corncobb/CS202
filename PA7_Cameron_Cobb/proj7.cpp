//Cameron Cobb
//CS202
//4/3/2019


#include <iostream>
#include "MyString.h"


//Basically just copied and pasted from webcampus
int main()
{
    MyString ms_default;
    std::cout << ms_default << std::endl;

    MyString ms_parametrized("MyString parametrized constructor!");
    std::cout << ms_parametrized << std::endl;

    MyString ms_copy(ms_parametrized);
    std::cout << ms_copy << std::endl;

    MyString* ms_Pt = new MyString("MyString to be deleted...");
    delete ms_Pt;
    ms_Pt = NULL; 

    MyString ms_size_length("Size and length test");
    std::cout << ms_size_length.size() << std::endl;
    std::cout << ms_size_length.length() << std::endl;

    MyString ms_toCstring("C-String equivalent successfully obtained!");
    std::cout << ms_toCstring.c_str() << std::endl;

    MyString ms_same1("The same"), ms_same2("The same");
    if (ms_same1 == ms_same2) 
        std::cout << "Same success" << std::endl;

    MyString ms_different("The same (NOT)");
    if (!(ms_same1 == ms_different))
        std::cout << "Different success" << std::endl;

    MyString ms_assign("Before assignment");
    std::cout << ms_assign << std::endl;
    ms_assign = MyString("After performing assignment");
    std::cout << ms_assign << std::endl;

    MyString ms_append1("The first part");
    MyString ms_append2(" and the second");
    MyString ms_concat = ms_append1 + ms_append2;
    std::cout << ms_concat << std::endl;

    MyString ms_access("Access successful (NOT)");
    ms_access[17] = 0;
    std::cout << ms_access << std::endl;

    return 0;
}
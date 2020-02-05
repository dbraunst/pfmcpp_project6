/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

 Pointers

 Please look at the screenshot in the files to see what happens if you copy this assignment into Xcode
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 steps:
 
 0) press the Compile, link and run... button and work your way through all of the error messages.
         you can click on them to be taken to the appropriate line number.
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses bigger's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    T(double v, const char* nameIn) : value(v), name(nameIn) {}   //1
    double value;//2
    std::string name;//3
};

struct Comparer                                //4
{
    T* compare(T* a, T* b) //5
    {
        if (a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float firstVal { 0 }, secondVal { 0 };
    float shrinkDistance(float* newVal)      //12
    {
        if(newVal != nullptr) firstVal = *newVal;
        
        while( std::abs(secondVal - firstVal) > 0.001f )
        {
            //write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
            if(secondVal > firstVal)
            {
                secondVal -= std::abs(secondVal - firstVal) / 2;
            }
            else 
            {
                secondVal += std::abs(secondVal - firstVal) / 2;
            }
        }
        
        return firstVal * secondVal;
    }
};

struct U2
{
    static float shrinkDistance(U* that, float* newVal )        //10
    {
        if (newVal != nullptr && that != nullptr)
        {
            std::cout << "U's firstVal value: " << that->firstVal << std::endl;
            that->firstVal = *newVal;
            std::cout << "U's firstVal updated value: " << that->firstVal << std::endl;
            while( std::abs(that->secondVal - that->firstVal) > 0.001f )
            {
                /*
                write something that makes the distance between that->secondVal and that->firstVal get smaller
                */
                if(that->secondVal > that->firstVal)
                {
                    that->secondVal -= std::abs(that->secondVal - that->firstVal) / 2;
                }
                else 
                {
                    that->secondVal += std::abs(that->secondVal - that->firstVal) / 2;
                }
            }
            std::cout << "U's secondVal updated value: " << that->secondVal << std::endl;
            return that->secondVal * that->firstVal;
        }
        return 0.0;
    }
};
        
int main()
{
    T first(10.0,"first");                                             //6
    T second(12.0,"second");                                             //6
    
    Comparer f;                                            //7
    
    auto* smaller = f.compare(&first,&second);                              //8
    if (smaller!= nullptr){
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }

    U third;
    float updatedValue = 5.f;
    std::cout << "[static func] third's multiplied values: " << U2::shrinkDistance(&third, &updatedValue) << std::endl;                  //11
    
    U fourth;
    std::cout << "[member func] fourth's multiplied values: " << fourth.shrinkDistance( &updatedValue ) << std::endl;
}

/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or const reference types ** WHERE POSSIBLE **
    hint: There is no reference equivalent to nullptr.  
    So don't try to convert nullptr, if nullptr is being returned anywhere
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
    if (smaller!= nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }

    U third;
    float updatedValue = 5.f;
    std::cout << "[static func] third's multiplied values: " << U2::shrinkDistance(&third, &updatedValue) << std::endl;                  //11
    
    U fourth;
    std::cout << "[member func] fourth's multiplied values: " << fourth.shrinkDistance( &updatedValue ) << std::endl;
}

/****************************
[file name]--------------
function.h
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-11-06 
[last edit]---
2021-11-06 
****************************/ 


#ifndef FUNCTION_H
#define FUNCTION_H
using namespace std;

struct my_out
{
    my_out(std::ostream& out1, 
           std::ostream& out2) : out1_(out1), 
                                 out2_(out2){}

    std::ostream& out1_;
    std::ostream& out2_;

};

// operator<<() function for most data types.
template <typename T>
my_out& operator<<(my_out& mo, T const& t)
{
    mo.out1_ << t;
    mo.out2_ << t;
    return mo;
}

// Allow for std::endl to be used with a my_out
my_out& operator<<(my_out& mo, std::ostream&(*f)(std::ostream&))
{
    mo.out1_ << f;
    mo.out2_ << f;
    return mo;
}

#endif

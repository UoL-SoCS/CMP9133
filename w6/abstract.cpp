#include <iostream>

struct Printable
{ // Saving space. Should be a class.​

    virtual void Print() const = 0;
};

struct A : public Printable
{

    void Print() const override { std::cout << "A" << std::endl; }
};


    struct B : public Printable
{
    void Print() const override
    {
        std::cout << "B" << std::endl;
    }
    
};

void Print(const Printable &var)
{
    var.Print();
}

    int main(){
    

        Print(A());

        Print(B());

        return 0;
}
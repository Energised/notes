/*
 * custom_exception.cpp
 * @author Dan Woolsey
 *
 * writing custom exceptions with inheritance example
 */

#include <iostream>

class my_coordinate_exception : public std::exception
{
private:
    int x, y;
    std::string err_msg;
public:
    my_coordinate_exception(int _x, int _y)
    {
        x = _x;
        y = _y;
        err_msg = "my_coordinate_exception : " + std::to_string(y) + "x" + std::to_string(x);
    }

    virtual const char* what() const throw()
    {
        // ok so fuck joss' code, screw building a streamstring
        // just store the error message when the exception is instantiated
        // and then return it as a cstring
        // doing it his way means the string data is lost when the catch
        // block tries to output it, so no value is given
        // see: https://stackoverflow.com/questions/44990407/c-custom-exception-message-not-displaying
        // ^^ explanation is good, but code wouldn't compile for me so did it this way
        return err_msg.c_str();
    }

    int get_x() const {return x;}
    int get_y() const {return y;}
};

void func()
{
    // do something to cause an error
    for(int y=0; y<5; y++)
    {
        for(int x=0; x<5; x++)
        {
            std::cout << y << " x " << x << std::endl;
            if(y == 4 & x == 1)
            {
                throw my_coordinate_exception(x, y);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    try
    {
        func();
    }
    catch(const std::exception &ex)
    {
        std::cerr << "caught in main() : ";
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}

/*
 * process_file.cpp
 * @author Dan Woolsey
 *
 * Process file with C-style int exceptions example
 */

#include <iostream>
#include <exception>

void process_file()
{
    FILE *fp = fopen("some_data.txt", "r");
    // errno is a global int var which is set
    // if something goes wrong in C style functions (like fopen)

    if(errno > 0) throw errno;
    // file has not been opened if this happens
    // no clean up needed
    // errno = 2 when file not found

    // do shit

    //cleanup
    fclose(fp);
}

int main(int argc, char* argv[])
{
    try
    {
        process_file();
    }
    catch(const int &err_code)
    {
        std::cerr << err_code << std::endl;
    }

    return 0;
}

/*
 * FileTesting.cpp
 * @author Dan Woolsey
 *
 * Implementation of FileReadWriter using FileWriter, FileReader and FileHandle
 */

#include <iostream>
using namespace std;

#include "FileReadWriter.h"

int main(int argc, char *argv[])
{
    //FileHandle x("tmp.txt", "r+"); // error: no publically visible constructor

    FileReader x("tmp_read.txt"); // implicitly uses "r" mode

    std::string tmp = x.read(30);
    std::cout << "tmp = \"" << tmp << "\"" << std::endl;

    FileWriter y("tmp_write"); // implicitly uses "w" mode

    y.write("Message being written to file...");

    FileReadWriter z("tmp_read_write.txt"); // implicitly uses "r+" mode

    std::string tmp_rw = z.read(12);
    std::cout << "tmp= \"" << tmp_rw << "\"" << std::endl;

    z.write("Message being written to file...");

    return 0;
}

/*
 * FileHandle.h
 * @author Dan Woolsey
 *
 * Header file and implementation for FileHandle
 */

#ifndef __FILE_HANDLE__
#define __FILE_HANDLE__

#include <cstdio>
//#include <stdio.h> // required for fopen_s

class FileHandle
{
protected:
    FILE *file_ptr;
    FileHandle(const std::string &_name, const std::string &_mode);
public:
    virtual ~FileHandle();
};

FileHandle::FileHandle(const std::string &_name, const std::string &_mode) : file_ptr(nullptr)
{
    std::cout << "Constructor - FileHandle" << std::endl;
    file_ptr = fopen(_name.c_str(), _mode.c_str()); // fopen_s does not exist in linux, microsoft only
    // dont use fopen_s bc microsoft = shit
}

FileHandle::~FileHandle()
{
    std::cout << "Destructor - FileHandle" << std::endl;
    if(file_ptr != nullptr)
    {
        fclose(file_ptr);
        file_ptr = nullptr;
    }
}

#endif

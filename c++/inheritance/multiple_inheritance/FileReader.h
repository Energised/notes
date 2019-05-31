/*
 * FileReader.h
 * @author Dan Woolsey
 *
 * Header file and implementation of FileReader : FileHandle
 */

#ifndef __FILE_READER__
#define __FILE_READER__

#include "FileHandle.h"

class FileReader : virtual public FileHandle
{
public:
    FileReader(const std::string &_name);
    virtual ~FileReader();

    virtual std::string read(const unsigned int num_bytes);
};

FileReader::FileReader(const std::string &_name) : FileHandle(_name, "r")
{
    std::cout << "Constructor - FileReader" << std::endl;
}

FileReader::~FileReader()
{
    std::cout << "Destructor - FileReader" << std::endl;
}

std::string FileReader::read(const unsigned int num_bytes)
{
    std::cout << "Read - FileReader" << std::endl;
    std::string str(num_bytes, '\0');
    fread(&(str[0]), sizeof(char), num_bytes, file_ptr);
    return str;
}

#endif

/*
 * FileWriter.h
 * @author Dan Woolsey
 *
 * Header file and implementation of FileWriter : FileHandle
 */

#ifndef __FILE_WRITER__
#define __FILE_WRITER__

#include "FileHandle.h"

class FileWriter : virtual public FileHandle
{
public:
    FileWriter(const std::string &_name);
    virtual ~FileWriter();

    virtual void write(const std::string &str);
};

FileWriter::FileWriter(const std::string &_name) : FileHandle(_name, "w")
{
    std::cout << "Constructor - FileWriter" << std::endl;
}

FileWriter::~FileWriter()
{
    std::cout << "Destructor - FileWriter" << std::endl;
}

void FileWriter::write(const std::string &str)
{
    std::cout << "Write - FileWriter" << std::endl;
    // apparently really bad code below...
    fseek(file_ptr, 0, SEEK_END);
    fwrite(&(str[0]), sizeof(char), str.size(), file_ptr);
    fflush(file_ptr);
}

#endif

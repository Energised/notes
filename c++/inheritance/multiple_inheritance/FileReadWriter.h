/*
 * FileReadWriter.h
 * @author Dan Woolsey
 *
 * Header file for FileReadWriter : FileReader : FileWriter
 */

#ifndef __FILE_READ_WRITER__
#define __FILE_READ_WRITER__

#include "FileReader.h"
#include "FileWriter.h"

class FileReadWriter : virtual public FileReader, virtual public FileWriter
{
public:
    FileReadWriter(const std::string &_name);
    virtual ~FileReadWriter();
};

FileReadWriter::FileReadWriter(const std::string &_name)
    : FileReader(_name), FileWriter(_name), FileHandle(_name, "r+")
{
    std::cout << "Constructor - FileReadWriter" << std::endl;
}

FileReadWriter::~FileReadWriter()
{
    std::cout << "Destructor - FileReadWriter" << std::endl;
}

#endif

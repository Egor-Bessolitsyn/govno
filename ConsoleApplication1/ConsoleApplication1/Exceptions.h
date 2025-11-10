
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class FileException : public std::runtime_error {
public:
    FileException(const std::string& msg): std::runtime_error(msg) {}
};

class IndexException : public std::out_of_range {
public:
    IndexException(const std::string& msg): std::out_of_range(msg) {}
};

#endif

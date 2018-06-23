#ifndef MULTIPLEPOINTSEXCEPTIONS_H
#define MULTIPLEPOINTSEXCEPTIONS_H

#include <vector>
#include <exception>
#include <string>

struct Point;

class MultiplePointsException : public std::exception
{
    std::string result;
public:
    MultiplePointsException(const std::vector<Point *> &v);
    std::vector<Point *> v;

    const char* what() const noexcept;
};

#endif // MULTIPLEPOINTSEXCEPTIONS_H

#include "multiplepointsexceptions.h"
#include "points.h"
#include <string>
#include <sstream>

using namespace std;


MultiplePointsException::MultiplePointsException(const std::vector<Point *> &v) {
    this->v = v;

    stringstream ss;
    ss << "Points:\n";
    for(Point *p : v)
        ss << *p << endl;
    ss << "are in the same distance from the center.\n";

    result = ss.str();
}

const char* MultiplePointsException::what() const noexcept {
    return result.c_str();
}

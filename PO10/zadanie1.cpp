#include <iostream>

using namespace std;

struct vec3 {
    float x, y, z;
};

vec3 operator+(const vec3 &a, const vec3 &b) {
    return vec3{a.x + b.x, a.y + b.y, a.z + b.z};
}

vec3 & operator+=(vec3 &a, const vec3 &b) {
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

vec3 operator-(const vec3 &a) {
    return vec3{-a.x, -a.y, -a.z};
}

vec3 operator-(const vec3 &a, const vec3 &b) {
    return a+-b;
}

vec3 & operator-=(vec3 &a, const vec3 &b) {
    a=a-b;
    return a;
}

vec3 operator*(const vec3 &a, const vec3 &b) {
    return vec3{ a.y*b.z - a.z*b.y,   a.z*b.x - a.x*b.z,   a.x*b.y - a.y*b.x };
}

vec3 operator*(const vec3 &a, const float &f) {
    return {a.x * f, a.y * f, a.z * f};
}

int main() {
    vec3 v1 = {1,2,3};
    v1 = 100 * v1;//vec3{-1,0,0};
    cout << v1.x << " " << v1.y << " " << v1.z << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

struct Vector{
    std::vector<double> data;
};

void print(const Vector& v){
    for (double value : v.data){
        std::cout << value << '\n' ;
    }

}

void scale(Vector& v, double c){
    for (double& value : v.data) {
        value = value * c;
    }
}

double dot(const Vector& v, const Vector& w){

    double total = 0;

    for (int i=0; i<3; i++){
        total += v.data[i]*w.data[i];
    }
    return total;
}

Vector add(const Vector& v, const Vector& w){
    Vector result = v;

    for (int i=0; i<3; i++){
        result.data[i] = v.data[i]+w.data[i];
    }
    return result;

}

void normalize(Vector& v){
    double size = std::sqrt(dot(v,v));

    for (double& value : v.data){
        value /= size;
    }
}


int main(){
    Vector a;
    a.data = {1,2,3};

    // scale(a, 2);
    std::cout << dot(a,a) << '\n';
    normalize(a);
    print(a);

    // std::cout << a.data[1];


    return 0;
}
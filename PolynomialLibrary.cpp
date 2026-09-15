#include <iostream>


struct Polynomial{
    int degree = 0;
    double* coefficients; 
};

Polynomial createPolynomial(int degree, double coeffs[]);
void destroyPolynomial(Polynomial& p);
void setCoefficient(const Polynomial& p, int power, double coeff);
double getCoefficient(const Polynomial& p, int power);
void printPolynomial(const Polynomial& p);

int main(){
    double coeffs[] = {1,2,3,4};

    Polynomial p = createPolynomial(3, coeffs);
    std::cout << "Polynomial p has degree: "<< p.degree << '\n';
    std::cout << "Polynomial p has coefficients" << '\n';
    for (int i = 0; i <= p.degree; i++){
        std::cout << p.coefficients[i] << ' ';
    }

    printPolynomial(p);

    destroyPolynomial(p);

    return 0;
}

Polynomial createPolynomial(int degree, double coeffs[]){
    Polynomial p;

    p.degree = degree;
    p.coefficients = new double[degree+1];

    for (int i = 0; i <= degree; i++){
        p.coefficients[i] = coeffs[i];
    }

    return p;
}

void setCoefficient(Polynomial& p, int power, double coeff){
    p.coefficients[power] = coeff;
}

double getCoefficient(const Polynomial& p, int power){
    return p.coefficients[power];

}

void printPolynomial(const Polynomial& p){

    for (int i = p.degree; i <= 0; i--){
        std::cout << p.coefficients[i] << "x^" << i;
    }
}

void destroyPolynomial(Polynomial& p){
    delete[] p.coefficients;
}
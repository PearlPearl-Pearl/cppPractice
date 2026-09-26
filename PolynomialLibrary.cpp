#include <iostream>
#include <cmath>
#include <algorithm>



struct Polynomial{
    int degree = 0;
    double* coefficients; 
};

Polynomial createPolynomial(int degree, double coeffs[]);
Polynomial addPolynomials(const Polynomial& p, const Polynomial& q);
Polynomial substractPolynomials(const Polynomial& p, Polynomial& q);
Polynomial multiplyPolynomials(const Polynomial& p, const Polynomial& q);
Polynomial differentiatePolynomial(const Polynomial& p);
void destroyPolynomial(Polynomial& p);
void setCoefficient(Polynomial& p, int power, double coeff);
double getCoefficient(const Polynomial& p, int power);
void printPolynomial(const Polynomial& p);
void scalePolynomial(Polynomial& p);
double evaluatePolynomial(const Polynomial& p, double value);


int main(){
    // double coeffsp[] = {1,1};
    // double coeffsq[] = {1, 0, 1};

    // Polynomial p = createPolynomial(1, coeffsp);
    // Polynomial q = createPolynomial(2, coeffsq);
    // Polynomial z = addPolynomials(p,q);
    // Polynomial prod = multiplyPolynomials(p,p);

    // printPolynomial(p);
    // std::cout << '\n';
    // printPolynomial(q);
    // std::cout << '\n';
    // printPolynomial(z);
    // std::cout << '\n';
    // printPolynomial(prod);

    double coeffsp[] = {2, 3, 5};  // 2x² + 3x + 5
    double coeffsq[] = {7, 11};    // 7x + 11

    Polynomial p = createPolynomial(2, coeffsp);
    Polynomial q = createPolynomial(1, coeffsq);

    Polynomial result = multiplyPolynomials(p, q);

    Polynomial k = differentiatePolynomial(p);

    printPolynomial(k);

    destroyPolynomial(p);
    destroyPolynomial(q);
    // destroyPolynomial(z);
    // destroyPolynomial(prod);
    destroyPolynomial(result);
    destroyPolynomial(k);

    return 0;
}

Polynomial createPolynomial(int degree, double coeffs[]){
    Polynomial p;

    p.degree = degree;
    p.coefficients = new double[degree+1];

    for (int i = degree; i >= 0; i--){
        p.coefficients[i] = coeffs[degree-i];
    }

    return p;
}

void setCoefficient(Polynomial& p, int power, double coeff){
    p.coefficients[power] = coeff;
}

double getCoefficient(const Polynomial& p, int power){
    return p.coefficients[power];
}

double evaluatePolynomial(const Polynomial& p, double value){
    double total = 0;
    int degree = p.degree;

    for (int i = degree; i >= 0; i--){
        // std::cout << "This is the coefficient for degree "<< i<< ','<< p.coefficients[degree-i] << '\n';
        // std::cout << "This is the power for degree "<< i<< ',' << pow(value, i) << '\n';
        total += p.coefficients[degree-i]*pow(value, i);
    }

    return total;
}

Polynomial addPolynomials(const Polynomial& p, const Polynomial& q){
    int maxdegree = std::max(p.degree, q.degree);
    int mindegree = std::min(p.degree, q.degree);

    double coeffs[maxdegree+1] = {0};

    for (int i=0; i<=mindegree; i++){
        coeffs[maxdegree-i] = p.coefficients[i] + q.coefficients[i];
    }
    if (maxdegree == p.degree){
        for (int i=mindegree+1; i<=maxdegree; i++){
            coeffs[maxdegree-i] = p.coefficients[i];
    }
    }
    else if (maxdegree == q.degree){
        for (int i=mindegree+1; i<=maxdegree; i++){
            coeffs[maxdegree-i] = q.coefficients[i];
    }
    }

    Polynomial newpolym = createPolynomial(maxdegree, coeffs);

    return newpolym;
}

Polynomial substractPolynomials(const Polynomial& p, const Polynomial& q){
    int qdegree = q.degree;
    double coeffs[qdegree+1] = {0};

    for (int i=0; i<=qdegree; i++){
        coeffs[i] = -1*q.coefficients[i];
    }

    Polynomial r = createPolynomial(qdegree, coeffs);

    Polynomial newpolym = addPolynomials(p, r);

    destroyPolynomial(r);

    return newpolym;
}

Polynomial multiplyPolynomials(const Polynomial& p, const Polynomial& q){
    int pdegree = p.degree;
    int qdegree =  q.degree;
    int solndegree = pdegree+qdegree;
    double coeffs[solndegree+1] = {0};
    Polynomial soln = createPolynomial(solndegree, coeffs);
    
    for (int i=0; i<=p.degree; i++){
        for (int j=0; j<=q.degree; j++){
            int degree = i+j;
            soln.coefficients[degree]  += p.coefficients[i]*q.coefficients[j];

        }
    }
    return soln;
}

void printPolynomial(const Polynomial& p){
    int degree = p.degree;
    std::string sign = "";

    for (int i = degree; i >= 0; i--){
        if (p.coefficients[i] >= 0){
            sign = "+";
        }
        else{
            sign = "";
        }

        if (p.coefficients[i] == 0){
            std::cout << "0";
        }
        else if (sign == "+" && i == degree){
            sign = "";
            std::cout << sign << p.coefficients[i] << "x^" << i;

        }
        // else if (sign == "+" && i == degree && p.coefficients[i]== 0){
        //     std::cout << "";
        // }
        else if (i == 1){
            std::cout << sign << p.coefficients[i] << "x";
        }
        else{
            std::cout << sign << p.coefficients[i] << "x^" << i;
        }
            
    }
}

void scalePolynomial(Polynomial& p, double c){
    for (int i=0; i<=p.degree; i++){
        p.coefficients[i] *= c;
    }
}

Polynomial differentiatePolynomial(const Polynomial& p){
    int pdegree = p.degree;

    if (pdegree > 0){
    double coeffs[pdegree] = {0};

    for (int i=pdegree; i>=1; i--){
        coeffs[pdegree-i] = i*p.coefficients[i];
    }

    Polynomial soln = createPolynomial(pdegree-1, coeffs);

    return soln;
    }

    else{
        double coeffs[] = {0};
        Polynomial soln = createPolynomial(0, coeffs);
        return soln;
    }
}

void destroyPolynomial(Polynomial& p){
    delete[] p.coefficients;
    p.coefficients = nullptr;
}

class fraction {
private:
    int numerator;
    int denominator;
    fraction() {
    }
    void error();
public:
    void reduction();
    void input();
    void output();

    int get_num();
    int get_denom();

    fraction sum(fraction frac);
    fraction multipl(fraction frac);
    fraction div(fraction frac);

    void sum(fraction &frac1,fraction &frac2);
    void multipl(fraction &frac1,fraction &frac2);
    void div(fraction &frac1,fraction &frac2);

    friend fraction operator+(fraction &frac1,fraction &frac2);
    friend fraction operator*(fraction &frac1,fraction &frac2);
    friend fraction operator/(fraction &frac1,fraction &frac2);


    fraction(int a, int b) {
        if(b){
            numerator = a;
            denominator = b;
            fraction::reduction();
        }
    }

    fraction (fraction& a){
        numerator=a.numerator;
        denominator=a.denominator;
    }

};



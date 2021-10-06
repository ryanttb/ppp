#include <cfloat>

#include <iostream>
#include <sstream>

using namespace std;

const char TOKEN_KIND_NUMBER = '8';
const char TOKEN_KIND_PLUS = '+';
const char TOKEN_KIND_MINUS = '-';
const char TOKEN_KIND_MUL = '*';
const char TOKEN_KIND_DIV = '/';
const char TOKEN_KIND_ERROR = 'E';

const double INVALID_VALUE = DBL_MIN;

class Token {
public:
    char kind;
    double value;

    Token(char k) : kind(k), value(0.0) {}
    Token(double v) : kind(TOKEN_KIND_NUMBER), value(v) {}
    Token(char k, double v) : kind(k), value(v) {}

    string str() {
        ostringstream s;
        s << "Token(kind: " << kind << ", value: " << value << ")";
        return s.str();
    }
};


Token get_token()
{
    double d;
    cin >> d;

    //cout << "d: " << d << endl;

    if (cin) {
        Token dt = Token(d);
        //cout << dt.str() << endl;
        return dt;
    }

    char c;
    cin >> c;

    //cout << "c: " << c << endl;

    if (cin) {
        Token ct = Token(c);
        //cout << ct.str() << endl;
        return ct;
    }

    return Token(TOKEN_KIND_ERROR);
}

double primary()
{
    Token t = get_token();

    return t.value;
}

double term()
{
    double left = primary();

    Token t = get_token();

    while (true) {
        switch (t.kind) {
            case TOKEN_KIND_MUL:
                left *= primary();
                t = get_token();
                break;

            case TOKEN_KIND_DIV:
            {
                double d = primary();

                if (d == 0) {
                    throw("divide by 0");
                }

                left /= primary();
                t = get_token();
                break;
            }

            default:
                return left;
        }
    }
}

double expression()
{
    double left = term();

    Token t = get_token();

    while (true) {
        switch (t.kind) {
            case TOKEN_KIND_PLUS:
                left += term();
                t = get_token();
                break;

            case TOKEN_KIND_MINUS:
                left -= term();
                t = get_token();
                break;

            default:
                // error: t is not plus or minus but we've already stolen the next input
                return left; // term as expression
        }
    }
}

int main() {

    try {
        //double result = expression();

        while (cin) {
            cout << "= " << expression() << endl;
        }

        return 0;
    } catch (exception& e) {
        cerr << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "exception" << endl;
        return 2;
    }
}

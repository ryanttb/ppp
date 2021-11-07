#include <cfloat>

#include <iostream>
#include <sstream>

using namespace std;

const char TOKEN_KIND_NUMBER = '8';
const char TOKEN_KIND_PLUS = '+';
const char TOKEN_KIND_MINUS = '-';
const char TOKEN_KIND_MUL = '*';
const char TOKEN_KIND_DIV = '/';

const char TOKEN_KIND_QUIT = 'q';
const char TOKEN_KIND_EVAL = ';';
const char TOKEN_KIND_UNSET = '?';
const char TOKEN_KIND_ERROR = 'E';

const double INVALID_VALUE = DBL_MIN;

struct Token {
    char kind;
    double value;

    Token() : kind{TOKEN_KIND_UNSET} {}
    Token(char k) : kind{k}, value{0.0} {}
    Token(double v) : kind{TOKEN_KIND_NUMBER}, value{v} {}
    Token(char k, double v) : kind{k}, value(v) {}

    string str() {
        ostringstream s;
        s << "Token{kind: " << kind << ", value: " << value << "}";
        return s.str();
    }
};

class TokenStream {
public:
    Token get() {
        if (m_next_token.kind != TOKEN_KIND_UNSET) {
            Token t {m_next_token};
            m_next_token = Token{};
            return t;
        } else {
            char c;
            cin >> c;

            switch (c) {
            case TOKEN_KIND_EVAL:
            case TOKEN_KIND_QUIT:
            case TOKEN_KIND_PLUS:
            case TOKEN_KIND_MINUS:
            case TOKEN_KIND_MUL:
            case TOKEN_KIND_DIV:
                // let these characters represent itself
                return Token {c};

            case '.':
            case '0': case '1': case '2': case '3': case '4': 
            case '5': case '6': case '7': case '8': case '9': 
                {
                    cin.putback(c); // put digit back onto input stream
                    double val;
                    cin >> val;
                    return Token {val};
                }
                
            default:
                throw("bad token");
            }
        }
    }

    void putback(Token t) {
        if (m_next_token.kind != TOKEN_KIND_UNSET) {
            throw("buffer is full");
        }
        m_next_token = t;
    }

private:
    Token m_next_token;
};

TokenStream ts;

double primary()
{
    Token t = ts.get();

    return t.value;
}

double term()
{
    double left = primary();

    Token t = ts.get();

    while (true) {
        switch (t.kind) {
            case TOKEN_KIND_MUL:
                left *= primary();
                t = ts.get();
                break;

            case TOKEN_KIND_DIV:
            {
                double d = primary();

                if (d == 0) {
                    throw("divide by 0");
                }

                left /= primary();
                t = ts.get();
                break;
            }

            default:
                ts.putback(t);
                return left;
        }
    }
}

double expression()
{
    double left = term();

    Token t = ts.get();

    while (true) {
        switch (t.kind) {
            case TOKEN_KIND_PLUS:
                left += term();
                t = ts.get();
                break;

            case TOKEN_KIND_MINUS:
                left -= term();
                t = ts.get();
                break;

            default:
                // bug: t is not plus or minus but we've already stolen the next input
                ts.putback(t);
                return left; // term as expression
        }
    }
}

int main() {

    try {
        double val = 0;

        while (cin) {
            Token t = ts.get();

            if (t.kind == TOKEN_KIND_QUIT) {
                cout << "quitting" << endl;
                break;
            }

            if (t.kind == TOKEN_KIND_EVAL) {
                cout << "= " << val << endl;
            } else {
                ts.putback(t);
            }

            val = expression();
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

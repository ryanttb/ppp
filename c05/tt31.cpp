int area(int length, int width)
{
    return length * width;
}

int main()
{
    //int s1 = area(7;
    /* MacOS: 
tt31.cpp:8:20: error: expected ')'
    int s1 = area(7;
                   ^
tt31.cpp:8:18: note: to match this '('
    int s1 = area(7;
                 ^
1 error generated.
     */

    /* AL2: 
     */

    /* Ubuntu: 
     */

    /* Arm: 
     */


    //int s2 = area(7)
    /* MacOS: 
tt31.cpp:29:14: error: no matching function for call to 'area'
    int s2 = area(7)
             ^~~~
tt31.cpp:1:5: note: candidate function not viable: requires 2 arguments, but 1 was provided
int area(int length, int width)
    ^
1 error generated.
     */

    /* AL2: 
     */

    /* Ubuntu: 
     */

    /* Arm: 
     */


    //Int s3 = area(7);
    /* MacOS: 
tt31.cpp:50:5: error: use of undeclared identifier 'Int'; did you mean 'int'?
    Int s3 = area(7);
    ^~~
    int
tt31.cpp:50:14: error: no matching function for call to 'area'
    Int s3 = area(7);
             ^~~~
tt31.cpp:1:5: note: candidate function not viable: requires 2 arguments, but 1 was provided
int area(int length, int width)
    ^
2 errors generated.
     */

    /* AL2: 
     */

    /* Ubuntu: 
     */

    /* Arm: 
     */

    //int s4 = area('7);
    /* MacOS: 
tt31.cpp:74:19: warning: missing terminating ' character [-Winvalid-pp-token]
    int s4 = area('7);
                  ^
tt31.cpp:74:19: error: expected expression
tt31.cpp:128:2: error: expected ';' at end of declaration
}
 ^
 ;
tt31.cpp:129:1: error: expected '}'
^
tt31.cpp:7:1: note: to match this '{'
{
^
1 warning and 3 errors generated.
     */

    /* AL2: 
     */

    /* Ubuntu: 
     */

    /* Arm: 
     */


    //int x0 = arena(7);
    /* MacOS: 
tt31.cpp:102:14: error: use of undeclared identifier 'arena'
    int x0 = arena(7);
             ^
1 error generated.
     */

    /* AL2: 
     */

    /* Ubuntu: 
     */

    /* Arm: 
     */

    //int x1 = area(7);
    /* MacOS: 
tt31.cpp:119:14: error: no matching function for call to 'area'
    int x1 = area(7);
             ^~~~
tt31.cpp:1:5: note: candidate function not viable: requires 2 arguments, but 1 was provided
int area(int length, int width)
    ^
1 error generated.
     */

    /* AL2: 
     */

    /* Ubuntu: 
     */

    /* Arm: 
     */

    //int x2 = area("seven", 2);
    /* MacOS: 
int x2 = area("seven", 2);
             ^~~~
tt31.cpp:1:5: note: candidate function not viable: no known conversion from 'const char [6]' to 'int' for 1st argument
int area(int length, int width)
    ^
1 error generated.
     */

    /* AL2: 
     */

    /* Ubuntu: 
     */

    /* Arm: 
     */

    return 0;
}


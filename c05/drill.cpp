#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    try {
        cout << " 1. Success!\n";
        cout << " 2. Success!\n";
        cout << " 3. Success" << "!\n";

        string success4 = " 4. Success!";
        cout << success4 << '\n';

        int res = 7;
        vector<int> v5(10);
        v5[5] = res;
        cout << " 5. Success!\n";

        vector<int> v6(10);
        v6[5] = 7;
        if (v6[5] == 7)
            cout << " 6. Success!\n";

        bool cond7 = true;
        if (cond7)
            cout << " 7. Success!\n";
        else 
            cout << " 7. Fail!\n";

        bool c8 = true;
        if (c8)
            cout << " 8. Success!\n";
        else
            cout << " 8. Fail!\n";

        string s9 = "ape";
        bool c9 = "fool" > s9;
        if (c9)
            cout << " 9. Success!\n";

        string s10 = "ape";
        if (s10 == "ape")
            cout << "10. Success!\n";

        string s11 = "ape";
        if (s11 == "ape")
            cout << "11. Success!\n";

        string s12 = "ape";
        if (s12 + "fool" == "apefool")
            cout << "12. Success!\n";

        vector<char> v13(5);
        for (int i = 0; i < v13.size(); ++i)
            ;
        cout << "13. Success!\n";

        vector<char> v14(5);
        for (int i = 0; i <= v14.size(); ++i) 
            ;
        cout << "14. Success!\n";

        string s15 = "15. Success!\n";
        for (int i = 0; i < s15.size(); ++i)
            cout << s15[i];

        if (true)
            cout << "16. Success!\n";
        else
            cout << "16. Fail!\n";

        int x17 = 2000;
        int c17 = x17;
        if (c17 == 2000) // warning: result of comparison of constant 2000 with expression of type 'char' is always false
            cout << "17. Success!\n";

        string s18 = "18. Success!\n"; 
        for (int i = 0; i < s18.size(); ++i)
            cout << s18[i];

        vector<int> v19(5);
        for (int i = 0; i <= v19.size(); ++i)
            ;
        cout << "19. Success!\n";

        int i20 = 0;
        int j20 = 9;
        while (i20 < 10) ++i20;
        if (j20 < i20)
            cout << "20. Success!\n";

        int x21 = 4;
        double d21 = 5.0/(x21 - 2); // floating point exception
        if (d21 == 0.5 * x21 + 0.5) 
            cout << "21. Success!\n";

        string s22 = "22. Success!\n"; // error: expected unqualified-id
        for (int i = 0; i <= 14; ++i)
            cout << s22[i];

        int i23 = 0, j23 = 0;
        while (i23 < 10)
            ++i23;
        if (j23 < i23)
            cout << "23. Success!\n";

        int x24 = 4;
        double d24 = 5.0/(x24 - 2);
        if (d24 == 0.5 * x24 + 0.5) // warning: using the result of an assignment as a condition without parentheses
            cout << "24. Success!\n";

        cout << "25. Success!\n"; // error: invalid operands to binary expression

        return 0;
    } catch (exception& e) {
        cerr << "Something went wrong: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "I do not know what was thrown" << endl;
        return 2;
    }
}

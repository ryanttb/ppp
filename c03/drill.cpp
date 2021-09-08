#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "A letter to whom?" << endl;
    string first_name;
    cin >> first_name;

    cout << "Their age?" << endl;
    int age;
    cin >> age;

    if (age < 0 || age > 110) {
        cerr << "No. That's not true. THAT'S IMPOSSIBLE!" << endl;
        exit(1);
    }

    cout << "A friend to ask about?" << endl;
    string friend_name;
    cin >> friend_name;

    cout << "Sex of friend?" << endl;
    char friend_sex;
    cin >> friend_sex;

    cout << "Ohai " << first_name << "," << endl
        << endl
        << "\tHow are you now?" << endl
        << "I'm not so bad." << endl
        << endl
        << "Have you seen " << friend_name << " lately?" << endl;

    cout << "Did you have sex with ";

    switch (friend_sex) {
        case 'm':
        case 'M':
            cout << "him";
            break;

        case 'f':
        case 'F':
            cout << "her";
            break;

        default:
            cout << "them";
            break;
    }

    cout << "?" << endl << endl;
    
    cout << "I hear you just had a birthday and you are " << age << " years old!" << endl;

    if (age < 12) {
        cout << "Next year, you will be " << age + 1 << "!" << endl;
    } else if (age == 17) {
        cout << "Next year, you will be able to vote!" << endl;
    } else if (age == 40) {
        cout << "Happy 40th!!!" << endl;
    } else if (age > 70) {
        cout << "I hope you're enjoying retirement!" << endl;
    } else {
        cout << "Nothing special about that." << endl;
    }


    cout << endl
        << "kthxbai" << endl
        << endl
        << "- arr" << endl;

    return 0;
}

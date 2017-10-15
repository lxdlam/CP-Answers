#include <climits>
#include <cfloat>
#include <iostream>

using namespace std;

int main()
{
    // int: -2147483648 ~ 2147483647
    // 10^9
    cout << "int: " << INT_MIN << " ~ " << INT_MAX << endl;
    // long: -9223372036854775808 ~ 9223372036854775807
    // 10^18
    cout << "long: " << LONG_MIN << " ~ " << LONG_MAX << endl;
    // long long : -9223372036854775808 ~ 9223372036854775807
    // 10^18
    cout << "long long : " << LONG_LONG_MIN << " ~ " << LONG_LONG_MAX << endl;
    // double: 2.22507e-308 ~ 1.79769e+308
    cout << "double: " << DBL_MIN << " ~ " << DBL_MAX << endl;
    // long double: 3.3621e-4932 ~ 1.18973e+4932
    cout << "long double: " << LDBL_MIN << " ~ " << LDBL_MAX << endl;
    // double EPS: 2.22045e-16
    cout << "double EPS: " << DBL_EPSILON << endl;
    // long double EPS: 1.0842e-19
    cout << "long double EPS: " << LDBL_EPSILON << endl;
}
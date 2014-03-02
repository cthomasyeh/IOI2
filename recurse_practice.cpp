#include <iostream>

using namespace std;

int factorial(int n)
{
    return 0;
}

int bunnyEars(int bunnies)
{
    return 0;
}

int bunnyEars2(int bunnies)
{
    return 0;
}

int sumDigits(int num)
{
    return 0;
}

int count7(int n)
{
    return 0;
}

int main()
{
    cout << "TEST FACTORIAL" << endl;
    cout << "******************************" << endl;
    cout << "Factorial of 5" << endl;
    cout << "Expected: 120" << endl;
    cout << "Output: " << factorial(5) << endl;
    cout << "\nFactorial of 1" << endl;
    cout << "Expected: 1" << endl;
    cout << "Output: " << factorial(1)<< endl;
    cout << "\nFactorial of 10" << endl;
    cout << "Expected: 362880" << endl;
    cout << "Output: " << factorial(10)<< endl;

    cout << "\nTEST BUNNIES" << endl;
    cout << "******************************" << endl;
    cout << "5 Bunnies" << endl;
    cout << "Expected: 10" << endl;
    cout << "Output: " << bunnyEars(5) << endl;
    cout << "\n1000 Bunnies" << endl;
    cout << "Expected: 2000" << endl;
    cout << "Output: " << bunnyEars(1000)<< endl;
    cout << "\n0 Bunnies" << endl;
    cout << "Expected: 0" << endl;
    cout << "Output: " << bunnyEars(0)<< endl;


    cout << "\nTEST BUNNIES2" << endl;
    cout << "******************************" << endl;
    cout << "5 Bunnies" << endl;
    cout << "Expected: 13" << endl;
    cout << "Output: " << bunnyEars2(5) << endl;
    cout << "\n1000 Bunnies" << endl;
    cout << "Expected: 2500" << endl;
    cout << "Output: " << bunnyEars2(1000)<< endl;
    cout << "\n0 Bunnies" << endl;
    cout << "Expected: 0" << endl;
    cout << "Output: " << bunnyEars2(0)<< endl;

    cout << "\nTEST SUMDIGITS" << endl;
    cout << "******************************" << endl;
    cout << "54321" << endl;
    cout << "Expected: 15" << endl;
    cout << "Output: " << sumDigits(54321) << endl;
    cout << "\n8935" << endl;
    cout << "Expected: 25" << endl;
    cout << "Output: " << sumDigits(8935)<< endl;
    cout << "\n0" << endl;
    cout << "Expected: 0" << endl;
    cout << "Output: " << sumDigits(0)<< endl;

    cout << "\nTEST COUNT7" << endl;
    cout << "******************************" << endl;
    cout << "717" << endl;
    cout << "Expected: 2" << endl;
    cout << "Output: " << count7(717) << endl;
    cout << "\n57378777" << endl;
    cout << "Expected: 5" << endl;
    cout << "Output: " << count7(57378777)<< endl;
    cout << "\n0" << endl;
    cout << "Expected: 0" << endl;
    cout << "Output: " << count7(0)<< endl;

    return 0;

}
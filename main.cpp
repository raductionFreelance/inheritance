#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

struct Name{
    string name, surname;
};
struct Address{
    string country, region, city, street;
    int building, appartmant;
};

struct Visa{
    int number, numOfEntries;
    string type, issuedIn, country;
    tm startDay{}, endDay{};
    
};

class Passport{
private:
    int seriesM, dateOfBarthday, dateOfIssueM, dateOfExpiryM, taxNumber;
    Name name;
    Address address;
public:
    Passport(const int& s, const int& d1, const int& d2, const int& d3, const int& t, const Name& n, const Address& a):
    seriesM(s), dateOfBarthday(d1), dateOfIssueM(d2), dateOfExpiryM(d3), taxNumber(t), name(n), address(a) {};
    
    void print() const {
            cout << "=== Passport Information ===\n";
            cout << "Series: " << seriesM << endl;
            cout << "Name: " << name.name << " " << name.surname << endl;
            cout << "Date of birth: " << dateOfBarthday << endl;
            cout << "Date of issue: " << dateOfIssueM << endl;
            cout << "Date of expiry: " << dateOfExpiryM << endl;
            cout << "Tax number: " << taxNumber << endl;
            cout << "Address: " << address.country << ", " << address.region << ", "
                 << address.city << ", " << address.street << " "
                 << address.building << "/" << address.appartmant << endl;
        }
};

class ForeignPassport : public Passport{
private:
    int seriesA, dateOfIssueA, dateOfExpiryA;
    vector<Visa> visa;
public:
    ForeignPassport(const int& sA, const int& d1A, const int& d2A,
                        const int& sM, const int& d1M, const int& d2M,
                        const int& d3M, const int& t,
                        const Name& n, const Address& a, const vector<Visa>& v)
            : Passport(sM, d1M, d2M, d3M, t, n, a),
            seriesA(sA), dateOfIssueA(d1A), dateOfExpiryA(d2A), visa(v) {};
    
    void print() const {
            cout << "\n=== Foreign Passport Information ===\n";
            Passport::print();
            cout << "Foreign passport series: " << seriesA << endl;
            cout << "Foreign passport issue date: " << dateOfIssueA << endl;
            cout << "Foreign passport expiry date: " << dateOfExpiryA << endl;

            for (size_t i = 0; i < visa.size(); i++) {
                cout << "\n--- Visa #" << (i + 1) << " ---\n";
                cout << "Number: " << visa[i].number << endl;
                cout << "Available entries: " << visa[i].numOfEntries << endl;
                cout << "Type: " << visa[i].type << endl;
                cout << "Issued in: " << visa[i].issuedIn << endl;
                cout << "Country: " << visa[i].country << endl;

                cout << "Valid from: " << visa[i].startDay.tm_mday << "."
                     << visa[i].startDay.tm_mon + 1 << "."
                     << visa[i].startDay.tm_year + 1900 << endl;

                cout << "Valid until: " << visa[i].endDay.tm_mday << "."
                     << visa[i].endDay.tm_mon + 1 << "."
                     << visa[i].endDay.tm_year + 1900 << endl;
            }
        }
};



int main() {
    Name n = {"Ivan", "Petrov"};
    Address a = {"Ukraine", "Kyiv region", "Kyiv", "Khreshchatyk", 10, 5};

    tm start1 = {0, 0, 0, 12, 5, 125};
    tm end1 = {0, 0, 0, 12, 5, 126};

    Visa v1 = {12345, 2, "Tourist", "Kyiv", "France", start1, end1};
    vector<Visa> visas = {v1};

    ForeignPassport fp(9999, 2022, 2032, 1111, 1999, 2015, 2025, 987654, n, a, visas);
    fp.print();

    return 0;
}

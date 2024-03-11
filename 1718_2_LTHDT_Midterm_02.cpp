#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iterator>
#include <iomanip>

using std::string;
using std::stack;
using std::deque;
#define vi std::vector<int>
#define mp std::map <int, int>
#define pi std::pair<int, int>
#define endl std::cout << std::endl

#include <sstream>
template <typename T> std::string tostr(const T& t)
{
    std::ostringstream os; os<<t; return os.str();
}

string convert_string (double a){
    int b = a;
    string res = "";
    while ( b > 0){
        res += tostr(b%10);
        b/=10;
    }
    std::reverse(res.begin(), res.end());
    a = a - (int)a;
    if ( a == 0 ){
        return res ;
    }else{
        res += ".";
        a = a*100;
        b = (int)a;
        string res2 = "";
        while ( b > 0){
        res2 += tostr(b%10);
        b/=10;
        }
        std::reverse(res2.begin(), res2.end());
        return res + res2;
    }
}

class Employee {
    private:
        int id;
        string firstName;
        string lastName;
        double salary;
    public:

        Employee (int id, string firstName, string lastName, double salary){
            this->id = id;
            this->firstName = firstName;
            this->lastName = lastName;
            this-> salary = salary;
        }

        int getID() {return id;}

        string getFirstName() {return firstName;}

        string getLastName() {return lastName;}

        string getName() {return firstName + " " + lastName;}

        double getSalary() {return salary;}

        void setSalary(double salary) {this->salary = salary;}

        double getAnnualSalary() {return 12.0 * salary;}

        double raiseSalary(double percent) {return salary += (salary*percent)/100;}

        string toString() {
            salary = round (salary * 100) / 100;
            return "Employee[id=" + tostr(id) + ",name=" + getName() + ",salary=$" + convert_string(salary) + "]";
        } 
        // format: “Employee[id=?,name=firstName lastName,salary=?]”;

        friend std::istream& operator>> (std::istream& in, Employee& nhanvien){
            in >> nhanvien.id;
            in.ignore();
            std::getline (in, nhanvien.firstName, '\n');
            std::getline (in, nhanvien.lastName, '\n');
            in >> nhanvien.salary;
            return in;
        }

        friend std::ostream& operator<< (std::ostream& out, Employee& nhanvien){
            out << nhanvien.toString();
            return out;
        }

        friend Employee operator++ (Employee& nhanvien){
            nhanvien.raiseSalary(10);
            return nhanvien;
        }

        friend Employee operator++ (Employee& nhanvien, int){
            nhanvien.raiseSalary(10);
            return nhanvien;
        }

        friend Employee operator-- (Employee& nhanvien){
            nhanvien.raiseSalary(0.01);
            return nhanvien;
        }

        friend Employee operator-- (Employee& nhanvien, int){
            nhanvien.raiseSalary(0.01);
            return nhanvien;
        }

        friend Employee operator+ (Employee& nhanvien, double difference){
            nhanvien.setSalary ( nhanvien.salary + difference);
            return nhanvien;
        }

        friend Employee operator- (Employee& nhanvien, double difference){
            nhanvien.setSalary ( nhanvien.salary - difference);
            return nhanvien;
        }

        friend bool operator> (Employee& nhavien_a, Employee nhanvien_b){
            return nhavien_a.getAnnualSalary() > nhanvien_b.getAnnualSalary();
        }

        friend bool operator< (Employee& nhavien_a, Employee nhanvien_b){
            return nhavien_a.getAnnualSalary() < nhanvien_b.getAnnualSalary();
        }

        friend bool operator== (Employee& nhavien_a, Employee nhanvien_b){
            return nhavien_a.getAnnualSalary() == nhanvien_b.getAnnualSalary();
        }

        friend bool operator!= (Employee& nhavien_a, Employee nhanvien_b){
            return nhavien_a.getAnnualSalary() != nhanvien_b.getAnnualSalary();
        }


};

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);

    Employee* Emp1 = new Employee(0, "", "", 0.0);
    Employee* Emp2 = new Employee(0, "", "", 0.0);
    std::cin >> *Emp1;
    std::cin >> *Emp2;
    int A, B;
    std::cin >> A >> B;

    std::cout << *Emp1 << '\n';
    std::cout << *Emp2 << '\n';

    if ( *Emp1 < *Emp2) std::cout << "NHO HON" << '\n';
    if ( *Emp1 > *Emp2) std::cout << "LON HON" << '\n';
    if ( *Emp1 == *Emp2) std::cout << "BANG NHAU" << '\n';

    ((*Emp1)++);
    *Emp1 = (*Emp1) - A;
    std::cout << "$" << Emp1->getSalary();
    return 0;
}
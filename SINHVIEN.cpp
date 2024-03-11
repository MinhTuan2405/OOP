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

// prototype

// in this class, define the class follow this instructation
/*
xây dựng các lớp sau kèm theo các thao tác của nó:
- Lớp Điểm, gồm có các thuộc tính:
+ mảng số thực: lưu danh sách điểm các môn học (các điểm là các số thực >=0 và <=10)
+ số lượng phần tử của danh sách điểm.

Thao tác: xây dựng các toán tử >>, <<, [], =, lấy điểm trung bình cộng, các phương thức khởi tạo (3 phương thức), phương thức hủy, các phương thức get và set.

*/
class Diem {
    private:
        int number;
        double mark[20];

        friend class SinhVien;
    public:
        Diem ();
        Diem (int number, double mark[]);
        Diem (Diem& grade);
        friend std::istream& operator>> ( std::istream& in, Diem& grade){
            grade.number = 0;
            while ( in >> grade.mark[grade.number]){
                ++grade.number;
            }
            return in;
        }
        friend std::ostream& operator<< ( std::ostream& out, Diem grade){
             out << grade.number << '\n';
            for ( int i = 0; i < grade.number; ++i){
                 out << grade.mark[i] << " ";
             }
            return out;
        };
        void get();
        int get_sub() {return number;};
        void set();
        double _GET_AVERAGE();
        ~Diem();

};

Diem::Diem(){
    number = 0;
    for ( int i = 0; i < 20; ++i){
        mark[i] = 0;
    }
}

Diem::Diem(int number, double mark[]){
    number = number;
    for ( int i = 0; i < number; ++i){
        mark[i] = mark[i];
    }
}

Diem::Diem ( Diem& grade){
    number = grade.number;
    for ( int i = 0; i < number; ++i){
        mark[i] = grade.mark[i];
    }
}

void Diem::set(){
    std::cin >> number;
    for ( int i = 0; i < number; ++i){
        std::cin >> mark[i];
    }
}

void Diem::get(){
    std::cout << number; endl;
    for (int i = 0; i < number; ++i){
        std::cout << mark[i] << " ";
    }
}

double Diem::_GET_AVERAGE(){
    double sum = 0 ;
    for ( int i = 0; i < number; ++i){
        sum += mark[i];
    }
    return (double) sum / number;
}

Diem::~Diem(){
    number = 0;
    for ( int i = 0; i < number; ++i){
        mark[i] = 0;
    }
}

/*
Lớp SinhViên, gồm có các thuộc tính
+ Họ tên (chuỗi có khoảng trắng)
+ Mã Sinh Viên (chuỗi không có khoảng trắng)
+ Điểm (thuộc lớp điểm khai báo ở trên).
Thao tác: xây dựng các toán tử >>, <<, =, < (dựa vào điểm trung bình),
 lấy điểm trung bình cộng, các phương thức khởi tạo (3 phương thức), phương thức hủy, các phương thức get và set.
*/

class SinhVien {
    private:
        string fullname;
        string code;
        Diem grade;
    friend class Diem;
    public:
        SinhVien(){
            fullname = "";
            code = "";
            grade.number = 0;
            for ( int i = 0; i < grade.number; ++i){
                grade.mark[i] = 0;
            }
        }

        SinhVien (string fullname, string code, Diem grade){
            fullname = fullname;
            code = code;
            grade = grade;
        }

        SinhVien ( SinhVien* sinhvien){
            fullname =sinhvien -> fullname;
            code = sinhvien -> code;
            grade = sinhvien -> grade;
        }

        friend std::istream& operator>> ( std::istream& in, SinhVien& sinhvien ){
            std::fflush (stdin);
            std::getline ( in, sinhvien.fullname, '\n');
            //in.ignore ('\n');
            in >> sinhvien.code;
            in >> sinhvien.grade;
            return in;
        }

        friend std::ostream& operator<< ( std::ostream& out, SinhVien sinhvien){
            out << "Ho Ten: " << sinhvien.fullname << '\n';
            out << "Ma Sinh Vien: " << sinhvien.code << '\n';
            out << "DTB: " << std::setprecision(1) << std::fixed << sinhvien.grade._GET_AVERAGE();
            return out;
        }

        SinhVien operator= ( SinhVien sinhvien){
            fullname = sinhvien.fullname;
            code = sinhvien.code;
            grade = sinhvien.grade;
        }

        bool operator< ( SinhVien sinhvien){
            return grade._GET_AVERAGE() < sinhvien.grade._GET_AVERAGE();
        }

        void set (){
            std::cin >> fullname;
            std::cin >> code;
            std::cin >> grade.number;
            for ( int i = 0; i < grade.number; ++i){
                std::cin >> grade.mark[i];
            }
        }

        string get_fullname(){
            return fullname;
        }

        string get_code (){
            return code;
        }

        int get_sub (){
            return grade.number;
        }

        float get_average_mark ( ){
            return grade._GET_AVERAGE();
        }

        void get(){
            std::cout << "Ho Ten: " << get_fullname() ; endl;
            std::cout << "Ma Sinh Vien: " << get_code(); endl;
            std::cout << "DTB: " << std::setprecision(1) << std::fixed << get_average_mark();
        }
        ~SinhVien (){
            fullname = "";
            code = "";
            for ( int i = 0; i < grade.number; ++i) grade.mark[i] = 0;
            grade.number = 0;
        }

};

int main (){

    SinhVien sinhvien;
    std::cin >> sinhvien;
    std::cout << sinhvien;
    return 0;
}
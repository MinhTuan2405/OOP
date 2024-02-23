/*
Xây dựng lớp phân số cho phép thực hiện các thao tác:
Nhập, xuất.

Input:
Nhập vào 2 số nguyên a b

Output:
Xuất ra phân số dạng a/b

demo 
input               output
1 2                 1/2

*/

/*
Xây dựng lớp phân số cho phép thực hiện các thao tác:
Nhập, xuất.
Lấy tử số, mẫu số.
Gán giá trị cho tử số, mẫu số.
Nghịch đảo, rút gọn.
Cộng, trừ, nhân, chia, so sánh với phân số khác.
Input:

Nhập vào 2 số nguyên a và b
Output:
Dòng 1 xuất phân số vừa nhập
Dòng 2 xuất tử số của phân số vừa nhập
Dòng 3 xuất mẫu số của phân số vừa nhập
Dòng 4 xuất phân số nghịch đảo
Dòng 5 xuất phân số rút gọn của phân số ban đầu
Xuất tổng của phân số ban đầu và phân số nghịch đảo của nó (kết quả được rút gọn)

*/

#include <iostream>
#include <algorithm>
#include <vector> 
#include <cmath>

#define endl std::cout << std::endl ;

class Phanso {
    public:
        int tu ; int mau ;

        void Nhap() {
            std::cin >> tu >> mau ;
        }

        void xuat() {
            std::cout << tu << "/" << mau ;
        }

        void lay_tu () {
            std::cout << tu ;
        }

        void lay_mau () {
            std::cout << mau ;
        }

        void gan_tu ( int a) {
            tu = a  ;
        }

        void gan_mau ( int b) {
            mau = b ;
        }

        void gan ( int a, int b) {
            tu = a ;
            mau = b ;
        }

        void nghich_dao () {
            int a = mau ;
            mau = tu ;
            tu = a ;
        }

        void rut_gon() {
            int gcd = std::__gcd ( tu, mau) ;
            tu = tu / gcd ;
            mau = mau / gcd ;
        }
        
            
};

Phanso operator+ ( Phanso ps1, Phanso ps2) {
    Phanso kq ;
    kq.mau = ps1.mau * ps2.mau ;
    kq.tu = ps1.tu*ps2.mau + ps2.tu*ps1.mau ;
    kq.rut_gon() ;
    return kq ;
}

Phanso operator- ( Phanso ps1, Phanso ps2) {
    Phanso kq ;
    kq.mau = ps1.mau * ps2.mau ;
    kq.tu = ps1.tu*ps2.mau - ps2.tu*ps1.mau ;
    kq.rut_gon() ;
    return kq ;
}

Phanso operator* ( Phanso ps1, Phanso ps2) {
    Phanso kq ;
    kq.mau = ps1.mau * ps2.mau ;
    kq.tu = ps1.tu*ps2.tu ;
    kq.rut_gon() ;
    return kq ;
}

Phanso operator/ ( Phanso ps1, Phanso ps2) {
    Phanso kq ;
    ps2.nghich_dao() ;
    kq = ps1*ps2 ;
    kq.rut_gon() ;
    return kq ;
}

bool operator< ( Phanso ps1, Phanso ps2) {
    return ps1.tu/ps1.mau < ps2.tu/ps2.mau ;
}// 1/2(0.5) 3/4(0.75)

bool operator> ( Phanso ps1, Phanso ps2) {
    return ps1.tu/ps1.mau > ps2.tu/ps2.mau ;
}// 1/2(0.5) 3/4(0.75)

bool operator== ( Phanso ps1, Phanso ps2) {
    return ps1.tu/ps1.mau == ps2.tu/ps2.mau ;
}// 1/2(0.5) 3/4(0.75)





int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    std::cout.tie(nullptr);

    Phanso ps1 ;
    ps1.Nhap() ;
    ps1.xuat() ;
    endl;
    ps1.lay_tu() ; endl;
    ps1.lay_mau() ;

    endl;
    int a, b ;
    std::cin >> a >> b ;
    ps1.gan ( a, b) ;
    ps1.xuat() ;

    endl;
    ps1.nghich_dao() ;
    ps1.xuat() ;

    endl;
    ps1.nghich_dao() ;
    ps1.rut_gon() ;
    ps1.xuat() ;

    //endl;

    // Phanso ps2 ;
    // ps2.Nhap() ;
    // Phanso c = ps1 + ps2 ;
    // c.xuat() ; endl;
    // Phanso d = ps1 - ps2 ;
    // d.xuat() ; endl;
    // Phanso e = ps1*ps2 ;
    // e.xuat(); endl;
    // Phanso f = ps1/ps2 ;
    // f.xuat() ; endl;


    // if ( ps1 < ps2 ) std::cout << "true";
    // else std::cout << "false";
    return 0;
}

// 


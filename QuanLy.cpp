#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
#include <string>
using namespace std;
int demcafe, demtrasua;
int tongcf, tongts;
bool sb[21];
class chonban {
	int so;
public:
	void datban() {

		cout << "chon so ban tu 1 den 20:";
		cin >> so;
		while (1) {
			if (sb[so] == true) {
				cout << "Ban da duoc chon.Vui long chon ban khac: ";
				cin >> so;
			}
			else {
				sb[so] = true;
				break;
			}
		}
	}
	void traban() {
		cout << "tra ban so: ";
		cin >> so;
		sb[so] = false;
	}
};
class sanpham {
	int sp; int sl;
public:
	void loaisp() {
		while (1) {
			system("cls");
			cout << "chon loai sp: \n1.cafe\n2.trasua\n3.da chon xong\n";
			cin >> sp;
			while (1) {
				if (sp == 1 || sp == 2 || sp == 3)break;
				cout << "chon lai san pham: 1 hoac 2 hoac 3\n";
				cin >> sp;
			}
			if (sp == 1) {
				cout << "nhap so luong cafe\n";
				cin >> sl;
				demcafe = demcafe + sl;
			}
			else if (sp == 2) {
				cout << "nhap so luong tra sua\n";
				cin >> sl;
				demtrasua = demtrasua + sl;
			}
			else if (sp == 3)break;
		}
	}
	/*void demsp_giasp() {
		if (sp == 1) {
			demcafe=demcafe+1;
		}
		else if (sp == 2) {
			demtrasua=demtrasua+1;
		}
	}*/
	void thongke() {
		tongcf = demcafe * 15000;
		tongts = demtrasua * 20000;
		string cf = "so luong cafe da ban: ";
		string tcf = ". Tong cafe la: ";
		string ts = "so luong tra sua da ban: ";
		string tts = ". Tong tra sua la: ";
		string ttn = "tong thu nhap la: ";
		string xd = "\n";
		cout << "so luong cafe da ban: " << demcafe << ". Tong cafe la: " << tongcf << "\n";
		cout << "so luong tra sua da ban: " << demtrasua << ". Tong tra sua la:" << tongts << "\n";
		cout << "tong thu nhap la: " << tongcf + tongts << "\n";
		//ghi ra file
		ofstream file("thong_ke.txt");
		file << cf << demcafe << tcf << tongcf << xd << ts << demtrasua << tts << tongts << xd << ttn << tongcf + tongts << xd;
		file.close();
	}
};
void reset() {
	demcafe = 0; demtrasua = 0;
	string r = "";
	//reset thong ke
	ofstream file("thong_ke.txt", ios::trunc);
	file << r;
	file.close();
	//reset thong tin khach hang
	ofstream file1("thong tin khach hang.txt", ios::trunc);
	file1 << r;
	file1.close();
}
class khachhang {
	string ten;
	string sodt;
	string address;
public:
	void nhapten() {
		cin.ignore();
		cout << "nhap ten: ";
		getline(std::cin, ten);
	}
	void nhapso() {
		cout << "nhap so dien thoai: ";
		getline(cin, sodt);
	}
	void diachi() {
		cout << "dia chi cua ban: ";
		getline(cin, address);
	}
	void ghithongtin() {
		string t = "ten khach hang: ";
		string sdt = ". so dien thoai: ";
		string dc = "dia chi: ";
		string xh = "\n";
		//ghi ra file
		ofstream file("thong tin khach hang.txt", ios::app);
		file << t << ten << xh << sdt << sodt << xh << dc << address << xh << xh;
		file.close();
	}
};
class menu {
public:
	void nuoc() {
		cout << "\nca phe" << ":" << "15000" << endl;
		cout << "\ntra sua" << ":" << "20000" << endl;
		system("pause");
	}
};
void main() {
	int c;
	chonban b; sanpham a; khachhang k; menu m;
	demcafe = 0; demtrasua = 0;
	for (int i = 1; i <= 20; i++) sb[i] = false;
	while (1) {
		system("cls");
		cout << "\nChon doi tuong: \n1.Ban san pham\n2.Hien thong ke\n3.Reset du lieu\n4.Khach tra ban\n5.Thong tin khach hang\n6.Hien thi menu\n";
		cout << "- Moi thac mac va phan hoi vui long lien he 113 -" << endl;
		cout << "nhap lua chon: ";
		cin >> c;
		while (1) {
			if (c == 1 || c == 2 || c == 3 || c == 4 || c == 5 || c == 6)break;
			cout << "chon lai doi tuong: 1 hoac 2 hoac 3\n";
			cin >> c;
		}

		if (c == 1) {
			b.datban();
			a.loaisp();
			//a.demsp_giasp();
		}
		else if (c == 2) {
			a.thongke();
		}
		else if (c == 3) {
			reset();
			a.thongke();
		}
		else if (c == 4) {
			b.traban();
		}
		else if (c == 5) {
			k.nhapten();
			k.nhapso();
			k.diachi();
			k.ghithongtin();
		}
		else if (c == 6) {
			m.nuoc();
		}
	}
}
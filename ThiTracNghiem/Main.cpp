#include <iostream>
#include <string>
#include <fstream>
#include "mylib.h"
#include "GiaoDien.h"
#include "ChucNang.h"
#include "MonHoc.h"
#include "Diem.h"
#include "KhaiBao.h"
#define MAXCAUHOI 200
#define MAXLOP 200
using namespace std;

int main() {
	LOP lop;
	DS_LOP ds_lop;
	NodeMH* root = null;
	MonHoc monhoc;
	docFileDanhSachLop(ds_lop);
	docFileSinhVien(ds_lop);
	docFileDanhSachMonHoc(root);
	docFileCauHoi(root);
	docFileDiem(ds_lop, root);
	//duyetCayDeHienThi(root);
	//ghiFileDanhSachMonHoc(root, fileout);
	resizeConsole(1300, 700); // 175
	//inBangDiem(ds_lop, lop, root, 45, 7, 75, 20);
	chucNangDangNhap(60, 10, 50, 10, ds_lop, root);
	//MonHoc* dsmh[100];
	//xuatDiemSV(ds_lop, "N18DCCN132", dsmh, 0, 10, 10);
	//DIEM diem, diem2;
	//cin >> diem.maMh;
	//cin >> diem.diem_thi;
	//cin >> diem2.maMh;
	//cin >> diem2.diem_thi;
	//NODEDIEM* node = khoiTaoDiem(diem);
	//NODEDIEM* node2 = khoiTaoDiem(diem2);
	//SINHVIEN sv;
	//cin >> sv.masv;
	//themDiem(sv, diem);
	//themDiem(sv, diem2);
	//for (NODEDIEM* p = sv.first; p != null; p = p->next)
	//{
	//	cout << p->data.diem_thi;
	//}
	//hienthi(ds_lop);
	//bangDiemTheoLop(40, 7, 80, 20, 15);
}
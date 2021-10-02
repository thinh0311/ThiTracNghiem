#pragma once
#include <iostream>
#include <string>
#include <fstream>
#define MAXCAUHOI 200
#define MAXLOP 200
#define MAXSV 200
#define MAXMH 200
#define null NULL
using namespace std;
//=============== danh sach cau hoi ================
struct CauHoiThi
{
	string noiDung;
	string dapAnA;
	string dapAnB;
	string dapAnC;
	string dapAnD;
	string dapAnDung;
	/*CauHoiThi(string nd, string a, string b, string c, string d, string da) {
		noiDung = nd;
		dapAnA = a;
		dapAnB = b;
		dapAnC = c;
		dapAnD = d;
		dapAnDung = da;
	}
	CauHoiThi() {
		noiDung = "";
		dapAnA = "";
		dapAnB = "";
		dapAnC = "";
		dapAnD = "";
		dapAnDung = "";
	}*/
};
typedef struct CauHoiThi CAUHOI;
struct DSCAUHOI
{
	CAUHOI ds[MAXCAUHOI];
	int sl = 0;
};
//============== danh sach mon hoc =================
struct monhoc
{
	//data
	string mamh;
	string tenmh;
	DSCAUHOI* dscauhoi = null;
};
typedef struct monhoc MonHoc;

struct NodeMH
{
	MonHoc data;
	NodeMH* left;
	NodeMH* right;
};

//=============== danh sach diem ===================
struct diem
{
	//data
	string maMh;
	float diem_thi;
};
typedef struct diem DIEM;
struct nodeDiem
{
	DIEM data;
	nodeDiem* next;
};
typedef struct nodeDiem NODEDIEM;
//============== = danh sach sinh vien =============
struct sinh_vien
{
	//data
	string masv;
	string ho;
	string ten;
	string phai;
	string password;
	NODEDIEM* first = null;

};
typedef struct sinh_vien SINHVIEN;
struct node
{
	SINHVIEN data;
	node* pNext;
};
typedef struct node NODESV;
//=============== danh sach lop ====================
struct lop
{
	string malop;
	string tenlop;
	//*dssv
	NODESV* first = null;
};
typedef struct lop LOP;
struct ds_lop
{
	LOP* ds[MAXLOP];
	int sl = 0;
};
typedef struct ds_lop DS_LOP;

struct mSINHVIEN {
	SINHVIEN sv[MAXSV];
	int slsv = 0;
};



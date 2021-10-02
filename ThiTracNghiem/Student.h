#pragma once
#include "KhaiBao.h"

NODESV* taoNodeSinhVien(SINHVIEN sv);
void themSinhVien(DS_LOP& ds_lop, SINHVIEN& sv, int vitri);
int xoaDauDSSV(DS_LOP& ds_lop, int vitri);
int xoaSauNode_p(DS_LOP& ds_lop, int vitri, NODESV* sv);
int xoaSinhVien(DS_LOP& ds_lop, int vitri, string masv);
bool KiemTraTrungSinhVien(DS_LOP& ds_lop, string masv);
int demSV(NODESV* p);
void mSinhVien(mSINHVIEN& mSV, DS_LOP lop, int sttLop);

NODESV* taoNodeSinhVien(SINHVIEN sv) {
	NODESV* node = new NODESV;
	node->data = sv;
	node->pNext = null;
	return node;
}

void themSinhVien(DS_LOP& ds_lop, SINHVIEN& sv, int vitri) {
	NODESV* node = taoNodeSinhVien(sv);
	if (ds_lop.ds[vitri]->first == null) {
		ds_lop.ds[vitri]->first = node;
	}
	else
	{
		node->pNext = ds_lop.ds[vitri]->first;
		ds_lop.ds[vitri]->first = node;
	}
}

void xuatSVTheoLop(DS_LOP& ds_lop,mSINHVIEN& msv, int vitri, int slsv, int index, int x, int y) {
	if (ds_lop.ds[vitri]->first == null)
	{
		gotoxy(100, 15); cout << "danh sach rong";
		return;
	}
	else {
		mSinhVien(msv, ds_lop, vitri);
		int dem = 0;
		SetColor(15);
		SetBGColor(32);
		if (slsv < 15) {
			for (int i = 0; i < slsv; i++)
			{
				gotoxy(x + 2, y + 3 + dem); cout << dem + 1;
				gotoxy(x + 10, y + 3 + dem); cout << msv.sv[i].masv;
				gotoxy(x + 26, y + 3 + dem); cout << msv.sv[i].ho;
				gotoxy(x + 45, y + 3 + dem); cout << msv.sv[i].ten;
				gotoxy(x + 65, y + 3 + dem); cout << msv.sv[i].phai;
				gotoxy(x + 83, y + 3 + dem); cout << msv.sv[i].password;
				dem++;
			}
		}
		else
		{
			if (slsv - index < 15)
			{
				dem = 0;
				for (int i = index; i < slsv; i++)
				{
					gotoxy(x + 2, y + 3 + dem); cout << i + 1;
					gotoxy(x + 10, y + 3 + dem); cout << msv.sv[i].masv;
					gotoxy(x + 26, y + 3 + dem); cout << msv.sv[i].ho;
					gotoxy(x + 45, y + 3 + dem); cout << msv.sv[i].ten;
					gotoxy(x + 65, y + 3 + dem); cout << msv.sv[i].phai;
					gotoxy(x + 83, y + 3 + dem); cout << msv.sv[i].password;
					dem++;
				}
			}
			else
			{
				dem = 0;
				for (int i = index; i < index + 15; i++)
				{
					gotoxy(x + 2, y + 3 + dem); cout << i + 1;
					gotoxy(x + 10, y + 3 + dem); cout << msv.sv[i].masv;
					gotoxy(x + 26, y + 3 + dem); cout << msv.sv[i].ho;
					gotoxy(x + 45, y + 3 + dem); cout << msv.sv[i].ten;
					gotoxy(x + 65, y + 3 + dem); cout << msv.sv[i].phai;
					gotoxy(x + 83, y + 3 + dem); cout << msv.sv[i].password;
					dem++;
				}
			}

		}
	}
}

int xoaDauDSSV(DS_LOP& ds_lop, int vitri)
{
	NODESV* p = new NODESV;
	if (ds_lop.ds[vitri]->first == NULL)
		return 0;
	p = ds_lop.ds[vitri]->first;
	ds_lop.ds[vitri]->first = p->pNext;
	delete p;
	return 1;
}
int xoaSauNode_p(DS_LOP& ds_lop, int vitri, NODESV* sv)
{
	NODESV* q = new NODESV;
	if (sv == NULL || (sv->pNext == NULL))
		return 0;
	q = sv->pNext;
	sv->pNext = q->pNext;
	delete q;
	return 1;
}

int xoaSinhVien(DS_LOP& ds_lop, int vitri, string masv)
{
	NODESV* p = new NODESV;
	p = ds_lop.ds[vitri]->first;
	if (p == NULL)
		return 0;
	if (p->data.masv == masv)
	{
		xoaDauDSSV(ds_lop, vitri);
		return 1;
	}
	for (p = ds_lop.ds[vitri]->first; p->pNext != NULL && p->pNext->data.masv != masv; p = p->pNext);
	if (p->pNext != NULL) {
		xoaSauNode_p(ds_lop, vitri, p);
		return 1;
	}
	return 0;
}

bool KiemTraTrungSinhVien(DS_LOP& ds_lop, string masv) {
	for (int i = 0; i < ds_lop.sl; i++) {

		NODESV* temp = ds_lop.ds[i]->first;

		// Duyet tung sinh vien de kiem tra co bi trung ma
		while (temp != NULL) {
			if (temp->data.masv == masv)
				return true;
			temp = temp->pNext;
		}
	}
	return false;
}

int demSV(NODESV* p) {
	int dem = 0;
	if (p != null) {
		NODESV* node = new NODESV;
		node = p;
		while (node != null) {
			dem++;
			node = node->pNext;
		}
	}
	return dem;
}

SINHVIEN timSV(DS_LOP& ds_lop, int vitri, string maSV) {
	NODESV* temp = ds_lop.ds[vitri]->first;

	while (temp != NULL) {
		if (temp->data.masv.compare(maSV) == 0)
			return temp->data;
		temp = temp->pNext;
	}
}

int sttSV(DS_LOP& ds_lop, mSINHVIEN msv, int vitri, string maSV, int slsv) {
	mSinhVien(msv, ds_lop, vitri);
	for (int i = 0; i < slsv; i++)
	{
		if (msv.sv[i].masv == maSV) {
			return i;
		}
	}
	return -1;
}

void mSinhVien(mSINHVIEN& mSV, DS_LOP lop, int sttLop)
{
	//sapXepTheoMaSinhVien(lop, lop.ds[sttLop]->first, sttLop);
	NODESV* p = new NODESV;
	p = lop.ds[sttLop]->first;
	mSV.slsv = demSV(lop.ds[sttLop]->first);
	for (int i = 0; i < mSV.slsv; i++)
	{
		mSV.sv[i].masv = p->data.masv;
		mSV.sv[i].ho = p->data.ho;
		mSV.sv[i].ten = p->data.ten;
		mSV.sv[i].phai = p->data.phai;
		mSV.sv[i].password = p->data.password;
		mSV.sv[i].first = p->data.first;
		p = p->pNext;
	}
}

bool checkAcc(DS_LOP& ds_lop, SINHVIEN& sv, string tk, string mk) {
	for (int i = 0; i < ds_lop.sl; i++) {

		NODESV* temp = ds_lop.ds[i]->first;

		// Duyet tung sinh vien de kiem tra co bi trung ma
		while (temp != NULL) {
			if (temp->data.masv == tk && temp->data.password == mk) {
				sv = temp->data;
				return true;
			}
			temp = temp->pNext;
		}
	}
	return false;
}

NODESV* timKiemSinhVien(DS_LOP& ds_lop, int sttLop, string masv)
{
	NODESV* p = new NODESV;
	for (p = ds_lop.ds[sttLop]->first; p != NULL; p = p->pNext)
		if (p->data.masv == masv) return p;
	return NULL;
}

void hieuChinhSinhVien(DS_LOP& ds_lop, int sttLop, string masv, SINHVIEN& sv)
{
	NODESV* p = new NODESV;
	p = timKiemSinhVien(ds_lop, sttLop, masv);
	if (p == NULL)
	{
		return;
	}
	p->data.ho = sv.ho;
	p->data.ten = sv.ten;
	p->data.phai = sv.phai;
	p->data.password = sv.password;
}

bool CheckDiemSV(DS_LOP& ds_lop, string maSV) {
	for (int i = 0; i < ds_lop.sl; i++)
	{
		for (NODESV* p = ds_lop.ds[i]->first; p != null; p = p->pNext)
		{
			if ( p->data.masv.compare(maSV) == 0 && p->data.first != null)
			{
				return true;
			}
		}
	}
	return false;
}

bool camThi(DS_LOP& ds_lop, string maSV, string maMH) {
	for (int i = 0; i < ds_lop.sl; i++)
	{
		for (NODESV* p = ds_lop.ds[i]->first; p != null; p = p->pNext)
		{
			if (p->data.masv.compare(maSV) == 0 && p->data.first != null)
			{
				for (NODEDIEM* node = p->data.first; node != null; node = node->next)
				{
					if (node->data.maMh.compare(maMH) == 0)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

SINHVIEN timSV(DS_LOP& ds_lop, string maSV) {
	for (int i = 0; i < ds_lop.sl; i++)
	{
		for (NODESV* p = ds_lop.ds[i]->first; p != null; p = p->pNext)
		{
			if (p->data.masv.compare(maSV) == 0)
			{
				return p->data;
			}
		}
	}
}
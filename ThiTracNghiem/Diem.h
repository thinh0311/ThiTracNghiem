#pragma once
#include "KhaiBao.h"

NODEDIEM* khoiTaoDiem(DIEM diem) {
	NODEDIEM* node = new NODEDIEM;
	node->data = diem;
	node->next = null;
	return node;
}

void themDiem(SINHVIEN& sv, DIEM diem) {
	NODEDIEM* p = khoiTaoDiem(diem);
	if (sv.first == null)
	{
		sv.first = p;
	}
	else {
		p->next = sv.first;
		sv.first = p;
	}
}

void themDiemSV(DS_LOP& ds_lop, string maSV, DIEM diem) {
	for (int i = 0; i < ds_lop.sl; i++)
	{
		NODESV* temp = ds_lop.ds[i]->first;
		while (temp != null)
		{
			if (temp->data.masv.compare(maSV) == 0) {
				themDiem(temp->data, diem);
			}
			temp = temp->pNext;
		}
	}
}

void xuatDSDiem(DS_LOP& ds_lop, mSINHVIEN& msv, string maMH, int vitri, int slsv, int index, int x, int y) {
	string hoten;
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
				hoten = msv.sv[i].ho + " " + msv.sv[i].ten;
				gotoxy(x + 10, y + 3 + dem); cout << hoten;
				if (msv.sv[i].first == null)
				{
					gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
				}
				else {
					NODEDIEM* p = msv.sv[i].first;
					while (p != null) {
						if (p->data.maMh.compare(maMH) == 0) {
							gotoxy(x + 56, y + 3 + dem); cout << p->data.diem_thi;
							break;
						}
						p = p->next;
					}
					if (p == null)
					{
						gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
					}
				}
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
					hoten = msv.sv[i].ho + " " + msv.sv[i].ten;
					gotoxy(x + 10, y + 3 + dem); cout << hoten;
					if (msv.sv[i].first == null)
					{
						gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
					}
					else {
						NODEDIEM* p = msv.sv[i].first;
						while (p != null) {
							if (p->data.maMh.compare(maMH) == 0) {
								gotoxy(x + 56, y + 3 + dem); cout << p->data.diem_thi;
								break;
							}
							p = p->next;
						}
						if (p == null)
						{
							gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
						}
					}
					dem++;
				}
			}
			else
			{
				dem = 0;
				for (int i = index; i < index + 15; i++)
				{
					gotoxy(x + 2, y + 3 + dem); cout << i + 1;
					hoten = msv.sv[i].ho + " " + msv.sv[i].ten;
					gotoxy(x + 10, y + 3 + dem); cout << hoten;
					if (msv.sv[i].first == null)
					{
						gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
					}
					else {
						NODEDIEM* p = msv.sv[i].first;
						while (p != null) {
							if (p->data.maMh.compare(maMH) == 0) {
								gotoxy(x + 56, y + 3 + dem); cout << p->data.diem_thi;
								break;
							}
							p = p->next;
						}
						if (p == null)
						{
							gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
						}
					}
					dem++;
				}
			}

		}
	}
}

void xuatDiemSV(DS_LOP& ds_lop, string masv, MonHoc* dsmh[100], int nmh, int index, int x, int y) {
	SINHVIEN sv;
	sv = timSV(ds_lop, masv);
	int dem = 0;
	SetColor(15);
	SetBGColor(32);
	if (nmh < 15) {
		for (int i = 0; i < nmh; i++)
		{
			gotoxy(x + 2, y + 3 + dem); cout << dem + 1;
			gotoxy(x + 10, y + 3 + dem); cout << dsmh[i]->tenmh;
			if (sv.first == null)
			{
				gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
			}
			else {
				NODEDIEM* p = sv.first;
				while (p != null) {
					if (p->data.maMh.compare(dsmh[i]->mamh) == 0) {
						gotoxy(x + 56, y + 3 + dem); cout << p->data.diem_thi;
						break;
					}
					p = p->next;
				}
				if (p == null)
				{
					gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
				}
			}
			dem++;
		}
	}
	else
	{
		if (nmh - index < 15)
		{
			dem = 0;
			for (int i = index; i < nmh; i++)
			{
				gotoxy(x + 2, y + 3 + dem); cout << dem + 1;
				gotoxy(x + 10, y + 3 + dem); cout << dsmh[i]->tenmh;
				if (sv.first == null)
				{
					gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
				}
				else {
					NODEDIEM* p = sv.first;
					while (p != null) {
						if (p->data.maMh.compare(dsmh[i]->mamh) == 0) {
							gotoxy(x + 56, y + 3 + dem); cout << p->data.diem_thi;
							break;
						}
						p = p->next;
					}
					if (p == null)
					{
						gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
					}
				}
				dem++;
			}
		}
		else
		{
			dem = 0;
			for (int i = index; i < index + 15; i++)
			{
				gotoxy(x + 2, y + 3 + dem); cout << dem + 1;
				gotoxy(x + 10, y + 3 + dem); cout << dsmh[i]->tenmh;
				if (sv.first == null)
				{
					gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
				}
				else {
					NODEDIEM* p = sv.first;
					while (p != null) {
						if (p->data.maMh.compare(dsmh[i]->mamh) == 0) {
							gotoxy(x + 56, y + 3 + dem); cout << p->data.diem_thi;
							break;
						}
						p = p->next;
					}
					if (p == null)
					{
						gotoxy(x + 53, y + 3 + dem); cout << "Chua thi";
					}
				}
				dem++;
			}
		}

	}
}
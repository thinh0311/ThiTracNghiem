#pragma once
#include "khaibao.h"
#include <fstream>
#include "Student.h"
#include "Lop.h"
#include "CauHoi.h"
#include "MonHoc.h"
#include "Diem.h"

//doc file ds lop
void docFileDanhSachLop(DS_LOP& ds_lop)
{
	ifstream filein;
	filein.open("data/DanhSachLop.txt", ios_base::in);
	while (filein.eof() != true)
	{
		ds_lop.ds[ds_lop.sl] = new LOP;
		getline(filein, ds_lop.ds[ds_lop.sl]->malop, ',');
		getline(filein, ds_lop.ds[ds_lop.sl]->tenlop);
		//filein.ignore();
		if (ds_lop.ds[ds_lop.sl]->malop == "" || ds_lop.ds[ds_lop.sl]->tenlop == "")
		{
			return;
		}
		ds_lop.sl++;
	}
	filein.close();
}

void ghiFileDanhSachLop(DS_LOP& ds_lop)
{
	ofstream fileout;
	fileout.open("data/DanhSachLop.txt", ios_base::out);
	for (int i = 0; i < ds_lop.sl; i++)
	{
		if (i == ds_lop.sl - 1)
		{
			fileout << ds_lop.ds[i]->malop << "," << ds_lop.ds[i]->tenlop;
		}
		else
			fileout << ds_lop.ds[i]->malop << "," << ds_lop.ds[i]->tenlop << "\n";
	}
	fileout.close();
}

void docFileSinhVien(DS_LOP& ds_lop)
{
	ifstream filein;
	SINHVIEN sv;
	string maLop = "", tenLop = "";
	filein.open("data/DanhSachSinhVien.txt", ios_base::in);
	while (filein.eof() != true)
	{
		int slsv;
		getline(filein, maLop, ' ');
		int sttLop = timMaLop(maLop, ds_lop);
		getline(filein, tenLop, '\n');
		filein >> slsv;
		filein.ignore();
		for (int i = 0; i < slsv; i++)
		{
			getline(filein, sv.masv, ',');
			getline(filein, sv.ho, ',');
			getline(filein, sv.ten, ',');
			getline(filein, sv.phai, ',');
			getline(filein, sv.password);
			if (sv.ho == "" || sv.masv == "" || sv.password == "" || sv.ten == "" || sv.phai == "")
			{
				return;
			}
			themSinhVien(ds_lop, sv, sttLop);
		}
	}
	filein.close();
}

void  ghiSinhVien(DS_LOP ds_lop)
{
	ofstream fileout;
	int slsv;
	fileout.open("data/DanhSachSinhVien.txt", ios_base::out);
	for (int i = 0; i < ds_lop.sl; i++)
	{
		fileout << ds_lop.ds[i]->malop << " " << ds_lop.ds[i]->tenlop << "\n";
		slsv = demSV(ds_lop.ds[i]->first);
		fileout << slsv << "\n";
		NODESV* p = new NODESV;
		for (p = ds_lop.ds[i]->first; p != NULL; p = p->pNext)
		{
			fileout << p->data.masv << ",";
			fileout << p->data.ho << ",";
			fileout << p->data.ten << ",";
			fileout << p->data.phai << ",";
			if (i == ds_lop.sl - 1 && p->pNext == NULL)
			{
				fileout << p->data.password;
			}
			else
			{
				fileout << p->data.password << endl;
			}
		}
	}
	fileout.close();
}

void docFileDanhSachMonHoc(NodeMH*& root)
{
	MonHoc mh;
	ifstream filein;
	filein.open("data/DanhSachMonHoc.txt", ios_base::in);
	while (filein.eof() != true)
	{
		NodeMH* p = new NodeMH;
		getline(filein, mh.mamh, ',');
		getline(filein, mh.tenmh);
		if (mh.mamh == "" || mh.tenmh == "")
		{
			return;
		}
		p = taoNodeMonHoc(mh);
		//cout << p->data.tenmh << "\t" << p->data.mamh << endl;
		themMonHoc(root, p);
	}
	filein.close();
}

void ghiFileDanhSachMonHoc(NodeMH* root)
{
	ofstream fileout;
	MonHoc* dsmh[500];
	int nmh = 0;
	fileout.open("data/DanhSachMonHoc.txt", ios_base::out);
	tree_to_array(root, dsmh, nmh);
	for (int i = 0; i < nmh; i++)
	{
		if (i == nmh - 1)
		{
			fileout << dsmh[i]->mamh << ",";
			fileout << dsmh[i]->tenmh;
		}
		else
			fileout << dsmh[i]->mamh << "," << dsmh[i]->tenmh << endl;
	}

}

void docFileCauHoi(NodeMH*& node)
{
	CAUHOI cauhoi;
	ifstream filein;
	filein.open("data/DSCauHoi.txt", ios_base::in);
	while (filein.eof() != true)
	{
		string mMH;
		int max;
		getline(filein, mMH);
		filein >> max;
		filein.ignore();
		for (int i = 0; i < max; i++)
		{
			getline(filein, cauhoi.noiDung);
			getline(filein, cauhoi.dapAnA);
			getline(filein, cauhoi.dapAnB);
			getline(filein, cauhoi.dapAnC);
			getline(filein, cauhoi.dapAnD);
			getline(filein, cauhoi.dapAnDung);
			duyetDeThemCauHoi(node, mMH, cauhoi);
		}
	}
	filein.close();
}

void ghiFileDSCauHoi(NodeMH* root)
{
	ofstream fileout;
	MonHoc* dsmh[500];
	int nmh = 0;
	fileout.open("data/DSCauHoi.txt", ios_base::out);
	tree_to_array(root, dsmh, nmh);
	for (int i = 0; i < nmh; i++)
	{
		fileout << dsmh[i]->mamh << "\n";
		fileout << dsmh[i]->dscauhoi->sl << endl;
		if (dsmh[i]->dscauhoi->sl == 0) {

		}
		else {
			for (int j = 0; j < dsmh[i]->dscauhoi->sl; j++)
			{
				fileout << dsmh[i]->dscauhoi->ds[j].noiDung << endl;
				fileout << dsmh[i]->dscauhoi->ds[j].dapAnA << endl;
				fileout << dsmh[i]->dscauhoi->ds[j].dapAnB << endl;
				fileout << dsmh[i]->dscauhoi->ds[j].dapAnC << endl;
				fileout << dsmh[i]->dscauhoi->ds[j].dapAnD << endl;
				if (i == nmh - 1)
				{
					if (j == dsmh[i]->dscauhoi->sl - 1)
					{
						fileout << dsmh[i]->dscauhoi->ds[j].dapAnDung;
					}
					else
					{
						fileout << dsmh[i]->dscauhoi->ds[j].dapAnDung << endl;
					}
				}
				else {
					fileout << dsmh[i]->dscauhoi->ds[j].dapAnDung << endl;
				}
			}
		}
	}
	fileout.close();
}

void docFileDiem(DS_LOP& ds_lop, NodeMH* root) {
	DIEM diem;
	ifstream filein;
	string maLop, maSV;
	int i;
	filein.open("data/DSDiem.txt", ios_base::in);
	while (!filein.eof())
	{
		filein >> i;
		filein.ignore();
		getline(filein, maSV, ',');
		for (NODESV* p = ds_lop.ds[i]->first; p != null; p = p->pNext)
		{
			if (maSV.compare(p->data.masv) == 0) {
				getline(filein, diem.maMh, ',');
				filein >> diem.diem_thi;
				filein.ignore();
				themDiem(p->data, diem);
			}
		}
	}
	filein.close();
}

void ghiFileDiem(DS_LOP& ds_lop) {
	ofstream fileout;
	fileout.open("data/DSDiem.txt", ios::out);
	for (int i = 0; i < ds_lop.sl; i++)
	{
		NODESV* p = new NODESV;
		for (p = ds_lop.ds[i]->first; p != null; p = p->pNext)
		{
			NODEDIEM* NODED = p->data.first;
			while (NODED != null)
			{
				fileout << i << ",";
				fileout << p->data.masv << ",";
				fileout << NODED->data.maMh << ",";
				fileout << NODED->data.diem_thi<< "\n";
				NODED = NODED->next;
			}
		}
	}
	fileout.close();
}

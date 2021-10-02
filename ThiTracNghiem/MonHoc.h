#pragma once
#include "KhaiBao.h"
#include "ChucNang.h"
#include "CauHoi.h"
#include <cstring>
#include <string.h>

void themMonHoc(NodeMH*& node, NodeMH* temp);
void hieuChinhMonHoc(NodeMH*& node, NodeMH* temp);
NodeMH* xoaMonHoc(NodeMH* node, char* mMH);
void tree_to_array(NodeMH* root, MonHoc* dsmh[], int& nmh);
int countMonHoc(NodeMH* root);

NodeMH* taoNodeMonHoc(MonHoc mH) {
	NodeMH* node = new NodeMH;
	node->data = mH;
	node->left = null;
	node->right = null;
	return node;
}

void themMonHoc(NodeMH*& node, NodeMH* temp) {
	if (node == null) {
		node = temp;
	}
	else if (node->data.mamh.compare(temp->data.mamh) >= 0) {
		themMonHoc(node->right, temp);
	}
	else if (node->data.mamh.compare(temp->data.mamh) < 0) {
		themMonHoc(node->left, temp);
	}
}

void hieuChinhMonHoc(NodeMH*& node, NodeMH* temp) {
	if (node->data.mamh.compare(temp->data.mamh) > 0) {
		hieuChinhMonHoc(node->right, temp);
	}
	else if (node->data.mamh.compare(temp->data.mamh) < 0) {
		hieuChinhMonHoc(node->left, temp);
	}
	else if (node->data.mamh.compare(temp->data.mamh) == 0) {
		node->data = temp->data;
	}
}

NodeMH* xoaMonHoc(NodeMH* node, string mMH) {
	if (node == null)
	{
		return node;
	}
	else if (node->data.mamh.compare(mMH) == 0)
	{
		if (node->data.dscauhoi->ds != null)
		{
			messeger(15, 30, 50, 3, 12, "Khong the xoa mon hoc nay !", DELAY);
			return node;
		}
		else {
			if (node->left == null && node->right == null)
			{
				node = null;
				messeger(15, 30, 50, 3, 2, "Xoa thanh cong", DELAY);
			}
			else if (node->left != null && node->right != null)
			{
				NodeMH* nodeTheThan = node->right;
				while (nodeTheThan->left != null)
				{
					nodeTheThan = nodeTheThan->left;
				}
				node->data = nodeTheThan->data;
				xoaMonHoc(node->right, mMH);
				return node;
			}
			else if (node->right != null)
			{
				return node->right;
			}
			else
			{
				return node->left;
			}
		}
	}
	else if (node->data.mamh.compare(mMH) > 0)
	{
		node->right = xoaMonHoc(node->right, mMH);
	}
	else if (node->data.mamh.compare(mMH) < 0)
	{
		node->left = xoaMonHoc(node->left, mMH);
	}
	return node;
}

void duyetDeThemCauHoi(NodeMH*& node, string mMH, CAUHOI cauhoi) {
	if (node->data.mamh.compare(mMH) > 0) {
		duyetDeThemCauHoi(node->right, mMH, cauhoi);
	}
	else if (node->data.mamh.compare(mMH) < 0) {
		duyetDeThemCauHoi(node->left, mMH, cauhoi);
	}
	else if (node->data.mamh.compare(mMH) == 0) {
		themCauHoi(node, mMH, cauhoi);
	}
}

void hienthi(NodeMH* node,CAUHOI CH[], string mamh, int& sl) {
	if (node->data.mamh.compare(mamh) == 0)
	{
		if (node->data.dscauhoi != null) {
			for (int i = 0; i < node->data.dscauhoi->sl; i++) {
				CH[i] = node->data.dscauhoi->ds[i];
			}
			sl = node->data.dscauhoi->sl;
		}
	}
}

void xuatDSMH(NodeMH*& root, MonHoc* dsmh[500], int nmh, int index, int x, int y)
{
	if (root == null)
	{
		gotoxy(100, 15); cout << "danh sach rong";
		return;
	}
	else {
		int dem = 0;
		SetColor(15);
		SetBGColor(32);
		if (nmh < 15) {
			for (int i = 0; i < nmh; i++)
			{
				gotoxy(x + 2, y + 3 + i); cout << i + 1;
				gotoxy(x + 15, y + 3 + i); cout << dsmh[i]->mamh;
				gotoxy(x + 45, y + 3 + i); cout << dsmh[i]->tenmh;
			}
		}
		else
		{
			if (nmh - index < 15)
			{
				dem = 0;
				for (int i = index; i < nmh; i++)
				{
					gotoxy(x + 2, y + 3 + dem); cout << i + 1;
					gotoxy(x + 15, y + 3 + dem); cout << dsmh[i]->mamh;
					gotoxy(x + 45, y + 3 + dem); cout << dsmh[i]->tenmh;
					dem++;
				}
			}
			else
			{
				dem = 0;
				for (int i = index; i < index + 15; i++)
				{
					gotoxy(x + 2, y + 3 + dem); cout << i + 1;
					gotoxy(x + 15, y + 3 + dem); cout << dsmh[i]->mamh;
					gotoxy(x + 45, y + 3 + dem); cout << dsmh[i]->tenmh;
					dem++;
				}
			}

		}
	}
}

void duyetCayDeHienThi(NodeMH* root,CAUHOI CH[], string maMH, int& sl) {
	if (root != null) {
		duyetCayDeHienThi(root->right,CH, maMH, sl);
		hienthi(root,CH, maMH, sl);
		duyetCayDeHienThi(root->left, CH,maMH, sl);
	}
}

MonHoc* Search(NodeMH* root, string str)
{
	if (root == null) {
		return null;
	} else if (root->data.mamh.compare(str) == 0) {
		return &(root->data);
	}
	else if (root->data.mamh.compare(str) < 0 ) {
		return Search(root->left, str);
	}
	else if (root->data.mamh.compare(str) > 0) {
		return Search(root->right, str);
	}
}

void tree_to_array(NodeMH* root, MonHoc* dsmh[], int& nmh)
{
	if (root != NULL)
	{
		dsmh[nmh] = new MonHoc;
		dsmh[nmh]->mamh = root->data.mamh;
		dsmh[nmh]->tenmh = root->data.tenmh;
		if (root->data.dscauhoi != null)
		{
			dsmh[nmh]->dscauhoi = root->data.dscauhoi;
		}
		else {
			DSCAUHOI* dsch = new DSCAUHOI;
			dsmh[nmh]->dscauhoi = dsch;
		}
		nmh++;
		tree_to_array(root->left, dsmh, nmh);
		tree_to_array(root->right, dsmh, nmh);
	}
	else {
		return;
	}
}

int countMonHoc(NodeMH* root)
{
	const int STACKSIZE = 500;
	NodeMH* Stack[STACKSIZE];
	NodeMH* p = new NodeMH;
	p = root;
	int i = 0;
	int sp = -1;	// Khoi tao Stack rong
	do
	{
		while (p != NULL)
		{
			Stack[++sp] = p;
			p = p->left;
		}
		if (sp != -1)
		{
			p = Stack[sp--];
			i++;
			p = p->right;
		}
		else
			break;
	} while (1);
	return i;
}

void layCauHoiMH(NodeMH* root, DSCAUHOI*& dsch, string maMH) {
	MonHoc* dsmh[500];
	int nmh = 0;
	tree_to_array(root, dsmh, nmh);
	for (int i = 0; i < nmh; i++)
	{
		if (dsmh[i]->mamh == maMH) {
			dsch = dsmh[i]->dscauhoi;
		}
	}
}

bool camXoa(DS_LOP& ds_lop, string maMH) {
	for (int i = 0; i < ds_lop.sl; i++)
	{
		for (NODESV* p = ds_lop.ds[i]->first; p != null; p = p->pNext)
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
	return false;
}

bool ktraCauHoi(NodeMH* root, string str) {
	if (root == null) {
		return false;
	}
	else if (root->data.mamh.compare(str) == 0 && root->data.dscauhoi != null) {
		return true;
	}
	else if (root->data.mamh.compare(str) < 0) {
		return Search(root->left, str);
	}
	else if (root->data.mamh.compare(str) > 0) {
		return Search(root->right, str);
	}
}
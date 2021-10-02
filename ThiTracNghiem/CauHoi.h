#pragma once
#include "KhaiBao.h"
#include <cstdlib>

//void themCauHoi(NodeMH*& node, CAUHOI& cauhoi) {
//	// noi dung ,a,b,c,d,dap an lay tu giao dien
//	if (node != null) {
//		if (node->data.dscauhoi != null) {
//			node->data.dscauhoi->ds[node->data.dscauhoi->sl] = cauhoi;
//			node->data.dscauhoi->sl++;
//		}
//		else {
//			DSCAUHOI* ds = new DSCAUHOI;
//			ds->ds[ds->sl] = cauhoi;
//			ds->sl++;
//			node->data.dscauhoi = ds;
//		}
//
//	}
//}

void themCauHoi(NodeMH*& node, string mMH, CAUHOI cauhoi) {
	// noi dung ,a,b,c,d,dap an lay tu giao dien
	if (node != NULL) {
		if (node->data.dscauhoi != NULL) {
			node->data.dscauhoi->ds[node->data.dscauhoi->sl] = cauhoi;
			node->data.dscauhoi->sl++;
		}
		else {
			DSCAUHOI* ds = new DSCAUHOI;
			ds->ds[ds->sl] = cauhoi;
			ds->sl++;
			node->data.dscauhoi = ds;
		}
	}
}

void Swap(int* number_1, int* number_2)
{
	int temp = *number_1;
	*number_1 = *number_2;
	*number_2 = temp;
}

void dayNgauNhien(int* arr, int slCH)
{
	for (int i = 0; i < slCH; i++)
	{
		arr[i] = i;
	}
	srand(time(NULL));
	int min = 0;
	int max = slCH - 1;
	int swapPosition;

	int i = 0;
	while (i < slCH - 1)
	{
		min = i + 1;
		swapPosition = rand() % (max - min + 1) + min;
		Swap(&arr[i], &arr[swapPosition]);
		i++;
	}
}

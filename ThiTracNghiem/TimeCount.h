#pragma once
#include "mylib.h"
#include "GiaoDien.h"
#include <iostream>
#include <thread>

int stop = 0;
void run() {
	char kt;
	while ((kt = _getch()) != 27 && stop == 0) {
		gotoxy(0, 1);   cout << kt;
	}
	stop = 1;
}
void startTimerJob(int time_in_second) {
	SetColor(2);
	while (time_in_second >= 0 && stop == 0) {
		if (time_in_second % 60 >= 10)
		{
			gotoxy(119, 4); cout << time_in_second / 60 << " : " << time_in_second % 60 ;
			Sleep(980);		time_in_second -= 1;
		} else if (time_in_second % 60 < 10)
		{
			gotoxy(119, 4); cout << time_in_second / 60 << " : 0" << time_in_second % 60;
			Sleep(980);		time_in_second -= 1;
		}
	}
	if (stop == 0) { 
		system("cls");
		ketThucThi(60, 10, "Het thoi gian lam bai !!"); 
		return;
	}
	else {
		stop = 1;
	}
}
void startTimer(int soPhut) {
	thread timer;
	timer = thread(startTimerJob,  soPhut*60); // tao luong cho CTC startTimerJob chay trong 5 giay
	run();  // luong chuong trinh chinh cua ta
	timer.join(); // ket thuc luong cap cho CTC startTimerJob
}

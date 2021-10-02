#pragma once
#include <iostream>
#include <conio.h>
#include "mylib.h"
#include <string.h>
#include "const.h"

using namespace std;

string text = "";
int bd = 0;
int kt = 0;
int dem = 0;
char input;


void printText(int x, int y, int maxw, int type_frame) {
	gotoxy(x + 2, y + 1);
	if (text.size() < maxw - 2)
	{
		bd = 0;
		kt = text.size();
	}
	if (type_frame == type_input) {
		for (int i = bd; i < kt; i++)
		{
			cout << text[i];
		}
	}
	else if (type_frame == type_password) {
		for (int i = bd; i < kt; i++)
		{
			cout << "*";
		}
	}

}

void inputText(int x, int y, int maxw, int rule, string str, int index, int type_frame) {
	resetInput(x, y, maxw, 3, 9);
	gotoxy(x + 2, y + 1);
	text = str;
	if (!text.empty())
	{
		if (text.size() < maxw - 2)
		{
			bd = 0;
			kt = text.size();
			gotoxy(x + text.size(), y);
		}
		else
		{
			kt = text.size();
			bd = kt - maxw + 3;
			gotoxy(x + maxw, y);
		}
		printText(x, y, maxw, type_frame);
	}
	bool loop = true;
	while (loop)
	{
		if (_kbhit()) {
			input = _getch();
			if (input == -32) {
				input = _getch();
				switch (input)
				{
				case ARROW_DONW:
				{
					resetInput(x, y, maxw, 3, 13);
					printText(x, y, maxw, type_frame);
					loop = false;
					dem++;
					if (dem > index - 1) dem = 0;
					break;
				}
				case ARROW_UP:
				{
					resetInput(x, y, maxw, 3, 13);
					printText(x, y, maxw, type_frame);
					loop = false;
					dem--;
					if (dem < 0) dem = index - 1;
					break;
				}
				case ARROW_RIGHT:
				{
					
					break;
				}
				case ARROW_LEFT:
				{
					
					break;
				}
				}
			}
			else if (input == 13)
			{
				loop = false;
			}
			else if (input == 8)
			{
				if (rule == rule_cam) {

				}
				else if (!text.empty())
				{
					if (text.size() < maxw - 1)
					{
						text.pop_back();
						printText(x, y, maxw, type_frame);
						kt--;
						cout << " ";
						gotoxy(x + text.size() + 2, y + 1);
					}
					else
					{
						text.pop_back();
						gotoxy(x + maxw-1, y+1);
						cout << ' ';
						bd--;
						kt--;
						printText(x, y, maxw - 2, type_frame);
					}
				}
			}
			else if (input == 27)
			{
				resetInput(x, y, maxw, 3, 13);
				printText(x, y, maxw, type_frame);
				ShowCursor(false);
				return;
			}
			else if (input >= 32 && input <= 128)
			{
				if (rule == rule_tudo)		//tu do
				{
					text += input;
				}
				else if (rule == rule_ho)	// ho
				{
					if (text.size() == 0)
					{
						if (input != 32)
						{
							if (input >= 97 && input <= 122)
							{
								input -= 32;
								text += input;
							}
							else if (input >= 65 && input <= 90)
							{
								text += input;
							}
						}
						//text += input;
					}
					else if (text.back() == 32)
					{
						if (input != 32)
						{
							if (input >= 97 && input <= 122)
							{
								input -= 32;
								text += input;

							}
							else if (input >= 65 && input <= 90)
							{
								text += input;
							}
						}
					}
					else
					{
						if ((input >= 97 && input <= 122) || (input == 32))
						{
							text += input;
						}
						else if (input >= 65 && input <= 90)
						{
							input += 32;
							text += input;
						}
					}
				}
				else if (rule == rule_mamh)  // ma mon hoc
				{	
					if (text.size() < 15)
					{
						if (input >= 97 && input <= 122)
						{
							input -= 32;
							text += input;
						}
						else if ((input >= 48 && input <= 57) || (input >= 65 && input <= 90))
						{
							text += input;
						}
					}
				}
				else if (rule == rule_masv) //ma sv
				{
					if (text.size() < 15)
					{
						if (input >= 97 && input <= 122)
						{
							input -= 32;
							text += input;
						}
						else if ((input >= 48 && input <= 57) || (input >= 65 && input <= 90) || (input == 45))
						{
							text += input;
						}
					}
				}
				else if (rule == rule_ten)
				{
					if (text.size() < 15)
					{
						if (input != 32)
						{
							if (text.size() == 0)
							{
								if (input >= 97 && input <= 122)
								{
									input -= 32;
									text += input;
								}
								else if (input >= 65 && input <= 90)
								{
									text += input;
								}
							}
							else
							{
								if (input >= 97 && input <= 122)
								{
									text += input;
								}
								else if (input >= 65 && input <= 90)
								{
									input += 32;
									text += input;
								}
							}
						}
					}
				}
				else if (rule == rule_so)
				{
					if (text.size() < 3)
					{
						if (input >= 48 && input <= 57)
							text += input;
					}
				}
				else if (rule == rule_tenmh)
				{
					if (text.size() < 30)
					{
						if (text.size() == 0)
						{
							if (input >= 97 && input <= 122)
							{
								input -= 32;
								text += input;
							}
							else if ((input >= 48 && input <= 57) || (input >= 65 && input <= 90))
							{
								text += input;
							}
						}
						else if (text.back() == 32)
						{
							if (input != 32)
							{
								if (input >= 97 && input <= 122)
								{
									input -= 32;
									text += input;

								}
								else if ((input >= 48 && input <= 57) || (input >= 65 && input <= 90))
								{
									text += input;
								}
							}
						}
						else
						{
							if ((input >= 48 && input <= 57) || (input >= 97 && input <= 122) || (input == 32))
							{
								text += input;
							}
							else if (input >= 65 && input <= 90)
							{
								input += 32;
								text += input;
							}
						}
					}
				}

				if (text.size() >= maxw - 2)
				{
					bd++;
					kt++;
				}
				printText(x, y, maxw, type_frame);
			}
		}
	}
}



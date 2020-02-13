#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include <fstream>
using namespace std;
class CRegister {
private:
	string name;
	char MobileNumber[11];
	char IDNumber[18];
	string Password;
public:
	CRegister() {
		registName();
        registNu();
	    registPW();
		registID();
	};
	void registName() {
		char N[100];
		cout << "请输入你的姓名,按Enter结束";
		cin.getline(N, 100);
		ofstream OpenFile;
		OpenFile.open("UserInformation1.txt", ios::app);
		OpenFile << N << endl;
		OpenFile.close();
	}
	void registNu() {
		char Nu[100];
		cout << "请输入你的电话号码";
		cin.getline(Nu, 100);
		ofstream OpenFile;
		OpenFile.open("UserInformation1.txt", ios::app);
		OpenFile << Nu << endl;

		OpenFile.close();
	}
	void registID() {
		char ID[100];
		cout << "请输入你的身份证号";
		cin.getline(ID, 100);//cin.getline()返回cin类型，而cin.get()表示清空缓冲区内容
		ofstream OpenFile;
		OpenFile.open("UserInformation1.txt", ios::app);
		if (OpenFile.fail()) {
			cout << "打开文件错误" << endl;
		}
		//按q退出
		if (strcmp(ID, "q") != 0) {
			OpenFile << ID << endl;
		}
		OpenFile.close();
	}
	void registPW() {
		char PW[100];//输入密码
		char RPW[100];//确认密码
		cout << "请输入密码";
		cin.getline(PW, 100);
		cout << "请确认密码";
		cin.getline(RPW, 100);
		ofstream OpenFile;
		if (strcmp(PW, RPW) == 0) {

			OpenFile.open("UserInformation1.txt", ios::app);
			OpenFile << PW << endl;
		}
		else {
			cout << "密码不一致";
			system("pause");
			registPW();
		}
		OpenFile.close();
	}
};


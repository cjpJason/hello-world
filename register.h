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
		cout << "�������������,��Enter����";
		cin.getline(N, 100);
		ofstream OpenFile;
		OpenFile.open("UserInformation1.txt", ios::app);
		OpenFile << N << endl;
		OpenFile.close();
	}
	void registNu() {
		char Nu[100];
		cout << "��������ĵ绰����";
		cin.getline(Nu, 100);
		ofstream OpenFile;
		OpenFile.open("UserInformation1.txt", ios::app);
		OpenFile << Nu << endl;

		OpenFile.close();
	}
	void registID() {
		char ID[100];
		cout << "������������֤��";
		cin.getline(ID, 100);//cin.getline()����cin���ͣ���cin.get()��ʾ��ջ���������
		ofstream OpenFile;
		OpenFile.open("UserInformation1.txt", ios::app);
		if (OpenFile.fail()) {
			cout << "���ļ�����" << endl;
		}
		//��q�˳�
		if (strcmp(ID, "q") != 0) {
			OpenFile << ID << endl;
		}
		OpenFile.close();
	}
	void registPW() {
		char PW[100];//��������
		char RPW[100];//ȷ������
		cout << "����������";
		cin.getline(PW, 100);
		cout << "��ȷ������";
		cin.getline(RPW, 100);
		ofstream OpenFile;
		if (strcmp(PW, RPW) == 0) {

			OpenFile.open("UserInformation1.txt", ios::app);
			OpenFile << PW << endl;
		}
		else {
			cout << "���벻һ��";
			system("pause");
			registPW();
		}
		OpenFile.close();
	}
};


#pragma once
#pragma once
#include<iostream>
#include<stdio.h>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include"CUser.h"
using namespace std;
class CLogin {
private:

public:
	CLogin() {
		Login();
	}
	void Login() {
		char input[100];//�û������ֻ��ţ��ֻ�����Ϊ��¼�˺ţ�
		char data[100];//��ʾtxt�ļ��ڵ��ֻ���
		char password[100];//�û�����
		char PW[100];//���ݿ�������
		static int flag=0;//��־�Ƿ��ҵ���Ӧ�ֻ���
		cout << "�������ֻ���";
		cin.getline(input, 100);
		ifstream infile;
		infile.open("UserInformation1.txt");
		if (!infile)cout << "error" << endl;//�򲻿��ļ��ͱ���һ��û�ã�
		while (infile.getline(data, 100)) {//���ж�ȡ
			if (strcmp(data, input) == 0) {//�ж��ֻ����Ƿ��Ӧ����Ӧ�����¶�һ����Ϊ����
				flag= 1;//�ҵ���Ӧ�˺ţ�flag���1
				cout << "����������"<<endl;
				cin.getline(password, 100);
				infile.getline(PW, 100);
				if (strcmp(PW, password) == 0) {//������ȷ�������¼
					infile.close();
					cout << "������ȷ";
					flag = 1;
					//�ҵ��ֻ��Ŷ�Ӧ������
					CUser user(findname(data),PW);//�����û�����
				}//����if����
			}//�˻�if����
		}//while����
		infile.close();
		if (flag == 0) 
			cout << "�û������󣬰�q�˳��������������ʹ��" << endl;
		else{
			flag = 0;
			cout << "�û���¼"<<endl<<"��q�˳��������������ʹ��";
		}
		char temp = 'q';
		char ch = _getche();
		if (ch == temp) {
			return;
		}
		else {
			Login();
		}
	}
	char* findname(char* a) {
		ifstream infile;
		infile.open("UserInformation1.txt");
		char name[100], temp[100];
		int i = 2;
		//����ѭ�����棬temp1��temp2��������һ�����ݣ��ʻ�Ϊ��һ��
		while (infile.getline(temp, 100)) {//����txt�ļ�����
			char temp1[100], temp2[100];
			if (i % 2 == 0) {
				if (strcmp(temp, a) == 0) {
					for (int j = 0; j < 100; ++j)
						name[j] = temp2[j];
					return name;
				}
				for (int n = 0; n < 100; ++n)
					temp1[n] = temp[n];
				++i;
			}
			if (i % 2 == 1) {
				if (strcmp(temp, a) == 0) {
					for (int j = 0; j < 100; ++j)
						name[j] = temp1[j];
					return name;
				}
				for (int n = 0; n < 100; ++n)
					temp2[n] = temp[n];
				++i;
			}
		}//while����
	}//findname����
};
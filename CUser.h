#pragma once
#pragma once
#include<iostream>
#include <fstream>
#include<conio.h>
#include"C:\Users\10561\source\repos\LibrarySystem-master\findbook.h"
#include"CModify.h"
using namespace std;
class CUser {
private:
	char UserName[100];
	char Password[100];
public:
	CUser(char a[100],char b[100]) {
		for (int i = 0; i < 100; ++i) {
			UserName[i] = a[i];//�����˺ţ���Ȼ�������ʲô�ã�
			Password[i] = b[i];
		}//forѭ������
//�û����棬�����в���ͼ�顢����ͼ�顢�޸�����
		User(UserName);//�û����溯��
	}
	void User(char* name) {
		while (*name) {
			putchar(*name++);
		}
		cout << "ͬѧ����ã���ӭʹ��ͼ�����ϵͳ����ѡ������Ҫ�Ĺ���" << endl;
		cout << "1�������鼮" << endl;
		cout << "2�������鼮" << endl;
		cout << "3���޸�����" << endl;
		cout << "4���˳�" << endl;
		int t=_getche();
		if (t == 49) {
			cout << "�����鼮";
			findbook();
		}
		if (t == 50) {
			cout << "�����鼮";
			borrowbook();
		}
		if (t == 51) {
			cout << "�޸�����";
			CModify::CModify(Password);
		}
		if (t == 52) {
			cout << "�˳�"<<endl;
			return;
		}
	}
};
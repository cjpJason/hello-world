#pragma once
#include<iostream>
#include<fstream>
#include <string.h>
#include"CUser.h"
//���ļ��޸����룬�޸�˼·�����ļ�1�����ݶ�ȡ���ļ�2��������Ҫ�޸ĵ����޸ģ�
//Ȼ������ļ�1���ٽ��ļ�2���ݸ��Ƶ��ļ���1
class CModify {
private:
	char password[100];
	char data[100];
public:
	CModify(char a[100]) {
		for (int i = 0; i < 100; ++i) {
			password[i] = a[i];
		}
		ifstream infile;
		infile.open("UserInformation1.txt");
		ofstream outfile;
		outfile.open("UserInformation2.txt",ios::ate);
		if (!infile)cout << "error" << endl;
		//��ȷ������
		cout << "������ԭ����";
		char temp[100];
		cin.getline(temp, 100);
		if (strcmp(password, temp) == 0) {//������ȷ�������޸�����
			cout << "��������Ҫ�޸ĵ�����";
			char temp1[100];
			cin.getline(temp1, 100);
			while (infile.getline(data, 100)) {
				if (strcmp(data,password)==0) {//�ҵ���������λ��
					strncpy_s(data, temp1,100);
					outfile << data << endl;
					continue;
				}//if������
				outfile << data << endl;
			}//while������
			infile.close();
			outfile.close();
			ifstream in;
			ofstream out;
			in.open("UserInformation2.txt");
			out.open("UserInformation1.txt",ios::ate);
			while (in.getline(data, 100)) {
				out << data << endl;
			}
			in.close();
			out.close();
			cout << endl;
			
		}
	}
};
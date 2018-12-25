
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct data {
	string ID;//���
	string name;//����
	string link;//��ϵ��ʽ
	string position;//��������
};
struct data *lb = new struct data[100];
int index;

class Manage {
protected:
public:
	void read_data() {//��ȡ�ļ�����
		int i = 0;
		ifstream fin("D:\\Manager_sisterm.dat", ios::in | ios::binary);//�����Ʒ�ʽ���ļ�
		if (!fin.is_open()) {
			cout << "���ܴ��ļ���D:\\Manager_sisterm.dat\n";
			exit(1);
		}
		while (!fin.eof()){
			fin >> lb[i].ID >> lb[i].name;
			fin >> lb[i].link >> lb[i].position;
			i++;
		} 
		index = i-1;
		fin.close();
	}

	void save_data() {//�������ݵ��ļ�
		int i;
		ofstream fout("D:\\Manager_sisterm.dat", ios::out | ios::binary|ios::trunc);
		if (!fout) {//���������ļ�
			cout << "���ܴ��ļ���D:\\Manager_sisterm.dat\n";
			exit(1);
		}
		for (i = 0; i < index; i++) {
			fout << lb[i].ID << "	" << lb[i].name << "	";
			fout << lb[i].link << " 	  " << lb[i].position << "\r\n";
		}
		fout << '\0';
		fout.close();
	}
	void delete_data() {//���ݱ��ɾ����Ա��Ϣ
	//	system("cls");
		read_data();
		char c;
	
		do {
			string del;
			cout << "������Ҫɾ����Ա�ı�ţ�" << endl;
			cin >> del;
			int i = 0;
			while (lb[i].ID != del&&i < index) //����Ҫɾ������Ա��
				i++;
			if (lb[i].ID == del) {
				for (int j = i; j < index - 1; j++) {
					lb[j].ID = lb[j + 1].ID;
					lb[j].name = lb[j + 1].name;
					lb[j].link = lb[j + 1].link;
					lb[j].position = lb[j + 1].position;

				}
				cout << "ɾ���ɹ�!" << endl;
				index = index - 1;
			}
			else if (i == index) {
				cout << "���޴��ˣ����������Ƿ���ȷ��" << endl;
			}
			cout << "�Ƿ����ɾ������y/n��" << endl;
			cin >> c;
		} while (c=='y'||c=='Y');
		save_data();//ɾ��������ݱ��浽�ļ�
	}
	void add_data() {//�����Ա��Ϣ
	//	system("cls");
		read_data();
		char c;
		int i = 0;
		do {
			string ad;
			cout << "������µ���Ա��Ϣ" << endl;
			cout << "��������Ա���:" << endl;
			cin >> ad;
			while (lb[i].ID != ad&&i < index) { //�鿴Ҫ��ӵ���Ա�Ƿ����
				i++;
			}
			if (lb[i].ID == ad) {
				cout << "����Ա��Ϣ�Ѵ���";
				
			}
			else {
				//index++;//����������������м������
				lb[index].ID = ad;
				cout << "��������Ա����:" << endl;
				cin >> lb[index].name;
				cout << "��������ϵ��ʽ:" << endl;
				cin >> lb[index].link;
				cout << "��������������:" << endl;
				cin >> lb[index].position;
				index++;
			}
			cout << "(�Ƿ����������(y/n))" << endl; 
			cin >> c;

		} while (c == 'y' || c == 'Y');
		save_data();
	}
	void change_data() {//�޸���Ա��Ϣ
	//	system("cls");
		read_data();
		string id;
		int i = 0;
		char c;
		do {
			cout << "������Ҫ�޸ĵ���Ա���:" << endl;
			cin >> id;
			while (lb[i].ID != id&&i < index) //����Ҫ�޸ĵ���Ա��
				i++;
			if (i == index) {
				cout << "���޴��ˣ����������Ƿ���ȷ��" << endl;
			}
			else if (lb[i].ID == id) {
				cout << "�������޸ĺ�ı�ţ�" << endl;
				cin >> lb[i].ID;
				cout << "�������޸ĺ��������" << endl;
				cin >> lb[i].name;
				cout << "�������޸ĺ����ϵ��ʽ��" << endl;
				cin >> lb[i].link;
				cout << "�������޸ĺ�Ĳ������ƣ�" << endl;
				cin >> lb[i].position;
			}
			cout << "�Ƿ�����޸ģ���y/n��" << endl;
			cin >> c;
		} while (c == 'y' || c == 'Y');
		save_data();
	}
	void print_data() {//��ӡȫ����Ա��Ϣ
		 //���ļ���ȡ
	//	system("cls");
		ifstream infile("D:\\Manager_sisterm.dat", ios::in | ios::binary);
		if (!infile) {
			cout << "���ܴ������ļ���D:\\Manager_sisterm.dat\n";
			exit(1);
		}
		//�õ��ļ����ȣ�
		infile.seekg(0, ios::end);
		int length = infile.tellg();//���ض�ָ���λ�ã�
		infile.seekg(0, ios::beg);
		char *r;
		r = new char[length];

		cout << "�ļ���ȡ�����" << endl;
		cout << "���" << '	' << "����" << '	' << "��ϵ��ʽ" << '	' << "��������" << endl;
		infile.read(r, length);
		cout << r;
		infile.close();
	}
	void find_data() {//������������ţ���ϵ��ʽ���в�ѯ
	//	system("cls");
		read_data();
		string find;
		char c;
		do{
			cout << "������Ҫ������Ա����������Ż���ϵ��ʽ)" << endl;
			cin >> find;
			int flag = 0;
			for (int i = 0; i < index; i++) {
				if (lb[i].ID == find) {
					flag = 1;
					cout << "����Ա���й���Ϣ���£�" << endl;
					cout << "��ţ�	" << lb[i].ID << endl;
					cout << "������	" << lb[i].name << endl;
					cout << "��ϵ��ʽ��" << lb[i].link << endl;
					cout << "�������ţ�" << lb[i].position << endl;
					break;
				}else if (lb[i].name == find) {
					flag = 1;
					cout << "����Ա���й���Ϣ���£�" << endl;
					cout << "��ţ�	" << lb[i].ID << endl;
					cout << "������	" << lb[i].name << endl;
					cout << "��ϵ��ʽ��" << lb[i].link << endl;
					cout << "�������ţ�" << lb[i].position << endl;
					break;
				}
				else if (lb[i].link == find) {
					flag = 1;
					cout << "����Ա���й���Ϣ���£�" << endl;
					cout << "��ţ�	" << lb[i].ID << endl;
					cout << "������	" << lb[i].name << endl;
					cout << "��ϵ��ʽ��" << lb[i].link << endl;
					cout << "�������ţ�" << lb[i].position << endl;
					break;
				}				
			}
			if (flag == 0) {
				cout << "δ�ҵ�����Ա��Ϣ��" << endl;
			}			
			cout << "�Ƿ������ѯ��(y/n)" << endl;
			cin >> c;
		}while(c == 'y' || c == 'Y');
	}
	void count_data() {//ͳ�ƹ�˾�����Լ�����������
	//	system("cls");
		read_data();
		string find;
		int n;
		cout << "������Ҫͳ�������Ĳ���������" << endl;
		cin >> n;
		for (int j = 0; j < n; j++) {
			cout << "������Ҫͳ�������Ĳ������ƣ�" << endl;
			cin >> find;
			int num = 0;
			for (int i = 0; i < index; i++) {
				if (lb[i].position == find) {
					num++;
				}
			}
			cout << find << "����" << num << "��" << endl;
		}		
		cout << "��˾��������" << index << endl;
	}
	void rank_data() {//����������
	//	system("cls");
		read_data();
		string rank;
		int n = 0;
		char c;
		do {
			struct data *ran = new struct data[50];
			cout << "������Ҫ����Ĳ������ƣ�" << endl;
			cin >> rank;
			for (int i = 0; i < index; i++) {
				if (lb[i].position == rank) {
					ran[n].ID = lb[i].ID;
					ran[n].name = lb[i].name;
					ran[n].link = lb[i].link;
					ran[n].position = lb[i].position;
					n++;
				}
			}
			for (int j = 0; j < n - 1; j++) {//ÿһ���˸������˶���һ��
				for (int i = 0; i < n - 1 - j; i++) {
					if (ran[i].ID > ran[i + 1].ID) {
						swap(ran[i].ID, ran[i + 1].ID);
						swap(ran[i].name, ran[i + 1].name);
						swap(ran[i].link, ran[i + 1].link);
					}
				}
			}
			cout << "�������������" << endl;
			cout << "���" << '	' << "����" << '	' << "��ϵ��ʽ" << '	' << "��������" << endl;
			for (int i = 0; i < n ; i++) {
				cout << ran[i].ID << "	"
					<< ran[i].name << "	"
					<< ran[i].link << "	        "
					<< ran[i].position << endl;
			}
			cout << "�Ƿ����������(y/n)" << endl;
			cin >> c;
		}while (c == 'y' || c == 'Y');

	}

};


int main() {
	int k;	
	Manage A;
	
	while (1) {
		cout << "           ��ӭʹ�ù�˾��Ա����ϵͳ         " << endl;
		cout << "                                        " << endl;
		cout << "              1.�����Ա��Ϣ              " << endl;
		cout << "              2.�޸���Ա��Ϣ              " << endl;
		cout << "              3.ɾ����Ա��Ϣ              " << endl;
		cout << "              4.��ѯ��Ա��Ϣ              " << endl;
		cout << "              5.��ӡ��Ա��Ϣ              " << endl;
		cout << "              6.������Ա����              " << endl;
		cout << "              7.ͳ����Ա��Ϣ              " << endl;
		cout << "              8.�˳�����                 " << endl;
		cout << "	   ������Ҫִ�еĲ���:" << ' ';
		cin >> k;
			switch (k) {
			case 1: A.add_data(); break;
			case 2: A.change_data(); break;
			case 3: A.delete_data(); break;
			case 4: A.find_data(); break;
			case 5: A.print_data(); break;
			case 6:	A.rank_data(); break;
			case 7: A.count_data(); break;
			case 8:exit(2); break;
			default:cout << "\t\t\t        �������,����" << endl; break;
			}
	}
	system("pause");
	return 0;
}

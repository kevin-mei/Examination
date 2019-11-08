#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class EightQueen {
public:
	EightQueen(int nQueen) {
		this->nQueen = nQueen;
		inColumn.resize(nQueen, false);
		mainDiagonal.resize(2 * nQueen - 1, false);
		minorDiagonal.resize(2 * nQueen - 1, false);
	}
	~EightQueen() {}
	int process() {
		int *path = new int[nQueen];
		calculate(path, 0);
		delete[] path;
		return 0;
	}
	void calculate(int *path, int row) {
		if (row == nQueen) {
			solution.push_back(vector<int>(path, path + nQueen));
			return;
		}
		for (int col = 0; col < nQueen; col++) {
			if (canLay(row, col)) {//��ǰλ�ÿɷ���
				path[row] = col;//��Ƿ��õ�λ��
				inColumn[col] = true;//��ǰ�ʺ�������
				minorDiagonal[row + col] = true;//�ʺ�����λ�õĺ�������֮�Ͷ�Ӧ�ĴζԽ���
				mainDiagonal[nQueen - 1 + row - col] = true;//�ʺ�����λ�õĺ�������֮�Ͷ�Ӧ�����Խ���
				calculate(path, row + 1);//��һ���ϵĻʺ�
				//break;//ȥ���������еĽ⣡
				inColumn[col] = false;
				minorDiagonal[row + col] = false;
				mainDiagonal[nQueen - 1 + row - col] = false;
			}
		}
	}
	
	bool canLay(int row, int col) {
		return !inColumn[col] && !minorDiagonal[row + col] && !mainDiagonal[nQueen - 1 + row - col];
		//int k, j;
		//for (int i = 0; i < 8; i++) {//����г�ͻ
		//	if (arry[i][j] == 1) {
		//		return false;
		//	}
		//}
		//for (int col = 0; col < 8; i++) {//����г�ͻ
		//	if (arry[k][j] == 1) {
		//		return false;
		//	}
		//}
		//for (int i = k - 1, m = j - 1; i >= 0 && m >= 0; i--, m--) {//�����Խ���
		//	if (arry[i][m] == 1) {
		//		return false;
		//	}
		//}
		//for (int i = k - 1, m = j + 1; i >= 0 && m <= 7; i--, m++) {//����ҶԽ���
		//	if (arry[i][m] == 1) {
		//		return false;
		//	}
		//}
		//return true;
	}
	void print() {
		for (int i = 0; i < solution.size(); i++) {
			cout << "solution " << i << " : " << endl;
			for (int row = 0; row < nQueen; row++) {
				for (int col = 0; col < solution[i][row]; col++) {
					cout << "O ";
				}
				cout << "X ";
				for (int col = solution[i][row] + 1; col < nQueen; col++) {
					cout << "O ";
				}
				cout << endl;
			}
			cout << endl << endl;
		}
	}
private:
	int nQueen;
	vector<bool> inColumn;
	vector<bool> mainDiagonal;
	vector<bool> minorDiagonal;
	vector<vector<int> > solution;
};

int main()
{
	EightQueen queen(8);
	queen.process();
	queen.print();
	return 0;
}

#pragma once

template <class Type>
Type inputCheck(Type &number)
{
	while (true) {
		cin >> number;
		if (cin.peek() == '\n' || cin.peek() == ',' || cin.peek() == '.') {
			cin.get();
			break;
		}
		else {
			cout << "\n�������! ������������� ������." << endl;
			cout << "��������� �� ���:";
			cin.clear();
			cin.sync();
			cout << endl;
		}
	}
	return number;
}
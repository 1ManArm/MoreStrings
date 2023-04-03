#include <iostream>
#include <string>

std::string spaces_str(std::string str); //�������� �������

bool is_spam(std::string message);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//������ 1. ������� � ������
	/*std::cout << "������ 1.\n������� ������ -> ";
	std::string str1;
	std::getline(std::cin, str1);
	std::cout << spaces_str(str1) << "\n\n";*/

	//������ 2. �������� �� ����
	/*std::cout << "������ 2.\n������� ������ -> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << "��������� ����\n\n";
	else
		std::cout << "��� ��\n\n";*/

	//������ 3. ������ ����� �� ������
	std::string URL = "http://vk.com/super_user/photos";
	std::cout << "������ 3.\n����� �����:\n" << URL << std::endl;
	int domen_index = URL.find("://") + 3;
	int path_index = URL.find("/", domen_index) + 1;
	std::string path = URL.substr(path_index);
	std::string domen = URL.substr(domen_index, path_index - 1 - domen_index);
	std::string protocol = URL.substr(0, domen_index - 3);
	std::cout << "\n��������: " << protocol << std::endl;
	std::cout << "�����:    " << domen << std::endl;
	std::cout << "����:     " << path << "\n\n";


	return 0;
}


std::string spaces_str(std::string str) {
	std::string result;
	for (int i = 0; i < str.length(); i++) {
		result += str[i];
		if (i != str.length() - 1)
			result += " ";
	}
	return result;
}

bool is_spam(std::string message) {
	for (int i = 0; i < message.length(); i++)
		message[i] = std::tolower(message[i]);
	const int spams_number = 3;
	std::string spams[spams_number]{
		"100% free",
		"sales increase",
		"only today"
	};
	for (int i = 0; i < spams_number; i++)
		if (message.find(spams[i]) < message.length())
			return true;
	return false;
}
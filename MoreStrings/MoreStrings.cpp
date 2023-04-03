#include <iostream>
#include <string>

std::string spaces_str(std::string str); //Прототип функции

bool is_spam(std::string message);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	//Задача 1. Пробелы в строке
	/*std::cout << "Задача 1.\nВведите строку -> ";
	std::string str1;
	std::getline(std::cin, str1);
	std::cout << spaces_str(str1) << "\n\n";*/

	//Задача 2. Проверка на спам
	/*std::cout << "Задача 2.\nВведите строку -> ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << "Обнаружен спам\n\n";
	else
		std::cout << "Все ок\n\n";*/

	//Задача 3. Разбор сайта по частям
	std::string URL = "http://vk.com/super_user/photos";
	std::cout << "Задача 3.\nАдрес сайта:\n" << URL << std::endl;
	int domen_index = URL.find("://") + 3;
	int path_index = URL.find("/", domen_index) + 1;
	std::string path = URL.substr(path_index);
	std::string domen = URL.substr(domen_index, path_index - 1 - domen_index);
	std::string protocol = URL.substr(0, domen_index - 3);
	std::cout << "\nПротокол: " << protocol << std::endl;
	std::cout << "Домен:    " << domen << std::endl;
	std::cout << "Путь:     " << path << "\n\n";


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
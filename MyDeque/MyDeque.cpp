#include "MyDeque.h"
#include <string>

int main()
{
	//Проверка вставки int
	MyDeque<int> deqInt;
	deqInt.push_front(12);
	deqInt.push_front(13);
	int a = 10;
	deqInt.push_front(a);
	deqInt.push_back(a);
	deqInt.push_back(1000);
	deqInt.push_front(123);
	deqInt.push_back(43);
	deqInt.push_front(456);
	deqInt.print();

	//Проверка конструктора копирования
	MyDeque<int> newIntDeq = deqInt;
	std::cout << std::endl;
	newIntDeq.print();
	std::cout << std::endl;

	//Проверка оператора присваивания
	std::cout << std::endl;
	newIntDeq.pop_back();
	newIntDeq.pop_back();
	newIntDeq.pop_back();
	newIntDeq = deqInt;
	newIntDeq.print();
	std::cout << std::endl;

	//Проверка вставки string
	MyDeque<std::string> deqStr;
	deqStr.push_front("wuerwer");
	deqStr.push_back("slkdsjhgf");
	deqStr.print();

	//Проверка метода удаления
	std::cout << deqInt.pop_front() << std::endl;
	std::cout << std::endl;
	std::cout << deqInt.pop_front() << std::endl;
	std::cout << std::endl;
	std::cout << deqInt.pop_front() << std::endl;
	std::cout << std::endl;
	std::cout << deqInt.pop_back() << std::endl;
	std::cout << std::endl;
	std::cout << deqInt.pop_back() << std::endl;
	std::cout << std::endl;
	std::cout << deqInt.pop_back() << std::endl;
	std::cout << std::endl;
	std::cout << deqInt.pop_front() << std::endl;
	std::cout << std::endl;
	std::cout << deqInt.pop_back() << std::endl;
	std::cout << std::endl;
	//Очередь уже пуста
	try
	{
		std::cout << deqInt.pop_back() << std::endl;
		std::cout << std::endl;
	}
	catch (const std::logic_error& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	try
	{
		std::cout << deqInt.pop_back() << std::endl;
		std::cout << std::endl;
	}
	catch (const std::logic_error& ex)
	{
		std::cerr << ex.what() << std::endl;
	}
	
	//Проверка возвращения без удаления
	std::cout << deqStr.back() << std::endl;
	std::cout << std::endl;
	std::cout << deqStr.front() << std::endl;
	std::cout << std::endl;
	deqStr.print();
	try
	{
		std::cout << deqInt.back() << std::endl;
		std::cout << std::endl;
	}
	catch (const std::logic_error& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	deqInt.print();
	
	deqStr.clear();
	deqStr.push_back("askjgf");
	deqStr.print();
	
	return 0;
}
#include <iostream>
#include <list>
#include <string>

struct Data 
{
public:
	int group;
	std::string surname;
};

int main()
{
	std::list <Data> groups;
	Data data;
	int group, cingroup;
	std::string surname;
	while (true) 
	{
		std::cin >> group >> surname;
		if (group == 0) 
		{
			break;
		}
		data.group = group;
		data.surname = surname;
		groups.push_back(data);
	}
	std::cin >> cingroup;
	for (Data row : groups) 
	{
		if (row.group == cingroup) 
		{
			std::cout << row.surname << std::endl;
		}
	}
}

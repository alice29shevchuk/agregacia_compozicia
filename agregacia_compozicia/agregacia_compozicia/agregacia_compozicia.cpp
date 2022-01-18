#include <iostream>
class Room
{
	int temperature;
public:
	Room()
	{
		this->temperature = 15;
	}
	int getTemperature()
	{
		return this->temperature;
	}
	void highTemperature()
	{
		this->temperature++;
	}
	void lowTemperature()
	{
		this->temperature--;
	}
};
class Conditioner
{
	int tempa;
	bool on_off;
public:
	Conditioner()
	{
		this->tempa = 20;
		this->on_off = false;
	}
	int getTempa()
	{
		return tempa;
	}
	void OnConditioner()
	{
		std::cout << "Кондиционер включен!\n";
		this->on_off = true;
	}
	void OffConditioner()
	{
		std::cout << "Кондиционер выключен!\n";
		this->on_off = false;
	}
	void highTempa(Room&room)
	{
		this->tempa = this->tempa + 1;
		while (this->tempa != room.getTemperature())
		{
			if (room.getTemperature() < this->tempa)
			{
				room.highTemperature();
			}
			else
			{
				room.lowTemperature();
			}
		}
	}
	void lowTempa(Room &room)
	{
		this->tempa = this->tempa - 1;
		while (this->tempa != room.getTemperature())
		{
			if (room.getTemperature() < this->tempa)
			{
				room.highTemperature();
			}
			else
			{
				room.lowTemperature();
			}
		}
	}
};
class Pult
{
public:
	void OnConditioner(Conditioner&cond)
	{
		cond.OnConditioner();
	}
	void OffConditioner(Conditioner& cond)
	{
		cond.OffConditioner();
	}
	void highTempa(Conditioner& cond,Room&room)
	{
		cond.highTempa(room);
	}
	void lowTempa(Conditioner& cond,Room& room)
	{
		cond.lowTempa(room);
	}
};
int main()
{
	setlocale(0, "");
	Pult pult;
	Conditioner cond;
	Room room;
	std::cout<<"Текущая темпа в комнате: "<<room.getTemperature();
	std::cout << "\n";
	pult.OnConditioner(cond);
	pult.lowTempa(cond,room);
	std::cout<<room.getTemperature();
	std::cout << "\n";
	std::cout << cond.getTempa();
}


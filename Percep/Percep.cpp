#include <bits/stdc++.h>

std::vector<double> WW = { 0.5, 0.5 };																		//Веса связей
const double CONST = 0.01;																					//Константа для обучения

bool takeRightAns(int x1, int x2)																			//Получение правильного ответа
{
	return x1 && x2;
}

double outputSignal(double x1, double x2)																	//Выходное значение
{
	return WW[0] * x1 + WW[1] * x2 - 1.5;  
}

double procOutputSignal(double h)																			//Функция активации
{
	return (1 / (1 + exp(-h)));
}

void refreshWeight(double& Wi, double rightans, double xi, double procOutS)									//Обновление веса
{
	Wi = Wi + CONST * (rightans - procOutS) * xi;
}

void train()																								//Тренировка персептрона
{
	for (size_t i = 0; i < 50000000; ++i)
	{
		int x1 = rand() % 2;
		int x2 = rand() % 2;
		bool rightAns = takeRightAns(x1, x2);
		double outS = outputSignal(x1, x2);
		double procOutS = procOutputSignal(outS);
		refreshWeight(WW[0], rightAns, x1, procOutS);
		refreshWeight(WW[1], rightAns, x2, procOutS);
	}
}


int main()
{
	train();

	std::cout << procOutputSignal(outputSignal(0, 0)) << std::endl;
	std::cout << procOutputSignal(outputSignal(1, 0)) << std::endl;
	std::cout << procOutputSignal(outputSignal(0, 1)) << std::endl;
	std::cout << procOutputSignal(outputSignal(1, 1)) << std::endl;
}


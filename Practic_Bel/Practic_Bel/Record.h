#pragma once

using namespace System;

ref class Record
{
public:
	Record();
	void SetData(String^ name, int bal_d, int bal_e);		//получаем данные о студенте
	int GetSum();							//возвращаем сумму баллов
	String^ Evaluation();						//возвращаем оценку
private:
	String^ Name;							//имя
	int BallDop;							//Доп баллы
	int BallEx;							//баллы за экзамен
};


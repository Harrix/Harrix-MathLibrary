//БИБЛИОТЕКА MATH HARRIX LIBRARY

//Сборник различных математических функций с открытым кодом на языке C++
//Страница проекта: https://github.com/Harrix/Math-Harrix-Library
//Распространяется по лицензии Apache License, Version 2.0

//   Copyright 2007-2013 Harrix
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "MathHarrixLibrary.h"

//ДЛЯ ГЕНЕРАТОРА СЛУЧАЙНЫХ ЧИСЕЛ
unsigned int MHL_Dummy;//Результат инициализации генератора случайных чисел

//СЛУЖЕБНЫЕ ДОПОЛНИТЕЛЬНЫЕ ПЕРМЕННЫЕ
double (*VMHL_TempFunction)(double*,int);
int *VMHL_TempInt1;
int *VMHL_TempInt2;
int *VMHL_TempInt3;
int *VMHL_TempInt4;
double *VMHL_TempDouble1;
double *VMHL_TempDouble2;
double *VMHL_TempDouble3;

void MHL_SeedRandom(void)
{
/*
Инициализатор генератора случайных чисел.
В данном случае используется самый простой его вариант со всеми его недостатками.
Входные параметры:
 Отсутствуют.
Возвращаемое значение:
 Отсутствуют.
*/
//В качестве начального значения для ГСЧ используем текущее время
MHL_Dummy=(unsigned)time(NULL);
srand(MHL_Dummy);//Стандартная инициализация
rand();//первый вызов для контроля
}
//---------------------------------------------------------------------------
double MHL_RandomNumber(void)
{
/*
Генератор случайных чисел (ГСЧ).
В данном случае используется самый простой его вариант со всеми его недостатками.
Использовать в функциях по криптографии не стоит.
Входные параметры:
 Отсутствуют.
Возвращаемое значение:
 Случайное вещественное число из интервала (0;1) по равномерному закону распределения.
*/
return (double)rand()/(RAND_MAX+1);
}
//---------------------------------------------------------------------------

//*****************************************************************
//Вектора (Одномерные массивы)
//*****************************************************************


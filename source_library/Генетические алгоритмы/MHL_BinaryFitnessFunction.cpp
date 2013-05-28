double MHL_BinaryFitnessFunction(int*x, int VMHL_N)
{
/*
Служебная функция. Функция вычисляет целевую функцию бинарного вектора, в котором
закодирован вещественный вектор. Использует внутренние служебные переменные.
Функция для MHL_StandartRealGeneticAlgorithm. Использовать для своих целей не рекомендуется.
Входные параметры:
 x - бинарный вектор;
 VMHL_N - количество элементов в векторе.
Возвращаемое значение:
 Значение целевой функции бинарного вектора.
Примечание. Используемые переменные, переодеваемые из MHL_StandartRealGeneticAlgorithm:
 VMHL_TempFunction - указатель на целевая функция для вещественного решения;
 VMHL_TempInt1 - указатель на массив, сколько бит приходится в бинарной хромосоме на кодирование ;
 VMHL_TempDouble1 - указатель на массив левых границ изменения вещественной переменной;
 VMHL_TempDouble2 - указатель на массив правых границ изменения вещественной переменной;
 VMHL_TempDouble3 - указатель на массив, в котором можно сохранить вещественный индивид при его раскодировании из бинарной строки;
 VMHL_TempInt2 - указатель на размерность вещественного вектора;
 VMHL_TempInt3 - указатель на тип преобразования вещественной задачи оптимизации в бинарное.
*/
double VMHL_Result;
int RealLength=*VMHL_TempInt2;//Размерность вещественного вектора
int TypOfConverting=*VMHL_TempInt3;//Тип преобразования

if (VMHL_N>0) VMHL_Result=0;//строчка только для того, чтобы компилятор не говорил, что VMHL_N не используется

//Переведем вектор из бинарного в вещественный
if (TypOfConverting==0)//IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации)
 MHL_BinaryVectorToRealVector(x,VMHL_TempDouble3,VMHL_TempDouble1,VMHL_TempDouble2,VMHL_TempInt1,RealLength);

if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 MHL_BinaryGrayVectorToRealVector(x,VMHL_TempDouble3,VMHL_TempInt4,VMHL_TempDouble1,VMHL_TempDouble2,VMHL_TempInt1,RealLength);

//Посчитаем значение целевой функции вещественного вектора
VMHL_Result=VMHL_TempFunction(VMHL_TempDouble3,RealLength);

return VMHL_Result;
}
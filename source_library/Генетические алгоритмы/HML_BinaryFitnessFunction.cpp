double HML_BinaryFitnessFunction(int*x, int VHML_N)
{
/*
Служебная функция. Функция вычисляет целевую функцию бинарного вектора, в котором
закодирован вещественный вектор. Использует внутренние служебные переменные.
Функция для HML_StandartRealGeneticAlgorithm. Использовать для своих целей не рекомендуется.
Входные параметры:
 x - бинарный вектор;
 VHML_N - количество элементов в векторе.
Возвращаемое значение:
 Значение целевой функции бинарного вектора.
Примечание. Используемые переменные, переодеваемые из HML_StandartRealGeneticAlgorithm:
 VHML_TempFunction - указатель на целевая функция для вещественного решения;
 VHML_TempInt1 - указатель на массив, сколько бит приходится в бинарной хромосоме на кодирование ;
 VHML_TempDouble1 - указатель на массив левых границ изменения вещественной переменной;
 VHML_TempDouble2 - указатель на массив правых границ изменения вещественной переменной;
 VHML_TempDouble3 - указатель на массив, в котором можно сохранить вещественный индивид при его раскодировании из бинарной строки;
 VHML_TempInt2 - указатель на размерность вещественного вектора;
 VHML_TempInt3 - указатель на тип преобразования вещественной задачи оптимизации в бинарное.
*/
double VHML_Result;
int RealLength=*VHML_TempInt2;//Размерность вещественного вектора
int TypOfConverting=*VHML_TempInt3;//Тип преобразования

if (VHML_N>0) VHML_Result=0;//строчка только для того, чтобы компилятор не говорил, что VHML_N не используется

//Переведем вектор из бинарного в вещественный
if (TypOfConverting==0)//IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации)
 HML_BinaryVectorToRealVector(x,VHML_TempDouble3,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);

if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 HML_BinaryGrayVectorToRealVector(x,VHML_TempDouble3,VHML_TempInt4,VHML_TempDouble1,VHML_TempDouble2,VHML_TempInt1,RealLength);

//Посчитаем значение целевой функции вещественного вектора
VHML_Result=VHML_TempFunction(VHML_TempDouble3,RealLength);

return VHML_Result;
}
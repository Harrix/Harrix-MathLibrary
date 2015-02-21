template <class T> T HML_Median(T *x, int VHML_N)
{
/*
Функция вычисляет медиану выборки.
Входные параметры:
 x - указатель на исходную выборку;
 VHML_N - размер массива.
Возвращаемое значение:
 Медиана массива.
*/
T VHML_Result;
T *SortVector;
T Two=2;
SortVector=new T[VHML_N];//Нам нужно отсортировать массив, но не трогая этот
HML_VectorToVector(x,SortVector,VHML_N);

HML_BubbleSort(SortVector,VHML_N);//отсортируем массив

if (HML_Parity(VHML_N)==0)//Если число элементов нечетно
 VHML_Result=SortVector[VHML_N/2];
else//Если число элементов четно
 VHML_Result=(SortVector[VHML_N/2-1]+SortVector[VHML_N/2])/Two;
delete [] SortVector;

return VHML_Result;
}
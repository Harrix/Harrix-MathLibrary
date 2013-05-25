template <class T> T TMHL_Median(T *x, int VMHL_N)
{
/*
Функция вычисляет медиану выборки.
Входные параметры:
 x - указатель на исходную выборку;
 VMHL_N - размер массива.
Возвращаемое значение:
 Медиана массива.
*/
T VMHL_Result;
T *SortVector;
T Two=2;
SortVector=new T[VMHL_N];//Нам нужно отсортировать массив, но не трогая этот
TMHL_VectorToVector(x,SortVector,VMHL_N);

TMHL_BubbleSort(SortVector,VMHL_N);//отсортируем массив

if (MHL_Parity(VMHL_N)==0)//Если число элементов нечетно
 VMHL_Result=SortVector[VMHL_N/2];
else//Если число элементов четно
 VMHL_Result=(SortVector[VMHL_N/2-1]+SortVector[VMHL_N/2])/Two;
delete [] SortVector;

return VMHL_Result;
}
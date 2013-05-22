template <class T> void TMHL_FibonacciNumbersVector(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция заполняет массив числами Фибоначчи.
Входные параметры:
 VMHL_ResultVector - указатель на массив, в который записывается результат;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
if (VMHL_N>=1) VMHL_ResultVector[0]=1;
if (VMHL_N>=2) VMHL_ResultVector[1]=1;
if (VMHL_N>2)
 {
 for (int i=2;i<VMHL_N;i++)
  VMHL_ResultVector[i]=VMHL_ResultVector[i-1]+VMHL_ResultVector[i-2];
 }
}
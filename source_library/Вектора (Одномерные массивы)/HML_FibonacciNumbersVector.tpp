template <class T> void HML_FibonacciNumbersVector(T *VHML_ResultVector, int VHML_N)
{
/*
Функция заполняет массив числами Фибоначчи.
Входные параметры:
 VHML_ResultVector - указатель на массив, в который записывается результат;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
if (VHML_N>=1) VHML_ResultVector[0]=1;
if (VHML_N>=2) VHML_ResultVector[1]=1;
if (VHML_N>2)
 {
 for (int i=2;i<VHML_N;i++)
  VHML_ResultVector[i]=VHML_ResultVector[i-1]+VHML_ResultVector[i-2];
 }
}
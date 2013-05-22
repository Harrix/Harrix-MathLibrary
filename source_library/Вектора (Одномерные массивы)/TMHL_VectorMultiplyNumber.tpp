template <class T> void TMHL_VectorMultiplyNumber(T *VMHL_ResultVector, int VMHL_N, T Number)
{
/*
Функция умножает вектор на число.
Входные параметры:
 VMHL_ResultVector - вектор (в нем и сохраняется результат);
 VMHL_N - размер вектора;
 Number - число, на которое умножается вектор.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++) 
   VMHL_ResultVector[i]*=Number;
}
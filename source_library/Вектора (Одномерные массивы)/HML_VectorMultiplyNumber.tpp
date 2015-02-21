template <class T> void HML_VectorMultiplyNumber(T *VHML_ResultVector, int VHML_N, T Number)
{
/*
Функция умножает вектор на число.
Входные параметры:
 VHML_ResultVector - вектор (в нем и сохраняется результат);
 VHML_N - размер вектора;
 Number - число, на которое умножается вектор.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++) 
   VHML_ResultVector[i]*=Number;
}
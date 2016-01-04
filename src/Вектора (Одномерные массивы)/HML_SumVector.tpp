template <class T> T HML_SumVector(T *VHML_Vector,int VHML_N)
{
/*
Функция вычисляет сумму элементов вектора.
Входные параметры:
 VHML_Vector - указатель на исходный массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Сумма элементов массива.
*/
T VHML_Result=0;
for (int i=0;i<VHML_N;i++)
    VHML_Result+=VHML_Vector[i];

return VHML_Result;
}
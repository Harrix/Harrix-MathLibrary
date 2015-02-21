template <class T> T HML_ProductOfElementsOfVector(T *VHML_Vector,int VHML_N)
{
/*
Функция вычисляет произведение элементов вектора.
Входные параметры:
 VHML_Vector - указатель на исходный массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Произведение элементов массива.
*/
T VHML_Result=1;
for (int i=0;i<VHML_N;i++)
    VHML_Result*=VHML_Vector[i];

return VHML_Result;
}
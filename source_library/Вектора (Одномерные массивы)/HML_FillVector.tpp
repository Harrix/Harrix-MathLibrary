template <class T> void HML_FillVector(T *VHML_ResultVector, int VHML_N, T x)
{
/*
Функция заполняет вектор значениями, равных x.
Входные параметры:
 VHML_ResultVector - указатель на преобразуемый массив;
 VHML_N - количество элементов в массиве;
 x - число, которым заполняется вектор.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=x;
}
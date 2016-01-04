template <class T> bool HML_EqualityOfVectors(T *a, T *b, int VHML_N)
{
/*
Функция проверяет равенство векторов.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VHML_N - размер векторов.
Возвращаемое значение:
 true - вектора совпадают;
 false - вектора не совпадают.
*/
bool VHML_Result=true;
for (int i=0;i<VHML_N;i++)
 if (a[i]!=b[i]) VHML_Result=false;

return VHML_Result;
}
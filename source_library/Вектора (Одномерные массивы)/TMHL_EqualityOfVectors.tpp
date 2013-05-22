template <class T> bool TMHL_EqualityOfVectors(T *a, T *b, int VMHL_N)
{
/*
Функция проверяет равенство векторов.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VMHL_N - размер векторов.
Возвращаемое значение:
 true - вектора совпадают;
 false - вектора не совпадают.
*/
int VMHL_Result=true;
for (int i=0;i<VMHL_N;i++)
 if (a[i]!=b[i]) VMHL_Result=false;

return VMHL_Result;
}
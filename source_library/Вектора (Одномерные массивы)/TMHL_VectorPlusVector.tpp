template <class T> void TMHL_VectorPlusVector(T *a, T *b, T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция складывает поэлементно из одного массива другой и записывает результат в третий массив.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VMHL_ResultVector - вектор разности;
 VMHL_N - размер векторов.
Возвращаемое значение:
 Отсутствует
*/
for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=a[i]+b[i];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_VectorPlusVector(T *VMHL_ResultVector, T *b, int VMHL_N)
{
/*
Функция складывает поэлементно из одного массива другой и записывает результат в первый массив.
Входные параметры:
 VMHL_ResultVector - первый вектор, к которому прибавляют второй вектор;
 b - вторый вектор;
 VMHL_N - размер векторов.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]+=b[i];
}
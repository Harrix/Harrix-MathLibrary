template <class T> void HML_VectorPlusVector(T *a, T *b, T *VHML_ResultVector, int VHML_N)
{
/*
Функция складывает поэлементно из одного массива другой и записывает результат в третий массив.
Входные параметры:
 a - первый вектор;
 b - вторый вектор;
 VHML_ResultVector - вектор разности;
 VHML_N - размер векторов.
Возвращаемое значение:
 Отсутствует
*/
for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=a[i]+b[i];
}
//---------------------------------------------------------------------------
template <class T> void HML_VectorPlusVector(T *VHML_ResultVector, T *b, int VHML_N)
{
/*
Функция складывает поэлементно из одного массива другой и записывает результат в первый массив.
Входные параметры:
 VHML_ResultVector - первый вектор, к которому прибавляют второй вектор;
 b - вторый вектор;
 VHML_N - размер векторов.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]+=b[i];
}
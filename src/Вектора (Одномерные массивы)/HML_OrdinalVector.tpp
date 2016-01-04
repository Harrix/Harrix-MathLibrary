template <class T> void HML_OrdinalVector(T *VHML_ResultVector, int VHML_N)
{
/*
Функция заполняет вектор значениями, равные номеру элемента, начиная с единицы.
Входные параметры:
 VHML_ResultVector - указатель на вектор (одномерный массив), который и заполняется;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
    VHML_ResultVector[i]=i+1;
}
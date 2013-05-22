template <class T> void TMHL_OrdinalVectorZero(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция заполняет вектор значениями, равные номеру элемента, начиная с нуля.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (одномерный массив), который и заполняется;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++) 
    VMHL_ResultVector[i]=i;
}
template <class T> void TMHL_ChangeOrderInVector(T *VMHL_Vector, T *VMHL_ResultVector, int *Order, int VMHL_N)
{
/*
Функция меняет порядок элементов в массиве VMHL_Vector и сохраняет в другой VMHL_ResultVector согласно массиву
Order, в котором записан новый порядок элементов.
Входные параметры:
 VMHL_Vector - указатель на массив;
 VMHL_ResultVector - указатель на массив, куда сохраняем данные;
 Order - указатель на массив, в котором хранится порядок элементов;
 VMHL_N - количество элементов в массиве.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VMHL_N;i++)
    VMHL_ResultVector[i]=VMHL_Vector[Order[i]];
}
//---------------------------------------------------------------------------
template <class T> void TMHL_ChangeOrderInVector(T *VMHL_Vector, int *Order, int VMHL_N)
{
/*
Функция меняет порядок элементов в массиве VMHL_Vector согласно массиву
Order, в котором записан новый порядок элементов.
Входные параметры:
 VMHL_Vector - указатель на массив;
 Order - указатель на массив, в котором хранится порядок элементов;
 VMHL_N - количество элементов в массиве.
Возвращаемое значение:
 Отсутствует.
*/
T *TempVector;
TempVector = new T [VMHL_N];
TMHL_VectorToVector(VMHL_Vector,TempVector,VMHL_N);
for (int i=0;i<VMHL_N;i++)
    VMHL_Vector[i]=TempVector[Order[i]];
delete [] TempVector;
}
template <class T> void HML_ChangeOrderInVector(T *VHML_Vector, T *VHML_ResultVector, int *Order, int VHML_N)
{
/*
Функция меняет порядок элементов в массиве VHML_Vector и сохраняет в другой VHML_ResultVector согласно массиву
Order, в котором записан новый порядок элементов.
Входные параметры:
 VHML_Vector - указатель на массив;
 VHML_ResultVector - указатель на массив, куда сохраняем данные;
 Order - указатель на массив, в котором хранится порядок элементов;
 VHML_N - количество элементов в массиве.
Возвращаемое значение:
 Отсутствует.
*/
for (int i=0;i<VHML_N;i++)
    VHML_ResultVector[i]=VHML_Vector[Order[i]];
}
//---------------------------------------------------------------------------
template <class T> void HML_ChangeOrderInVector(T *VHML_Vector, int *Order, int VHML_N)
{
/*
Функция меняет порядок элементов в массиве VHML_Vector согласно массиву
Order, в котором записан новый порядок элементов.
Входные параметры:
 VHML_Vector - указатель на массив;
 Order - указатель на массив, в котором хранится порядок элементов;
 VHML_N - количество элементов в массиве.
Возвращаемое значение:
 Отсутствует.
*/
T *TempVector;
TempVector = new T [VHML_N];
HML_VectorToVector(VHML_Vector,TempVector,VHML_N);
for (int i=0;i<VHML_N;i++)
    VHML_Vector[i]=TempVector[Order[i]];
delete [] TempVector;
}
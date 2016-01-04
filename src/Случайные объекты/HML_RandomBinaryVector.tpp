template <class T> void HML_RandomBinaryVector(T *VHML_ResultVector,int VHML_N)
{
/*
Функция заполняет вектор (одномерный массив) случайно нулями и единицами.
Входные параметры:
 VHML_ResultVector - указатель на преобразуемый массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VHML_N;i++)
 {
 if (HML_RandomNumber()<0.5)
  VHML_ResultVector[i]=0;
 else
  VHML_ResultVector[i]=1;
 }
}
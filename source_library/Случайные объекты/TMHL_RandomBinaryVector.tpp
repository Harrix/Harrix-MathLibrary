template <class T> void TMHL_RandomBinaryVector(T *VMHL_ResultVector,int VMHL_N)
{
/*
Функция заполняет вектор (одномерный массив) случайно нулями и единицами.
Входные параметры:
 VMHL_ResultVector - указатель на преобразуемый массив;
 VMHL_N - размер массива VMHL_ResultMatrix (число строк).
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VMHL_N;i++)
 {
 if (MHL_RandomNumber()<0.5)
  VMHL_ResultVector[i]=0;
 else
  VMHL_ResultVector[i]=1;
 }
}
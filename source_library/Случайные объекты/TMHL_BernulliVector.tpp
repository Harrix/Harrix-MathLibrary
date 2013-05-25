template <class T> void TMHL_BernulliVector(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция формирует случайный вектор Бернулли.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VMHL_N;i++)
 {
 if (MHL_RandomNumber()<0.5)
  VMHL_ResultVector[i]=-1.;
 else
  VMHL_ResultVector[i]=1.;
 }
}
template <class T> void HML_BernulliVector(T *VHML_ResultVector, int VHML_N)
{
/*
Функция формирует случайный вектор Бернулли.
Входные параметры:
 VHML_ResultVector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VHML_N;i++)
 {
 if (HML_RandomNumber()<0.5)
  VHML_ResultVector[i]=-1.;
 else
  VHML_ResultVector[i]=1.;
 }
}
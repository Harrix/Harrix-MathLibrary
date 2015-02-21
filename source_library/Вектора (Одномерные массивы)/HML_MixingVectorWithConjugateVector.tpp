template <class T, class T2> void HML_MixingVectorWithConjugateVector(T *VHML_ResultVector, T2 *VHML_ResultVector2, double P, int VHML_N)
{
/*
Функция перемешивает массив вместе со сопряженным массивом. Поочередно
рассматриваются номера элементов массивов. С некоторой вероятностью
рассматриваемый элемент массива меняется местами со случайным элементом массива.
Пары элементов первого массива и сопряженного остаются без изменения.
Входные параметры:
 VHML_ResultVector - указатель на исходный массив;
 VHML_ResultVector2 - указатель на сопряженный массив;
 P - вероятность того, что элемент массива под рассматриваемым номером поменяется
 местами с каким-нибудь другим элементов (не включая самого себя);
 VHML_N - количество элементов в массивах.
Возвращаемое значение:
 Отсутствует.
*/
int i,j;
for (i=0;i<VHML_N;i++)
 {
 if (HML_RandomNumber()<P)
  {
  j=HML_RandomUniformInt(0,VHML_N-1);
  if (j>=i) j++;
  HML_NumberInterchange (&VHML_ResultVector[i],&VHML_ResultVector[j]);//меняем местами элементы массива
  HML_NumberInterchange (&VHML_ResultVector2[i],&VHML_ResultVector2[j]);//меняем местами элементы сопряженного массива
  }
 }
}
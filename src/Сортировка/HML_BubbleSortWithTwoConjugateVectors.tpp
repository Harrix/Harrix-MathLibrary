template <class T, class T2, class T3> void HML_BubbleSortWithTwoConjugateVectors(T *VHML_ResultVector, T2 *VHML_ResultVector2, T3 *VHML_ResultVector3, int VHML_N)
{
/*
Функция сортирует массив вместе с двумя сопряженными массивами в порядке возрастания методом "Сортировка пузырьком".
Пары элементов первого массива и сопряженного остаются без изменения.
Входные параметры:
 VHML_ResultVector - указатель на исходный массив;
 VHML_ResultVector2 - указатель на сопряженный массив;
 VHML_ResultVector3 - указатель на второй сопряженный массив;
 VHML_N - количество элементов в массивах.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VHML_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VHML_ResultVector[j]>VHML_ResultVector[j+1])
   {
   HML_NumberInterchange(&(VHML_ResultVector[j]),&(VHML_ResultVector[j+1]));
   HML_NumberInterchange(&(VHML_ResultVector2[j]),&(VHML_ResultVector2[j+1]));
   HML_NumberInterchange(&(VHML_ResultVector3[j]),&(VHML_ResultVector3[j+1]));
   }
}
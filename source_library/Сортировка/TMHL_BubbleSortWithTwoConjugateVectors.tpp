template <class T, class T2, class T3> void TMHL_BubbleSortWithTwoConjugateVectors(T *VMHL_ResultVector, T2 *VMHL_ResultVector2, T3 *VMHL_ResultVector3, int VMHL_N)
{
/*
Функция сортирует массив вместе с двумя сопряженными массивами в порядке возрастания методом "Сортировка пузырьком".
Пары элементов первого массива и сопряженного остаются без изменения.
Входные параметры:
 VMHL_ResultVector - указатель на исходный массив;
 VMHL_ResultVector2 - указатель на сопряженный массив;
 VMHL_ResultVector3 - указатель на второй сопряженный массив;
 VMHL_N - количество элементов в массивах.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VMHL_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VMHL_ResultVector[j]>VMHL_ResultVector[j+1])
   {
   TMHL_NumberInterchange(&(VMHL_ResultVector[j]),&(VMHL_ResultVector[j+1]));
   TMHL_NumberInterchange(&(VMHL_ResultVector2[j]),&(VMHL_ResultVector2[j+1]));
   TMHL_NumberInterchange(&(VMHL_ResultVector3[j]),&(VMHL_ResultVector3[j+1]));
   }
}
template <class T> void HML_BubbleDescendingSort(T *VHML_ResultVector, int VHML_N)
{
/*
Функция сортирует массив в порядке убывания методом "Сортировка пузырьком".
Входные параметры:
 VHML_ResultVector - указатель на исходный массив;
 VHML_N - количество элементов в массиве.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VHML_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VHML_ResultVector[j]<VHML_ResultVector[j+1])
   HML_NumberInterchange(&(VHML_ResultVector[j]),&(VHML_ResultVector[j+1]));
}
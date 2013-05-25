template <class T> void TMHL_BubbleDescendingSort(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция сортирует массив в порядке убывания методом "Сортировка пузырьком".
Входные параметры:
 VMHL_ResultVector - указатель на исходный массив;
 VMHL_N - количество элементов в массиве.
Выходной параметр:
 Отсутствует.
*/
int i,j;
for(i=VMHL_N-1;i>0;i--)
 for(j=0;j<i;j++)
  if(VMHL_ResultVector[j]<VMHL_ResultVector[j+1])
   TMHL_NumberInterchange(&(VMHL_ResultVector[j]),&(VMHL_ResultVector[j+1]));
}
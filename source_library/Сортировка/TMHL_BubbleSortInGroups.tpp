template <class T> void TMHL_BubbleSortInGroups(T *VMHL_ResultVector, int VMHL_N, int m)
{
/*
Функция сортирует массив в порядке возрастания методом "Сортировка пузырьком" в группах данного массива.
Имеется массив. Он делится на группы элементов по m элементов. Первые m
элементов принадлежат первой группе, следующие m элементов - следующей и т.д.
(Разумеется, в последней группе может и не оказаться m элементов).
Потом в каждой группе элементы сортируются по возрастанию.
Входные параметры:
 VMHL_ResultVector - указатель на исходный массив;
 VMHL_N - количество элементов в массиве;
 m - количество элементов в группе.
*/
int i,j,k,N,M;
N=int(VMHL_N/m);//число групп
for (k=0;k<N;k++)
 {
 for(i=m-1;i>0;i--)
  for(j=0;j<i;j++)
   if(VMHL_ResultVector[k*m+j]>VMHL_ResultVector[k*m+j+1])
    TMHL_NumberInterchange(&(VMHL_ResultVector[k*m+j]),&(VMHL_ResultVector[k*m+j+1]));
 }
M=VMHL_N%m;
if (M!=0)//если есть последняя неполная группа
 {
 for(i=M-1;i>0;i--)
  for(j=0;j<i;j++)
   if(VMHL_ResultVector[N*m+j]>VMHL_ResultVector[N*m+j+1])
    TMHL_NumberInterchange(&(VMHL_ResultVector[N*m+j]),&(VMHL_ResultVector[N*m+j+1]));
 }
}
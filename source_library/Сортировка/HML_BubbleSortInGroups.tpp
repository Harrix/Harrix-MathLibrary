template <class T> void HML_BubbleSortInGroups(T *VHML_ResultVector, int VHML_N, int m)
{
/*
Функция сортирует массив в порядке возрастания методом "Сортировка пузырьком" в группах данного массива.
Имеется массив. Он делится на группы элементов по m элементов. Первые m
элементов принадлежат первой группе, следующие m элементов - следующей и т.д.
(Разумеется, в последней группе может и не оказаться m элементов).
Потом в каждой группе элементы сортируются по возрастанию.
Входные параметры:
 VHML_ResultVector - указатель на исходный массив;
 VHML_N - количество элементов в массиве;
 m - количество элементов в группе.
*/
int i,j,k,N,M;
N=int(VHML_N/m);//число групп
for (k=0;k<N;k++)
 {
 for(i=m-1;i>0;i--)
  for(j=0;j<i;j++)
   if(VHML_ResultVector[k*m+j]>VHML_ResultVector[k*m+j+1])
    HML_NumberInterchange(&(VHML_ResultVector[k*m+j]),&(VHML_ResultVector[k*m+j+1]));
 }
M=VHML_N%m;
if (M!=0)//если есть последняя неполная группа
 {
 for(i=M-1;i>0;i--)
  for(j=0;j<i;j++)
   if(VHML_ResultVector[N*m+j]>VHML_ResultVector[N*m+j+1])
    HML_NumberInterchange(&(VHML_ResultVector[N*m+j]),&(VHML_ResultVector[N*m+j+1]));
 }
}
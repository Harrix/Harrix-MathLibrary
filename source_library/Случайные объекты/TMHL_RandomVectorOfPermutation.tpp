template <class T> void TMHL_RandomVectorOfPermutation(T *VMHL_ResultVector, int VMHL_N)
{
/*
Функция создает случайную строку-перестановку чисел от 1 до VMHL_N (включительно).
Входные параметры:
 VMHL_ResultVector - указатель на массив;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
T MOne=-1;
int i, b1, b2, randomall;
TMHL_FillVector (VMHL_ResultVector,VMHL_N,MOne);
for (i=0;i<VMHL_N;i++)
 {//начало заполнения цифрами
 randomall=MHL_RandomUniformInt(0,VMHL_N-i)+1;
 b1=0;
 b2=0;
 while (b1<randomall)
  {
  if (VMHL_ResultVector[b2]==-1) b1=b1+1;
  b2=b2+1;
  }
 VMHL_ResultVector[b2-1]=i+1;
 }//конец заполнения цифрами
}
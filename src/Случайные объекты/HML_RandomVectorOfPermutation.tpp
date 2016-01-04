template <class T> void HML_RandomVectorOfPermutation(T *VHML_ResultVector, int VHML_N)
{
/*
Функция создает случайную строку-перестановку чисел от 1 до VHML_N (включительно).
Входные параметры:
 VHML_ResultVector - указатель на массив;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
T MOne=-1;
int i, b1, b2, randomall;
HML_FillVector (VHML_ResultVector,VHML_N,MOne);
for (i=0;i<VHML_N;i++)
 {//начало заполнения цифрами
 randomall=HML_RandomUniformInt(0,VHML_N-i)+1;
 b1=0;
 b2=0;
 while (b1<randomall)
  {
  if (VHML_ResultVector[b2]==-1) b1=b1+1;
  b2=b2+1;
  }
 VHML_ResultVector[b2-1]=i+1;
 }//конец заполнения цифрами
}
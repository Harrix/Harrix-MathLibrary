template <class T> void TMHL_UniformCrossover(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N)
{
/*
Равномерное скрещивание. Оператор генетического алгоритма.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
int i;
int k;
//проводим скрещивание
for (i=0;i<VMHL_N;i++)
 {
 //копируем гены из родителей по порядку с равной вероятностью
 k=MHL_RandomUniformInt(0,2);
 if (k==0) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 if (k==1) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
}
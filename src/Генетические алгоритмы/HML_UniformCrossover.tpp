template <class T> void HML_UniformCrossover(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N)
{
/*
Равномерное скрещивание. Оператор генетического алгоритма.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
*/
int i;
int k;
//проводим скрещивание
for (i=0;i<VHML_N;i++)
 {
 //копируем гены из родителей по порядку с равной вероятностью
 k=HML_RandomUniformInt(0,2);
 if (k==0) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 if (k==1) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
}
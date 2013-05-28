template <class T> void TMHL_SinglepointCrossover(T *Parent1, T *Parent2, T *VMHL_ResultVector, int VMHL_N)
{
/*
Одноточечное скрещивание. Оператор генетического алгоритма.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VMHL_ResultVector - потомок;
 VMHL_N - размер векторов Parent1, Parent2 и VMHL_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
int i;
int k=MHL_RandomUniformInt(0,2);//0 или 1
int point=MHL_RandomUniformInt(1,VMHL_N);//точка разрыва хромосомы
if (k==0)//какой потомок "выживет": первый вариант или второй
 {
 for (i=0;i<point;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point;i<VMHL_N;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
else
 {
 for (i=0;i<point;i++) VMHL_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point;i<VMHL_N;i++) VMHL_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 }
}
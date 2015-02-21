template <class T> void HML_TwopointCrossoverWithCopying(T *Parent1, T *Parent2, T *VHML_ResultVector, int VHML_N)
{
/*
Двухточечное скрещивание с возможностью полного копирования одного из родителей. Оператор генетического алгоритма. Отличается от стандартного двухточечного скрещивания тем, что точки разрыва могут происходить по краям родителей, что может привести к полному копированию родителя.
Входные параметры:
 Parent1 - первый родитель;
 Parent2 - второй родитель;
 VHML_ResultVector - потомок;
 VHML_N - размер векторов Parent1, Parent2 и VHML_ResultVector.
Возвращаемое значение:
 Отсутствует.
Примечание:
 Потомок выбирается случайно.
*/
int i;
int k=HML_RandomUniformInt(0,2);//0 или 1
//проводим скрещивание
int point1=HML_RandomUniformInt(0,VHML_N+1);//1 точка разрыва хромосомы
int point2=HML_RandomUniformInt(0,VHML_N+1);//2 точка разрыва хромосомы
//1-ая точка разрыва должна следовать за 2-ой. Поэтому, если это не так,
//то переставляем точки местами функцией HML_NumberInterchangeInt
if (point2<point1) HML_NumberInterchange(&point1,&point2);
if (k==0)//какой потомок "выживет": первый вариант или второй (зависит от порядка следования родителей)
 {
 for (i=0;i<point1;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point1;i<point2;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point2;i<VHML_N;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 }
else
 {
 for (i=0;i<point1;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 for (i=point1;i<point2;i++) VHML_ResultVector[i]=Parent1[i];//копируем гены из 1 родителя
 for (i=point2;i<VHML_N;i++) VHML_ResultVector[i]=Parent2[i];//копируем гены из 2 родителя
 }
}
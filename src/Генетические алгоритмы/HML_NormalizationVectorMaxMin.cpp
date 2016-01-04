void HML_NormalizationVectorMaxMin(double *VHML_ResultVector,int VHML_N)
{
/*
Нормировка вектора чисел так, чтобы максимальный элемент имел значение 1, а минимальный 0.
Входные параметры:
 VHML_ResultVector - указатель на вектор (одномерный массив);
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
double max=HML_MaximumOfVector(VHML_ResultVector,VHML_N);//максимальное значение
double min=HML_MinimumOfVector(VHML_ResultVector,VHML_N);//минимальное значение
int vbool=0;
if (max<HML_MINFINITY)
 {
 //Если все числа очень маленькие
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1.0;
 vbool=1;
 }
if ((min>HML_INFINITY)&&(vbool==0))
 {
 //Если все числа очень большие
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1.0;
 vbool=1;
 }
if ((min==max)&&(vbool==0))
 {
 //Если все числа равны
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1.0;
 vbool=1;
 }
if (vbool==0)
 {
 double d=max-min;
 for (int i=0;i<VHML_N;i++)
  VHML_ResultVector[i]=(VHML_ResultVector[i]-min)/d;
 }
}
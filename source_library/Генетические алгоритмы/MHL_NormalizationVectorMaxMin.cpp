void MHL_NormalizationVectorMaxMin(double *VMHL_ResultVector,int VMHL_N)
{
/*
Нормировка вектора чисел так, чтобы максимальный элемент имел значение 1, а минимальный 0.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
double max=TMHL_MaximumOfVector(VMHL_ResultVector,VMHL_N);//максимальное значение
double min=TMHL_MinimumOfVector(VMHL_ResultVector,VMHL_N);//минимальное значение
int vbool=0;
if (max<MHL_MINFINITY)
 {
 //Если все числа очень маленькие
 for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=1.0;
 vbool=1;
 }
if ((min>MHL_INFINITY)&&(vbool==0))
 {
 //Если все числа очень большие
 for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=1.0;
 vbool=1;
 }
if ((min==max)&&(vbool==0))
 {
 //Если все числа равны
 for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=1.0;
 vbool=1;
 }
if (vbool==0)
 {
 double d=max-min;
 for (int i=0;i<VMHL_N;i++)
  VMHL_ResultVector[i]=(VMHL_ResultVector[i]-min)/d;
 }
}
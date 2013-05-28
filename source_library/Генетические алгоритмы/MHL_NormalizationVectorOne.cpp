void MHL_NormalizationVectorOne(double *VMHL_ResultVector,int VMHL_N)
{
/*
Нормировка вектора чисел в отрезок [0,1] так, чтобы сумма всех элементов была равна 1.
Входные параметры:
 VMHL_ResultVector - указатель на вектор (одномерный массив), который и будет преобразовываться;
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
//вначале отнормируем в интервал
MHL_NormalizationVectorMaxMin (VMHL_ResultVector,VMHL_N);
//Вычислим сумму вектора
double sum=TMHL_SumVector(VMHL_ResultVector,VMHL_N);
if (sum==0)
 {
 //Если сумма равна нулю
 for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=1./double(VMHL_N);
 }
else
 {
 for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]/=sum;
 }
}
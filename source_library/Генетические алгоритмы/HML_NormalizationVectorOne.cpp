void HML_NormalizationVectorOne(double *VHML_ResultVector,int VHML_N)
{
/*
Нормировка вектора чисел в отрезок [0,1] так, чтобы сумма всех элементов была равна 1.
Входные параметры:
 VHML_ResultVector - указатель на вектор (одномерный массив), который и будет преобразовываться;
 VHML_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
//вначале отнормируем в интервал
HML_NormalizationVectorMaxMin (VHML_ResultVector,VHML_N);
//Вычислим сумму вектора
double sum=HML_SumVector(VHML_ResultVector,VHML_N);
if (sum==0)
 {
 //Если сумма равна нулю
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]=1./double(VHML_N);
 }
else
 {
 for (int i=0;i<VHML_N;i++) VHML_ResultVector[i]/=sum;
 }
}
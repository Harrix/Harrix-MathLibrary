void MHL_RandomVectorOfProbability(double *VMHL_ResultVector, int VMHL_N)
{
/*
Функция заполняет вектор случайными значениями вероятностей. Сумма всех элементов вектора равна 1.
Входные параметры:
 VMHL_ResultVector - указатель на вектор вероятностей (одномерный массив);
 VMHL_N - размер массива.
Возвращаемое значение:
 Отсутствует.
*/
for(int i=0;i<VMHL_N;i++)
 VMHL_ResultVector[i]=MHL_RandomNumber();
//Вычислим сумму вектора
double sum=TMHL_SumVector(VMHL_ResultVector,VMHL_N);
if (sum==0)
 {
 //Если сумма равна нулю
 for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]=1./double(VMHL_N);
 }
else
 {
 //Нормализуем
 for (int i=0;i<VMHL_N;i++) VMHL_ResultVector[i]/=sum;
 }
}
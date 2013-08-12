void MHL_UniformSearchOptimizationN (double Left, double Right, double (*Function)(double), int Count, double *VMHL_Result_X,double *VMHL_Result_Y)
{
/*
Метод равномерного поиска. Метод одномерной оптимизации функции на интервале. Ищет минимум. От MHL_UniformSearchOptimization отличается тем, что вместо параметра шага равномерного прохода используется число вычислений целевой функции, но они взаимозаменяемы.
Входные параметры:
 Left - начало интервала поиска;
 Right - конец интервала поиска;
 Function - унимодальная функция, минимум которой ищется;
 Count - число вычислений целевой функции;
 VMHL_Result_X - вычисленная точка минимума (сюда записывается результат);
 VMHL_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение:
 Отсутствует.
*/
int i,n;
double min,fmin,f,x;
double Interval=ceil(fabs(Right-Left)/double(Count));
n=Count;
min=Left;
fmin=Function(min);
x=Left;
for (i=1;i<n;i++)
 {
 x+=Interval;
 f=Function(x);
 if (f<fmin)
  {
  min=x;
  fmin=f;
  }
 }
*VMHL_Result_X=min;
*VMHL_Result_Y=fmin;
}
void MHL_GoldenSectionOptimization (double Left, double Right, double (*Function)(double), double Interval, double *VMHL_Result_X,double *VMHL_Result_Y)
{
/*
Метод золотого сечения. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.
Входные параметры:
 Left - начало интервала поиска;
 b - конец интервала поиска;
 Function - унимодальная функция, минимум которой ищется;
 Interval - длина конечного интервала неопределенности (точность поиска);
 VMHL_Result_X - вычисленная точка минимума (сюда записывается результат);
 VMHL_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение: 
 Отсутствует.
*/
double l,v,fl,fv;
l=Left+(1.-MHL_TAU)*(Right-Left);
v=Left+MHL_TAU*(Right-Left);
fl=Function(l);
fv=Function(v);
while (fabs(Right-Left)>=Interval)
 {
 if (Function(l)<Function(v))
  {
  Right=v;
  v=l;
  fv=fl;
  l=Left+(1.-MHL_TAU)*(Right-Left);
  fl=Function(l);
  }
 else
  {
  Left=l;
  l=v;
  fl=fv;
  v=Left+MHL_TAU*(Right-Left);
  fv=Function(v);
  }
 }
*VMHL_Result_X=(Left+Right)/2.;
*VMHL_Result_Y=Function(*VMHL_Result_X);
}
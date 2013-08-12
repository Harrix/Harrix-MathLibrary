void MHL_DichotomyOptimization (double Left, double Right, double (*Function)(double), double Interval, double Epsilon, double *VMHL_Result_X,double *VMHL_Result_Y)
{
/*
Метод дихотомии. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.
Входные параметры:
 Left - начало интервала поиска;
 Right - конец интервала поиска;
 Function - унимодальная функция, минимум которой ищется;
 Interval - длина конечного интервала неопределенности (точность поиска);
 Epsilon - малое число;
 VMHL_Result_X - вычисленная точка минимума (сюда записывается результат);
 VMHL_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение:
 Отсутствует.
Примечание:
 Epsilon должен быть меньше, чем Interval/2, иначе возвращается левая граница просто.
*/
if (Epsilon>=Interval/2.)
 {
 //зануляем результаты
 *VMHL_Result_X=Left;
 *VMHL_Result_Y=Function(*VMHL_Result_X);
 }
else
 {
 double l,v;
 while (fabs(Right-Left)>=Interval)
  {
  l=(Left+Right)/2.-Epsilon;
  v=(Left+Right)/2.+Epsilon;
  if (Function(l)<Function(v))
   Right=v;
  else
   Left=l;
  }
 *VMHL_Result_X=(Left+Right)/2.;
 *VMHL_Result_Y=Function(*VMHL_Result_X);
 }
}
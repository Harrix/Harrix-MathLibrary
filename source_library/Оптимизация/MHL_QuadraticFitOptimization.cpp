void MHL_QuadraticFitOptimization (double Left, double Right, double (*Function)(double), double Epsilon, double Epsilon2, double *VMHL_Result_X,double *VMHL_Result_Y)
{
/*
Метод квадратичной интерполяции. Метод одномерной оптимизации унимодальной функции на интервале. Ищет минимум.
Входные параметры:
 Left - начало интервала поиска;
 Right - конец интервала поиска;
 Function - унимодальная функция, минимум которой ищется;
 Epsilon - точность;
 Epsilon2 - шаг, фактически еще одно малое число;
 VMHL_Result_X - вычисленная точка минимума (сюда записывается результат);
 VMHL_Result_Y - значение функции в точке минимума (сюда записывается результат).
Возвращаемое значение:
 Отсутствует.
*/
double x,h,x1,x2,x3,k,f1,f2,f3,fx,fp1,fp2,fp3,p[4],X=Left;
double error=0;
int ko;
h=Epsilon2;
x1=(Left+Right)/2.-h;
x2=(Left+Right)/2.;
x3=(Left+Right)/2.+h;
f1=Function(x1);
f2=Function(x2);
f3=Function(x3);
if (f1<f2)
 k=-1.;
else
 k=1.;
while (!((f1>=f2)&&(f2<=f3)))
 {
 x1=x1+k*h;
 x2=x2+k*h;
 x3=x3+k*h;
 f1=Function(x1);
 f2=Function(x2);
 f3=Function(x3);
 if (x1<Left) error=Left;
 if (x3>Right) error=Right;
 if (error!=0) break;
 }
if (error==0)
{
 x=0.5*((x2*x2-x3*x3)*f1+(x3*x3-x1*x1)*f2+(x1*x1-x2*x2)*f3)/((x2-x3)*f1+(x3-x1)*f2+(x1-x2)*f3);
 fx=Function(x);
 while ((fabs(fx-f2)>Epsilon)&&(X!=x))
  {
  X=x;
  p[0]=x1;
  p[1]=x2;
  p[2]=x3;
  p[3]=x;
  TMHL_BubbleSort(p, 4);
  fp1=Function(p[0]);
  fp2=Function(p[1]);
  fp3=Function(p[2]);
  if (!((fp1>=fp2)&&(fp2<=fp3)))
   ko=1;
  else
   ko=0;
  x1=p[0+ko];
  x2=p[1+ko];
  x3=p[2+ko];
  x=0.5*((x2*x2-x3*x3)*f1+(x3*x3-x1*x1)*f2+(x1*x1-x2*x2)*f3)/((x2-x3)*f1+(x3-x1)*f2+(x1-x2)*f3);
  fx=Function(x);
  }
 *VMHL_Result_X=x;
 *VMHL_Result_Y=fx;
}
else
 {
    *VMHL_Result_X=error;
    *VMHL_Result_Y=Function(error);
 }
}
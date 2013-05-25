double MHL_IntegralOfSimpson(double a, double b, double Epsilon,double (*Function)(double))
{
/*
Интегрирование по формуле Симпсона с оценкой точности по правилу Рунге.
Считается интеграл функции на отрезке [a,b] с погрешностью порядка Epsilon.
Входные параметры:
 a - начало отрезка интегрирования;
 b - конец отрезка интегрирования;
 Epsilon - погрешность;
 Function - подынтегральная функция.
Возвращаемое значение:
 Значение определенного интеграла.
Примечание: значимые цифры в ответе определяются Epsilon.
*/
double h,s,s1,VMHL_Result,s3,x;
VMHL_Result=1.;
h=b-a;
s=Function(a)+Function(b);
do
 {
 s3=VMHL_Result;
 h=h/2.;
 s1=0;
 x=a+h;
 do
  {
  s1=s1+2.*Function(x);
  x=x+2.*h;
  }
 while (x<b);
 s=s+s1;
 VMHL_Result=(s+s1)*h/3.;
 x=fabs(s3-VMHL_Result)/15.;
}
while (x>Epsilon);
return VMHL_Result;
}
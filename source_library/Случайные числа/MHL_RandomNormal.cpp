double MHL_RandomNormal(double Mean, double StdDev)
{
/*
Случайное число по нормальному закону распределения.
Входные параметры:
 Mean - математическое ожидание;
 StdDev - среднеквадратичное отклонение.
Возвращаемое значение:
 Случайное число по нормальному закону.
*/
double VMHL_Result,
s=0.449871,
t=-0.386595,
a=0.19600,
b=0.25472,
r1=0.27597,
r2=0.27846;
double u,v,x,y,q;
bool B;
B=false;
do
 {
 u=MHL_RandomNumber();
 v=MHL_RandomNumber();
 v=1.7156*(v-0.5);
 x=u-s;
 y=fabs(v)-t;
 q=x*x+y*(a*y-b*x);
 if (q<r1)
  B=true;
 else
  if ((q<=r2)&&(v*v<-4.0*log(u)*u*u))
   B=true;
 }
while (B!=true);
if (u==0) return Mean;
VMHL_Result=v/u;
VMHL_Result=VMHL_Result*StdDev+Mean;
return VMHL_Result;
return VMHL_Result;
}
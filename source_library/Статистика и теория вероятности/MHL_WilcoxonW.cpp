int MHL_WilcoxonW(double *a, double *b, int VMHL_N1, int VMHL_N2, double Q)
{
/*
Функция проверяет однородность выборок по критерию Вилкосена W.
Входные параметры:
 a - первая выборка;
 b - вторая выборка;
 VMHL_N1 - размер первой выборки;
 VMHL_N2 - размер второй выборки;
 Q - уровень значимости. Может принимать значения:
  0.002;
  0.01;
  0.02;
  0.05;
  0.1;
  0.2.
Возвращаемое значение:
 -2 - уровень значимости выбран неправильно (не из допустимого множества);
 -1 - объемы выборок не позволяют провести проверку при данном уровне значимости (или они не положительные);
 0 - выборки не однородны  при данном уровне значимости;
 1 - выборки однородны  при данном уровне значимости;
*/
int VMHL_Result=-2;

bool checkQ=false;
if (Q==0.002) checkQ=true;
if (Q==0.01)  checkQ=true;
if (Q==0.02)  checkQ=true;
if (Q==0.05)  checkQ=true;
if (Q==0.1)   checkQ=true;
if (Q==0.2)   checkQ=true;
if (checkQ==false) return VMHL_Result;// уровень значимости выбран не допустимого множества

//проверим правильность размеров выборки
VMHL_Result=-1;
if (VMHL_N1<=0) return VMHL_Result;
if (VMHL_N2<=0) return VMHL_Result;
//Если одной выборки много по числу элементов, а второй мало, то статистика выдаст некорректные результаты
if ((VMHL_N1>25)&&(VMHL_N2<5)) return VMHL_Result;
if ((VMHL_N2>25)&&(VMHL_N1<5)) return VMHL_Result;

int i;
double *All=new double[VMHL_N1+VMHL_N2];//объединенный массив
double *Rank=new double[VMHL_N1+VMHL_N2];//ранги

double W=0;//значение статистики критерия Вилкосена

//заполняем объединенный массив
for (i=0;i<VMHL_N1;i++) All[i]=a[i];//заливаем первую выборку
for (i=0;i<VMHL_N2;i++) All[i+VMHL_N1]=b[i];//заливаем вторую выборку

//проставляем ранги
MHL_MakeVectorOfRankForRankSelection(All, Rank,VMHL_N1+VMHL_N2);

//подсчитываем значение статистики W критерия Вилкосена
if (VMHL_N1<=VMHL_N2)
    for (i=0;i<VMHL_N1;i++) W += Rank[i];
else
    for (i=0;i<VMHL_N2;i++) W += Rank[i+VMHL_N1];

//Границы интервала критический значений статистики W для критерия Вилкоксена
double Left;
double Right;

if ((VMHL_N1<=25)&&(VMHL_N2<=25))
{
    //Берем значения из таблицы
    Left=MHL_LeftBorderOfWilcoxonWFromTable(VMHL_N1,VMHL_N2,Q/2.);
    Right=MHL_RightBorderOfWilcoxonWFromTable(VMHL_N1,VMHL_N2,Q/2.);
    if ((Left==-1)||(Right==-1)) return -1;//При таких размерах нельзя провести корректную проверку
}
else
{
    //В таблице значений для таких объемов выборки нет, поэтому проводим пересчет
    double m,n;
    if (VMHL_N1<=VMHL_N2)
    {
        m=VMHL_N1;
        n=VMHL_N2;
    }
    else
    {
        m=VMHL_N2;
        n=VMHL_N1;
    }

    double MW2=2*m*(m+n+1)/2.;

    double f1=(m*(m+n+1)-1)/2.;
    double f2=sqrt(m*n*(m+n+1)/12.);

    double h;
    //Берем значения обратной функции нормального распределения при значении 1-Q/2, так как
    //мы учитываем две критические границы
    if (Q==0.002) h=3.090232;//0.999
    if (Q==0.01)  h=2.575829;//0.995
    if (Q==0.02)  h=2.326348;//0.99
    if (Q==0.05)  h=1.959964;//0.975
    if (Q==0.1)   h=1.644854;//0.95
    if (Q==0.2)   h=1.281552;//0.9

    Left=int(f1-h*f2);
    Right=MW2-Left;
}

//Теперь проведем непосредственно проверку гипотезу об однородности выборок
if ((W>=Left)&&(W<=Right))
    VMHL_Result = 1;//выборки однородны
else
    VMHL_Result = 0;//выборки не однородны

delete [] All;
delete [] Rank;

return VMHL_Result;
}
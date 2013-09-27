double MHL_LeftBorderOfWilcoxonWFromTable(int m, int n, double Q)
{
    /*
    Функция возвращает левую границу интервала критический значений статистики W для критерия Вилкоксена по табличным данным.
    Входные параметры:
     m - объем первой выборки (не больше 25);
     n - объем второй выборки (не больше 25);
     Q - уровень значимости. Может принимать значения:
      0.001;
      0.005;
      0.01;
      0.025;
      0.05;
      0.1.
    Возвращаемое значение:
     Левая граница интервала критический значений статистики W для критерия Вилкоксена.
    Примечание:
     Если размеры выборок не из таблицы, если не правильный выбран уровень значимости, то возвратится -1.
    */
    double VMHL_Result=-1;

    if (n<m)  TMHL_NumberInterchange(&n,&m);//вначале должна идти выборка с меньшим объемом

    if (m==1)
    {
        if (n==9)
        {
            if (Q==0.10) VMHL_Result = 1;
        }

        if (n==10)
        {
            if (Q==0.10) VMHL_Result = 1;
        }

        if (n==11)
        {
            if (Q==0.10) VMHL_Result = 1;
        }

        if (n==12)
        {
            if (Q==0.10) VMHL_Result = 1;
        }

        if (n==13)
        {
            if (Q==0.10) VMHL_Result = 1;
        }

        if (n==14)
        {
            if (Q==0.10) VMHL_Result = 1;
        }

        if (n==15)
        {
            if (Q==0.10) VMHL_Result = 1;
        }

        if (n==16)
        {
            if (Q==0.10) VMHL_Result = 1;
        }

        if (n==17)
        {
            if (Q==0.10) VMHL_Result = 1;
        }

        if (n==18)
        {
            if (Q==0.10) VMHL_Result = 1;
        }

        if (n==19)
        {
            if (Q==0.05) VMHL_Result = 1;
            if (Q==0.10) VMHL_Result = 2;
        }

        if (n==20)
        {
            if (Q==0.05) VMHL_Result = 1;
            if (Q==0.10) VMHL_Result = 2;
        }

        if (n==21)
        {
            if (Q==0.05) VMHL_Result = 1;
            if (Q==0.10) VMHL_Result = 2;
        }

        if (n==22)
        {
            if (Q==0.05) VMHL_Result = 1;
            if (Q==0.10) VMHL_Result = 2;
        }

        if (n==23)
        {
            if (Q==0.05) VMHL_Result = 1;
            if (Q==0.10) VMHL_Result = 2;
        }

        if (n==24)
        {
            if (Q==0.05) VMHL_Result = 1;
            if (Q==0.10) VMHL_Result = 2;
        }

        if (n==25)
        {
            if (Q==0.05) VMHL_Result = 1;
            if (Q==0.10) VMHL_Result = 2;
        }
    }

    if (m==2)
    {
        if (n==3)
        {
            if (Q==0.10) VMHL_Result = 3;
        }

        if (n==4)
        {
            if (Q==0.10) VMHL_Result = 3;
        }

        if (n==5)
        {
            if (Q==0.05) VMHL_Result = 3;
            if (Q==0.10) VMHL_Result = 4;
        }

        if (n==6)
        {
            if (Q==0.05) VMHL_Result = 3;
            if (Q==0.10) VMHL_Result = 4;
        }

        if (n==7)
        {
            if (Q==0.05) VMHL_Result = 3;
            if (Q==0.10) VMHL_Result = 4;
        }

        if (n==8)
        {
            if (Q==0.025) VMHL_Result = 3;
            if (Q==0.05)  VMHL_Result = 4;
            if (Q==0.10)  VMHL_Result = 5;
        }

        if (n==9)
        {
            if (Q==0.025) VMHL_Result = 3;
            if (Q==0.05)  VMHL_Result = 4;
            if (Q==0.10)  VMHL_Result = 5;
        }

        if (n==10)
        {
            if (Q==0.025) VMHL_Result = 3;
            if (Q==0.05)  VMHL_Result = 4;
            if (Q==0.10)  VMHL_Result = 6;
        }

        if (n==11)
        {
            if (Q==0.025) VMHL_Result = 3;
            if (Q==0.05)  VMHL_Result = 4;
            if (Q==0.10)  VMHL_Result = 6;
        }

        if (n==12)
        {
            if (Q==0.025) VMHL_Result = 4;
            if (Q==0.05)  VMHL_Result = 5;
            if (Q==0.10)  VMHL_Result = 7;
        }

        if (n==13)
        {
            if (Q==0.010) VMHL_Result = 3;
            if (Q==0.025) VMHL_Result = 4;
            if (Q==0.05)  VMHL_Result = 5;
            if (Q==0.10)  VMHL_Result = 7;
        }

        if (n==14)
        {
            if (Q==0.010) VMHL_Result = 3;
            if (Q==0.025) VMHL_Result = 4;
            if (Q==0.05)  VMHL_Result = 6;
            if (Q==0.10)  VMHL_Result = 8;
        }

        if (n==15)
        {
            if (Q==0.010) VMHL_Result = 3;
            if (Q==0.025) VMHL_Result = 4;
            if (Q==0.05)  VMHL_Result = 6;
            if (Q==0.10)  VMHL_Result = 8;
        }

        if (n==16)
        {
            if (Q==0.010) VMHL_Result = 3;
            if (Q==0.025) VMHL_Result = 4;
            if (Q==0.05)  VMHL_Result = 6;
            if (Q==0.10)  VMHL_Result = 8;
        }

        if (n==17)
        {
            if (Q==0.010) VMHL_Result = 3;
            if (Q==0.025) VMHL_Result = 5;
            if (Q==0.05)  VMHL_Result = 6;
            if (Q==0.10)  VMHL_Result = 9;
        }

        if (n==18)
        {
            if (Q==0.010) VMHL_Result = 3;
            if (Q==0.025) VMHL_Result = 5;
            if (Q==0.05)  VMHL_Result = 7;
            if (Q==0.10)  VMHL_Result = 9;
        }

        if (n==19)
        {
            if (Q==0.005) VMHL_Result = 3;
            if (Q==0.010) VMHL_Result = 4;
            if (Q==0.025) VMHL_Result = 5;
            if (Q==0.05)  VMHL_Result = 7;
            if (Q==0.10)  VMHL_Result = 10;
        }

        if (n==20)
        {
            if (Q==0.005) VMHL_Result = 3;
            if (Q==0.010) VMHL_Result = 4;
            if (Q==0.025) VMHL_Result = 5;
            if (Q==0.05)  VMHL_Result = 7;
            if (Q==0.10)  VMHL_Result = 10;
        }

        if (n==21)
        {
            if (Q==0.005) VMHL_Result = 3;
            if (Q==0.010) VMHL_Result = 4;
            if (Q==0.025) VMHL_Result = 6;
            if (Q==0.05)  VMHL_Result = 8;
            if (Q==0.10)  VMHL_Result = 11;
        }

        if (n==22)
        {
            if (Q==0.005) VMHL_Result = 3;
            if (Q==0.010) VMHL_Result = 4;
            if (Q==0.025) VMHL_Result = 6;
            if (Q==0.05)  VMHL_Result = 8;
            if (Q==0.10)  VMHL_Result = 11;
        }

        if (n==23)
        {
            if (Q==0.005) VMHL_Result = 3;
            if (Q==0.010) VMHL_Result = 4;
            if (Q==0.025) VMHL_Result = 6;
            if (Q==0.05)  VMHL_Result = 8;
            if (Q==0.10)  VMHL_Result = 12;
        }

        if (n==24)
        {
            if (Q==0.005) VMHL_Result = 3;
            if (Q==0.010) VMHL_Result = 4;
            if (Q==0.025) VMHL_Result = 6;
            if (Q==0.05)  VMHL_Result = 9;
            if (Q==0.10)  VMHL_Result = 12;
        }

        if (n==25)
        {
            if (Q==0.005) VMHL_Result = 3;
            if (Q==0.010) VMHL_Result = 4;
            if (Q==0.025) VMHL_Result = 6;
            if (Q==0.05)  VMHL_Result = 9;
            if (Q==0.10)  VMHL_Result = 12;
        }
    }

    if (m==3)
    {
        if (n==3)
        {
            if (Q==0.05)  VMHL_Result = 6;
            if (Q==0.10)  VMHL_Result = 7;
        }

        if (n==4)
        {
            if (Q==0.05)  VMHL_Result = 6;
            if (Q==0.10)  VMHL_Result = 7;
        }

        if (n==5)
        {
            if (Q==0.025) VMHL_Result = 6;
            if (Q==0.05)  VMHL_Result = 7;
            if (Q==0.10)  VMHL_Result = 8;
        }

        if (n==6)
        {
            if (Q==0.025) VMHL_Result = 7;
            if (Q==0.05)  VMHL_Result = 8;
            if (Q==0.10)  VMHL_Result = 9;
        }

        if (n==7)
        {
            if (Q==0.010) VMHL_Result = 6;
            if (Q==0.025) VMHL_Result = 7;
            if (Q==0.05)  VMHL_Result = 8;
            if (Q==0.10)  VMHL_Result = 10;
        }

        if (n==8)
        {
            if (Q==0.010) VMHL_Result = 6;
            if (Q==0.025) VMHL_Result = 8;
            if (Q==0.05)  VMHL_Result = 9;
            if (Q==0.10)  VMHL_Result = 11;
        }

        if (n==9)
        {
            if (Q==0.005) VMHL_Result = 6;
            if (Q==0.010) VMHL_Result = 7;
            if (Q==0.025) VMHL_Result = 8;
            if (Q==0.05)  VMHL_Result = 10;
            if (Q==0.10)  VMHL_Result = 11;
        }

        if (n==10)
        {
            if (Q==0.005) VMHL_Result = 6;
            if (Q==0.010) VMHL_Result = 7;
            if (Q==0.025) VMHL_Result = 9;
            if (Q==0.05)  VMHL_Result = 10;
            if (Q==0.10)  VMHL_Result = 12;
        }

        if (n==11)
        {
            if (Q==0.005) VMHL_Result = 6;
            if (Q==0.010) VMHL_Result = 7;
            if (Q==0.025) VMHL_Result = 9;
            if (Q==0.05)  VMHL_Result = 11;
            if (Q==0.10)  VMHL_Result = 13;
        }

        if (n==12)
        {
            if (Q==0.005) VMHL_Result = 7;
            if (Q==0.010) VMHL_Result = 8;
            if (Q==0.025) VMHL_Result = 10;
            if (Q==0.05)  VMHL_Result = 11;
            if (Q==0.10)  VMHL_Result = 14;
        }

        if (n==13)
        {
            if (Q==0.005) VMHL_Result = 7;
            if (Q==0.010) VMHL_Result = 8;
            if (Q==0.025) VMHL_Result = 10;
            if (Q==0.05)  VMHL_Result = 12;
            if (Q==0.10)  VMHL_Result = 15;
        }

        if (n==14)
        {
            if (Q==0.005) VMHL_Result = 7;
            if (Q==0.010) VMHL_Result = 8;
            if (Q==0.025) VMHL_Result = 11;
            if (Q==0.05)  VMHL_Result = 13;
            if (Q==0.10)  VMHL_Result = 16;
        }

        if (n==15)
        {
            if (Q==0.005) VMHL_Result = 8;
            if (Q==0.010) VMHL_Result = 9;
            if (Q==0.025) VMHL_Result = 11;
            if (Q==0.05)  VMHL_Result = 13;
            if (Q==0.10)  VMHL_Result = 16;
        }

        if (n==16)
        {
            if (Q==0.005) VMHL_Result = 8;
            if (Q==0.010) VMHL_Result = 9;
            if (Q==0.025) VMHL_Result = 12;
            if (Q==0.05)  VMHL_Result = 14;
            if (Q==0.10)  VMHL_Result = 17;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 6;
            if (Q==0.005) VMHL_Result = 8;
            if (Q==0.010) VMHL_Result = 10;
            if (Q==0.025) VMHL_Result = 12;
            if (Q==0.05)  VMHL_Result = 15;
            if (Q==0.10)  VMHL_Result = 18;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 6;
            if (Q==0.005) VMHL_Result = 8;
            if (Q==0.010) VMHL_Result = 10;
            if (Q==0.025) VMHL_Result = 13;
            if (Q==0.05)  VMHL_Result = 15;
            if (Q==0.10)  VMHL_Result = 19;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 6;
            if (Q==0.005) VMHL_Result = 9;
            if (Q==0.010) VMHL_Result = 10;
            if (Q==0.025) VMHL_Result = 13;
            if (Q==0.05)  VMHL_Result = 16;
            if (Q==0.10)  VMHL_Result = 20;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 6;
            if (Q==0.005) VMHL_Result = 9;
            if (Q==0.010) VMHL_Result = 11;
            if (Q==0.025) VMHL_Result = 14;
            if (Q==0.05)  VMHL_Result = 17;
            if (Q==0.10)  VMHL_Result = 21;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 7;
            if (Q==0.005) VMHL_Result = 10;
            if (Q==0.010) VMHL_Result = 12;
            if (Q==0.025) VMHL_Result = 15;
            if (Q==0.05)  VMHL_Result = 18;
            if (Q==0.10)  VMHL_Result = 22;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 7;
            if (Q==0.005) VMHL_Result = 10;
            if (Q==0.010) VMHL_Result = 12;
            if (Q==0.025) VMHL_Result = 15;
            if (Q==0.05)  VMHL_Result = 19;
            if (Q==0.10)  VMHL_Result = 23;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 7;
            if (Q==0.005) VMHL_Result = 10;
            if (Q==0.010) VMHL_Result = 12;
            if (Q==0.025) VMHL_Result = 16;
            if (Q==0.05)  VMHL_Result = 19;
            if (Q==0.10)  VMHL_Result = 24;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 7;
            if (Q==0.005) VMHL_Result = 11;
            if (Q==0.010) VMHL_Result = 13;
            if (Q==0.025) VMHL_Result = 16;
            if (Q==0.05)  VMHL_Result = 20;
            if (Q==0.10)  VMHL_Result = 25;
        }
    }

    if (m==4)
    {
        if (n==4)
        {
            if (Q==0.025) VMHL_Result = 10;
            if (Q==0.05)  VMHL_Result = 11;
            if (Q==0.10)  VMHL_Result = 13;
        }

        if (n==5)
        {
            if (Q==0.010) VMHL_Result = 10;
            if (Q==0.025) VMHL_Result = 11;
            if (Q==0.05)  VMHL_Result = 12;
            if (Q==0.10)  VMHL_Result = 14;
        }

        if (n==6)
        {
            if (Q==0.005) VMHL_Result = 10;
            if (Q==0.010) VMHL_Result = 11;
            if (Q==0.025) VMHL_Result = 12;
            if (Q==0.05)  VMHL_Result = 13;
            if (Q==0.10)  VMHL_Result = 15;
        }

        if (n==7)
        {
            if (Q==0.005) VMHL_Result = 10;
            if (Q==0.010) VMHL_Result = 11;
            if (Q==0.025) VMHL_Result = 13;
            if (Q==0.05)  VMHL_Result = 14;
            if (Q==0.10)  VMHL_Result = 16;
        }

        if (n==8)
        {
            if (Q==0.005) VMHL_Result = 11;
            if (Q==0.010) VMHL_Result = 12;
            if (Q==0.025) VMHL_Result = 14;
            if (Q==0.05)  VMHL_Result = 15;
            if (Q==0.10)  VMHL_Result = 17;
        }

        if (n==9)
        {
            if (Q==0.005) VMHL_Result = 11;
            if (Q==0.010) VMHL_Result = 13;
            if (Q==0.025) VMHL_Result = 14;
            if (Q==0.05)  VMHL_Result = 16;
            if (Q==0.10)  VMHL_Result = 19;
        }

        if (n==10)
        {
            if (Q==0.001) VMHL_Result = 10;
            if (Q==0.005) VMHL_Result = 12;
            if (Q==0.010) VMHL_Result = 13;
            if (Q==0.025) VMHL_Result = 15;
            if (Q==0.05)  VMHL_Result = 17;
            if (Q==0.10)  VMHL_Result = 20;
        }

        if (n==11)
        {
            if (Q==0.001) VMHL_Result = 10;
            if (Q==0.005) VMHL_Result = 12;
            if (Q==0.010) VMHL_Result = 14;
            if (Q==0.025) VMHL_Result = 16;
            if (Q==0.05)  VMHL_Result = 18;
            if (Q==0.10)  VMHL_Result = 21;
        }

        if (n==12)
        {
            if (Q==0.001) VMHL_Result = 10;
            if (Q==0.005) VMHL_Result = 13;
            if (Q==0.010) VMHL_Result = 15;
            if (Q==0.025) VMHL_Result = 17;
            if (Q==0.05)  VMHL_Result = 19;
            if (Q==0.10)  VMHL_Result = 22;
        }

        if (n==13)
        {
            if (Q==0.001) VMHL_Result = 11;
            if (Q==0.005) VMHL_Result = 13;
            if (Q==0.010) VMHL_Result = 15;
            if (Q==0.025) VMHL_Result = 18;
            if (Q==0.05)  VMHL_Result = 20;
            if (Q==0.10)  VMHL_Result = 23;
        }

        if (n==14)
        {
            if (Q==0.001) VMHL_Result = 11;
            if (Q==0.005) VMHL_Result = 14;
            if (Q==0.010) VMHL_Result = 16;
            if (Q==0.025) VMHL_Result = 19;
            if (Q==0.05)  VMHL_Result = 21;
            if (Q==0.10)  VMHL_Result = 25;
        }

        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 11;
            if (Q==0.005) VMHL_Result = 15;
            if (Q==0.010) VMHL_Result = 17;
            if (Q==0.025) VMHL_Result = 20;
            if (Q==0.05)  VMHL_Result = 22;
            if (Q==0.10)  VMHL_Result = 26;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 12;
            if (Q==0.005) VMHL_Result = 15;
            if (Q==0.010) VMHL_Result = 17;
            if (Q==0.025) VMHL_Result = 21;
            if (Q==0.05)  VMHL_Result = 24;
            if (Q==0.10)  VMHL_Result = 27;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 12;
            if (Q==0.005) VMHL_Result = 16;
            if (Q==0.010) VMHL_Result = 18;
            if (Q==0.025) VMHL_Result = 21;
            if (Q==0.05)  VMHL_Result = 25;
            if (Q==0.10)  VMHL_Result = 28;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 13;
            if (Q==0.005) VMHL_Result = 16;
            if (Q==0.010) VMHL_Result = 19;
            if (Q==0.025) VMHL_Result = 22;
            if (Q==0.05)  VMHL_Result = 26;
            if (Q==0.10)  VMHL_Result = 30;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 13;
            if (Q==0.005) VMHL_Result = 17;
            if (Q==0.010) VMHL_Result = 19;
            if (Q==0.025) VMHL_Result = 23;
            if (Q==0.05)  VMHL_Result = 27;
            if (Q==0.10)  VMHL_Result = 31;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 13;
            if (Q==0.005) VMHL_Result = 18;
            if (Q==0.010) VMHL_Result = 20;
            if (Q==0.025) VMHL_Result = 24;
            if (Q==0.05)  VMHL_Result = 28;
            if (Q==0.10)  VMHL_Result = 32;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 14;
            if (Q==0.005) VMHL_Result = 18;
            if (Q==0.010) VMHL_Result = 21;
            if (Q==0.025) VMHL_Result = 25;
            if (Q==0.05)  VMHL_Result = 29;
            if (Q==0.10)  VMHL_Result = 33;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 14;
            if (Q==0.005) VMHL_Result = 19;
            if (Q==0.010) VMHL_Result = 21;
            if (Q==0.025) VMHL_Result = 26;
            if (Q==0.05)  VMHL_Result = 30;
            if (Q==0.10)  VMHL_Result = 35;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 14;
            if (Q==0.005) VMHL_Result = 19;
            if (Q==0.010) VMHL_Result = 22;
            if (Q==0.025) VMHL_Result = 27;
            if (Q==0.05)  VMHL_Result = 31;
            if (Q==0.10)  VMHL_Result = 36;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 15;
            if (Q==0.005) VMHL_Result = 20;
            if (Q==0.010) VMHL_Result = 23;
            if (Q==0.025) VMHL_Result = 27;
            if (Q==0.05)  VMHL_Result = 32;
            if (Q==0.10)  VMHL_Result = 38;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 15;
            if (Q==0.005) VMHL_Result = 20;
            if (Q==0.010) VMHL_Result = 23;
            if (Q==0.025) VMHL_Result = 28;
            if (Q==0.05)  VMHL_Result = 33;
            if (Q==0.10)  VMHL_Result = 38;
        }
    }

    if (m==5)
    {
        if (n==5)
        {
            if (Q==0.005) VMHL_Result = 15;
            if (Q==0.010) VMHL_Result = 16;
            if (Q==0.025) VMHL_Result = 17;
            if (Q==0.05)  VMHL_Result = 19;
            if (Q==0.10)  VMHL_Result = 20;
        }

        if (n==6)
        {
            if (Q==0.005) VMHL_Result = 16;
            if (Q==0.010) VMHL_Result = 17;
            if (Q==0.025) VMHL_Result = 18;
            if (Q==0.05)  VMHL_Result = 20;
            if (Q==0.10)  VMHL_Result = 22;
        }

        if (n==7)
        {
            if (Q==0.005) VMHL_Result = 16;
            if (Q==0.010) VMHL_Result = 18;
            if (Q==0.025) VMHL_Result = 20;
            if (Q==0.05)  VMHL_Result = 21;
            if (Q==0.10)  VMHL_Result = 23;
        }

        if (n==8)
        {
            if (Q==0.001) VMHL_Result = 15;
            if (Q==0.005) VMHL_Result = 17;
            if (Q==0.010) VMHL_Result = 19;
            if (Q==0.025) VMHL_Result = 21;
            if (Q==0.05)  VMHL_Result = 23;
            if (Q==0.10)  VMHL_Result = 25;
        }

        if (n==9)
        {
            if (Q==0.001) VMHL_Result = 16;
            if (Q==0.005) VMHL_Result = 18;
            if (Q==0.010) VMHL_Result = 20;
            if (Q==0.025) VMHL_Result = 22;
            if (Q==0.05)  VMHL_Result = 24;
            if (Q==0.10)  VMHL_Result = 27;
        }

        if (n==10)
        {
            if (Q==0.001) VMHL_Result = 16;
            if (Q==0.005) VMHL_Result = 19;
            if (Q==0.010) VMHL_Result = 21;
            if (Q==0.025) VMHL_Result = 23;
            if (Q==0.05)  VMHL_Result = 26;
            if (Q==0.10)  VMHL_Result = 28;
        }

        if (n==11)
        {
            if (Q==0.001) VMHL_Result = 17;
            if (Q==0.005) VMHL_Result = 20;
            if (Q==0.010) VMHL_Result = 22;
            if (Q==0.025) VMHL_Result = 24;
            if (Q==0.05)  VMHL_Result = 27;
            if (Q==0.10)  VMHL_Result = 30;
        }

        if (n==12)
        {
            if (Q==0.001) VMHL_Result = 17;
            if (Q==0.005) VMHL_Result = 21;
            if (Q==0.010) VMHL_Result = 23;
            if (Q==0.025) VMHL_Result = 26;
            if (Q==0.05)  VMHL_Result = 28;
            if (Q==0.10)  VMHL_Result = 32;
        }

        if (n==13)
        {
            if (Q==0.001) VMHL_Result = 18;
            if (Q==0.005) VMHL_Result = 22;
            if (Q==0.010) VMHL_Result = 24;
            if (Q==0.025) VMHL_Result = 27;
            if (Q==0.05)  VMHL_Result = 30;
            if (Q==0.10)  VMHL_Result = 33;
        }

        if (n==14)
        {
            if (Q==0.001) VMHL_Result = 18;
            if (Q==0.005) VMHL_Result = 22;
            if (Q==0.010) VMHL_Result = 25;
            if (Q==0.025) VMHL_Result = 28;
            if (Q==0.05)  VMHL_Result = 31;
            if (Q==0.10)  VMHL_Result = 35;
        }

        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 19;
            if (Q==0.005) VMHL_Result = 23;
            if (Q==0.010) VMHL_Result = 26;
            if (Q==0.025) VMHL_Result = 29;
            if (Q==0.05)  VMHL_Result = 33;
            if (Q==0.10)  VMHL_Result = 37;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 20;
            if (Q==0.005) VMHL_Result = 24;
            if (Q==0.010) VMHL_Result = 27;
            if (Q==0.025) VMHL_Result = 30;
            if (Q==0.05)  VMHL_Result = 34;
            if (Q==0.10)  VMHL_Result = 38;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 20;
            if (Q==0.005) VMHL_Result = 25;
            if (Q==0.010) VMHL_Result = 28;
            if (Q==0.025) VMHL_Result = 32;
            if (Q==0.05)  VMHL_Result = 35;
            if (Q==0.10)  VMHL_Result = 40;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 21;
            if (Q==0.005) VMHL_Result = 26;
            if (Q==0.010) VMHL_Result = 29;
            if (Q==0.025) VMHL_Result = 33;
            if (Q==0.05)  VMHL_Result = 37;
            if (Q==0.10)  VMHL_Result = 42;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 22;
            if (Q==0.005) VMHL_Result = 27;
            if (Q==0.010) VMHL_Result = 30;
            if (Q==0.025) VMHL_Result = 34;
            if (Q==0.05)  VMHL_Result = 38;
            if (Q==0.10)  VMHL_Result = 43;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 22;
            if (Q==0.005) VMHL_Result = 28;
            if (Q==0.010) VMHL_Result = 31;
            if (Q==0.025) VMHL_Result = 35;
            if (Q==0.05)  VMHL_Result = 40;
            if (Q==0.10)  VMHL_Result = 45;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 23;
            if (Q==0.005) VMHL_Result = 29;
            if (Q==0.010) VMHL_Result = 32;
            if (Q==0.025) VMHL_Result = 37;
            if (Q==0.05)  VMHL_Result = 41;
            if (Q==0.10)  VMHL_Result = 47;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 23;
            if (Q==0.005) VMHL_Result = 29;
            if (Q==0.010) VMHL_Result = 33;
            if (Q==0.025) VMHL_Result = 38;
            if (Q==0.05)  VMHL_Result = 43;
            if (Q==0.10)  VMHL_Result = 48;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 24;
            if (Q==0.005) VMHL_Result = 30;
            if (Q==0.010) VMHL_Result = 34;
            if (Q==0.025) VMHL_Result = 39;
            if (Q==0.05)  VMHL_Result = 44;
            if (Q==0.10)  VMHL_Result = 50;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 25;
            if (Q==0.005) VMHL_Result = 31;
            if (Q==0.010) VMHL_Result = 35;
            if (Q==0.025) VMHL_Result = 40;
            if (Q==0.05)  VMHL_Result = 45;
            if (Q==0.10)  VMHL_Result = 51;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 25;
            if (Q==0.005) VMHL_Result = 32;
            if (Q==0.010) VMHL_Result = 36;
            if (Q==0.025) VMHL_Result = 42;
            if (Q==0.05)  VMHL_Result = 47;
            if (Q==0.10)  VMHL_Result = 53;
        }
    }

    if (m==6)
    {
        if (n==6)
        {
            if (Q==0.005) VMHL_Result = 23;
            if (Q==0.010) VMHL_Result = 24;
            if (Q==0.025) VMHL_Result = 26;
            if (Q==0.05)  VMHL_Result = 28;
            if (Q==0.10)  VMHL_Result = 30;
        }

        if (n==7)
        {
            if (Q==0.001) VMHL_Result = 21;
            if (Q==0.005) VMHL_Result = 24;
            if (Q==0.010) VMHL_Result = 25;
            if (Q==0.025) VMHL_Result = 27;
            if (Q==0.05)  VMHL_Result = 29;
            if (Q==0.10)  VMHL_Result = 32;
        }

        if (n==8)
        {
            if (Q==0.001) VMHL_Result = 22;
            if (Q==0.005) VMHL_Result = 25;
            if (Q==0.010) VMHL_Result = 27;
            if (Q==0.025) VMHL_Result = 29;
            if (Q==0.05)  VMHL_Result = 31;
            if (Q==0.10)  VMHL_Result = 34;
        }

        if (n==9)
        {
            if (Q==0.001) VMHL_Result = 23;
            if (Q==0.005) VMHL_Result = 26;
            if (Q==0.010) VMHL_Result = 28;
            if (Q==0.025) VMHL_Result = 31;
            if (Q==0.05)  VMHL_Result = 33;
            if (Q==0.10)  VMHL_Result = 36;
        }

        if (n==10)
        {
            if (Q==0.001) VMHL_Result = 24;
            if (Q==0.005) VMHL_Result = 27;
            if (Q==0.010) VMHL_Result = 29;
            if (Q==0.025) VMHL_Result = 32;
            if (Q==0.05)  VMHL_Result = 35;
            if (Q==0.10)  VMHL_Result = 38;
        }

        if (n==11)
        {
            if (Q==0.001) VMHL_Result = 25;
            if (Q==0.005) VMHL_Result = 28;
            if (Q==0.010) VMHL_Result = 30;
            if (Q==0.025) VMHL_Result = 34;
            if (Q==0.05)  VMHL_Result = 37;
            if (Q==0.10)  VMHL_Result = 40;
        }

        if (n==12)
        {
            if (Q==0.001) VMHL_Result = 25;
            if (Q==0.005) VMHL_Result = 30;
            if (Q==0.010) VMHL_Result = 32;
            if (Q==0.025) VMHL_Result = 35;
            if (Q==0.05)  VMHL_Result = 38;
            if (Q==0.10)  VMHL_Result = 42;
        }

        if (n==13)
        {
            if (Q==0.001) VMHL_Result = 26;
            if (Q==0.005) VMHL_Result = 31;
            if (Q==0.010) VMHL_Result = 33;
            if (Q==0.025) VMHL_Result = 37;
            if (Q==0.05)  VMHL_Result = 40;
            if (Q==0.10)  VMHL_Result = 44;
        }

        if (n==14)
        {
            if (Q==0.001) VMHL_Result = 27;
            if (Q==0.005) VMHL_Result = 32;
            if (Q==0.010) VMHL_Result = 34;
            if (Q==0.025) VMHL_Result = 38;
            if (Q==0.05)  VMHL_Result = 42;
            if (Q==0.10)  VMHL_Result = 46;
        }

        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 28;
            if (Q==0.005) VMHL_Result = 33;
            if (Q==0.010) VMHL_Result = 36;
            if (Q==0.025) VMHL_Result = 40;
            if (Q==0.05)  VMHL_Result = 44;
            if (Q==0.10)  VMHL_Result = 48;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 29;
            if (Q==0.005) VMHL_Result = 34;
            if (Q==0.010) VMHL_Result = 37;
            if (Q==0.025) VMHL_Result = 42;
            if (Q==0.05)  VMHL_Result = 46;
            if (Q==0.10)  VMHL_Result = 50;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 30;
            if (Q==0.005) VMHL_Result = 36;
            if (Q==0.010) VMHL_Result = 39;
            if (Q==0.025) VMHL_Result = 43;
            if (Q==0.05)  VMHL_Result = 47;
            if (Q==0.10)  VMHL_Result = 52;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 31;
            if (Q==0.005) VMHL_Result = 37;
            if (Q==0.010) VMHL_Result = 40;
            if (Q==0.025) VMHL_Result = 45;
            if (Q==0.05)  VMHL_Result = 49;
            if (Q==0.10)  VMHL_Result = 55;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 32;
            if (Q==0.005) VMHL_Result = 38;
            if (Q==0.010) VMHL_Result = 41;
            if (Q==0.025) VMHL_Result = 46;
            if (Q==0.05)  VMHL_Result = 51;
            if (Q==0.10)  VMHL_Result = 57;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 33;
            if (Q==0.005) VMHL_Result = 39;
            if (Q==0.010) VMHL_Result = 43;
            if (Q==0.025) VMHL_Result = 48;
            if (Q==0.05)  VMHL_Result = 53;
            if (Q==0.10)  VMHL_Result = 59;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 33;
            if (Q==0.005) VMHL_Result = 40;
            if (Q==0.010) VMHL_Result = 44;
            if (Q==0.025) VMHL_Result = 50;
            if (Q==0.05)  VMHL_Result = 55;
            if (Q==0.10)  VMHL_Result = 61;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 34;
            if (Q==0.005) VMHL_Result = 42;
            if (Q==0.010) VMHL_Result = 45;
            if (Q==0.025) VMHL_Result = 51;
            if (Q==0.05)  VMHL_Result = 57;
            if (Q==0.10)  VMHL_Result = 63;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 35;
            if (Q==0.005) VMHL_Result = 43;
            if (Q==0.010) VMHL_Result = 47;
            if (Q==0.025) VMHL_Result = 53;
            if (Q==0.05)  VMHL_Result = 58;
            if (Q==0.10)  VMHL_Result = 65;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 36;
            if (Q==0.005) VMHL_Result = 44;
            if (Q==0.010) VMHL_Result = 48;
            if (Q==0.025) VMHL_Result = 54;
            if (Q==0.05)  VMHL_Result = 60;
            if (Q==0.10)  VMHL_Result = 67;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 37;
            if (Q==0.005) VMHL_Result = 45;
            if (Q==0.010) VMHL_Result = 50;
            if (Q==0.025) VMHL_Result = 56;
            if (Q==0.05)  VMHL_Result = 62;
            if (Q==0.10)  VMHL_Result = 69;
        }
    }

    if (m==7)
    {
        if (n==7)
        {
            if (Q==0.001) VMHL_Result = 29;
            if (Q==0.005) VMHL_Result = 32;
            if (Q==0.010) VMHL_Result = 34;
            if (Q==0.025) VMHL_Result = 36;
            if (Q==0.05)  VMHL_Result = 39;
            if (Q==0.10)  VMHL_Result = 41;
        }

        if (n==8)
        {
            if (Q==0.001) VMHL_Result = 30;
            if (Q==0.005) VMHL_Result = 34;
            if (Q==0.010) VMHL_Result = 35;
            if (Q==0.025) VMHL_Result = 38;
            if (Q==0.05)  VMHL_Result = 41;
            if (Q==0.10)  VMHL_Result = 44;
        }

        if (n==9)
        {
            if (Q==0.001) VMHL_Result = 31;
            if (Q==0.005) VMHL_Result = 35;
            if (Q==0.010) VMHL_Result = 37;
            if (Q==0.025) VMHL_Result = 40;
            if (Q==0.05)  VMHL_Result = 43;
            if (Q==0.10)  VMHL_Result = 46;
        }

        if (n==10)
        {
            if (Q==0.001) VMHL_Result = 33;
            if (Q==0.005) VMHL_Result = 37;
            if (Q==0.010) VMHL_Result = 39;
            if (Q==0.025) VMHL_Result = 42;
            if (Q==0.05)  VMHL_Result = 45;
            if (Q==0.10)  VMHL_Result = 49;
        }

        if (n==11)
        {
            if (Q==0.001) VMHL_Result = 34;
            if (Q==0.005) VMHL_Result = 38;
            if (Q==0.010) VMHL_Result = 40;
            if (Q==0.025) VMHL_Result = 44;
            if (Q==0.05)  VMHL_Result = 47;
            if (Q==0.10)  VMHL_Result = 51;
        }

        if (n==12)
        {
            if (Q==0.001) VMHL_Result = 35;
            if (Q==0.005) VMHL_Result = 40;
            if (Q==0.010) VMHL_Result = 42;
            if (Q==0.025) VMHL_Result = 46;
            if (Q==0.05)  VMHL_Result = 49;
            if (Q==0.10)  VMHL_Result = 54;
        }

        if (n==13)
        {
            if (Q==0.001) VMHL_Result = 36;
            if (Q==0.005) VMHL_Result = 41;
            if (Q==0.010) VMHL_Result = 44;
            if (Q==0.025) VMHL_Result = 48;
            if (Q==0.05)  VMHL_Result = 52;
            if (Q==0.10)  VMHL_Result = 56;
        }

        if (n==14)
        {
            if (Q==0.001) VMHL_Result = 37;
            if (Q==0.005) VMHL_Result = 43;
            if (Q==0.010) VMHL_Result = 45;
            if (Q==0.025) VMHL_Result = 50;
            if (Q==0.05)  VMHL_Result = 54;
            if (Q==0.10)  VMHL_Result = 59;
        }

        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 38;
            if (Q==0.005) VMHL_Result = 44;
            if (Q==0.010) VMHL_Result = 47;
            if (Q==0.025) VMHL_Result = 52;
            if (Q==0.05)  VMHL_Result = 56;
            if (Q==0.10)  VMHL_Result = 61;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 39;
            if (Q==0.005) VMHL_Result = 46;
            if (Q==0.010) VMHL_Result = 49;
            if (Q==0.025) VMHL_Result = 54;
            if (Q==0.05)  VMHL_Result = 58;
            if (Q==0.10)  VMHL_Result = 64;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 41;
            if (Q==0.005) VMHL_Result = 47;
            if (Q==0.010) VMHL_Result = 51;
            if (Q==0.025) VMHL_Result = 56;
            if (Q==0.05)  VMHL_Result = 61;
            if (Q==0.10)  VMHL_Result = 66;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 42;
            if (Q==0.005) VMHL_Result = 49;
            if (Q==0.010) VMHL_Result = 52;
            if (Q==0.025) VMHL_Result = 58;
            if (Q==0.05)  VMHL_Result = 63;
            if (Q==0.10)  VMHL_Result = 69;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 43;
            if (Q==0.005) VMHL_Result = 50;
            if (Q==0.010) VMHL_Result = 54;
            if (Q==0.025) VMHL_Result = 60;
            if (Q==0.05)  VMHL_Result = 65;
            if (Q==0.10)  VMHL_Result = 71;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 44;
            if (Q==0.005) VMHL_Result = 52;
            if (Q==0.010) VMHL_Result = 56;
            if (Q==0.025) VMHL_Result = 62;
            if (Q==0.05)  VMHL_Result = 67;
            if (Q==0.10)  VMHL_Result = 74;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 46;
            if (Q==0.005) VMHL_Result = 53;
            if (Q==0.010) VMHL_Result = 58;
            if (Q==0.025) VMHL_Result = 64;
            if (Q==0.05)  VMHL_Result = 69;
            if (Q==0.10)  VMHL_Result = 76;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 47;
            if (Q==0.005) VMHL_Result = 55;
            if (Q==0.010) VMHL_Result = 59;
            if (Q==0.025) VMHL_Result = 66;
            if (Q==0.05)  VMHL_Result = 72;
            if (Q==0.10)  VMHL_Result = 79;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 48;
            if (Q==0.005) VMHL_Result = 57;
            if (Q==0.010) VMHL_Result = 61;
            if (Q==0.025) VMHL_Result = 68;
            if (Q==0.05)  VMHL_Result = 74;
            if (Q==0.10)  VMHL_Result = 81;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 49;
            if (Q==0.005) VMHL_Result = 58;
            if (Q==0.010) VMHL_Result = 63;
            if (Q==0.025) VMHL_Result = 70;
            if (Q==0.05)  VMHL_Result = 76;
            if (Q==0.10)  VMHL_Result = 84;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 50;
            if (Q==0.005) VMHL_Result = 60;
            if (Q==0.010) VMHL_Result = 64;
            if (Q==0.025) VMHL_Result = 72;
            if (Q==0.05)  VMHL_Result = 78;
            if (Q==0.10)  VMHL_Result = 86;
        }
    }

    if (m==8)
    {
        if (n==8)
        {
            if (Q==0.001) VMHL_Result = 40;
            if (Q==0.005) VMHL_Result = 43;
            if (Q==0.010) VMHL_Result = 45;
            if (Q==0.025) VMHL_Result = 49;
            if (Q==0.05)  VMHL_Result = 51;
            if (Q==0.10)  VMHL_Result = 55;
        }

        if (n==9)
        {
            if (Q==0.001) VMHL_Result = 41;
            if (Q==0.005) VMHL_Result = 45;
            if (Q==0.010) VMHL_Result = 47;
            if (Q==0.025) VMHL_Result = 51;
            if (Q==0.05)  VMHL_Result = 54;
            if (Q==0.10)  VMHL_Result = 58;
        }

        if (n==10)
        {
            if (Q==0.001) VMHL_Result = 42;
            if (Q==0.005) VMHL_Result = 47;
            if (Q==0.010) VMHL_Result = 49;
            if (Q==0.025) VMHL_Result = 53;
            if (Q==0.05)  VMHL_Result = 56;
            if (Q==0.10)  VMHL_Result = 60;
        }

        if (n==11)
        {
            if (Q==0.001) VMHL_Result = 44;
            if (Q==0.005) VMHL_Result = 49;
            if (Q==0.010) VMHL_Result = 51;
            if (Q==0.025) VMHL_Result = 55;
            if (Q==0.05)  VMHL_Result = 59;
            if (Q==0.10)  VMHL_Result = 63;
        }

        if (n==12)
        {
            if (Q==0.001) VMHL_Result = 45;
            if (Q==0.005) VMHL_Result = 51;
            if (Q==0.010) VMHL_Result = 53;
            if (Q==0.025) VMHL_Result = 58;
            if (Q==0.05)  VMHL_Result = 62;
            if (Q==0.10)  VMHL_Result = 66;
        }

        if (n==13)
        {
            if (Q==0.001) VMHL_Result = 47;
            if (Q==0.005) VMHL_Result = 53;
            if (Q==0.010) VMHL_Result = 56;
            if (Q==0.025) VMHL_Result = 60;
            if (Q==0.05)  VMHL_Result = 64;
            if (Q==0.10)  VMHL_Result = 69;
        }

        if (n==14)
        {
            if (Q==0.001) VMHL_Result = 48;
            if (Q==0.005) VMHL_Result = 54;
            if (Q==0.010) VMHL_Result = 58;
            if (Q==0.025) VMHL_Result = 62;
            if (Q==0.05)  VMHL_Result = 67;
            if (Q==0.10)  VMHL_Result = 72;
        }

        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 50;
            if (Q==0.005) VMHL_Result = 56;
            if (Q==0.010) VMHL_Result = 60;
            if (Q==0.025) VMHL_Result = 65;
            if (Q==0.05)  VMHL_Result = 69;
            if (Q==0.10)  VMHL_Result = 75;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 51;
            if (Q==0.005) VMHL_Result = 58;
            if (Q==0.010) VMHL_Result = 62;
            if (Q==0.025) VMHL_Result = 67;
            if (Q==0.05)  VMHL_Result = 72;
            if (Q==0.10)  VMHL_Result = 78;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 53;
            if (Q==0.005) VMHL_Result = 60;
            if (Q==0.010) VMHL_Result = 64;
            if (Q==0.025) VMHL_Result = 70;
            if (Q==0.05)  VMHL_Result = 75;
            if (Q==0.10)  VMHL_Result = 81;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 54;
            if (Q==0.005) VMHL_Result = 62;
            if (Q==0.010) VMHL_Result = 66;
            if (Q==0.025) VMHL_Result = 72;
            if (Q==0.05)  VMHL_Result = 77;
            if (Q==0.10)  VMHL_Result = 84;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 56;
            if (Q==0.005) VMHL_Result = 64;
            if (Q==0.010) VMHL_Result = 68;
            if (Q==0.025) VMHL_Result = 74;
            if (Q==0.05)  VMHL_Result = 80;
            if (Q==0.10)  VMHL_Result = 87;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 57;
            if (Q==0.005) VMHL_Result = 66;
            if (Q==0.010) VMHL_Result = 70;
            if (Q==0.025) VMHL_Result = 77;
            if (Q==0.05)  VMHL_Result = 83;
            if (Q==0.10)  VMHL_Result = 90;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 59;
            if (Q==0.005) VMHL_Result = 68;
            if (Q==0.010) VMHL_Result = 72;
            if (Q==0.025) VMHL_Result = 79;
            if (Q==0.05)  VMHL_Result = 85;
            if (Q==0.10)  VMHL_Result = 92;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 60;
            if (Q==0.005) VMHL_Result = 70;
            if (Q==0.010) VMHL_Result = 74;
            if (Q==0.025) VMHL_Result = 81;
            if (Q==0.05)  VMHL_Result = 88;
            if (Q==0.10)  VMHL_Result = 95;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 62;
            if (Q==0.005) VMHL_Result = 71;
            if (Q==0.010) VMHL_Result = 76;
            if (Q==0.025) VMHL_Result = 84;
            if (Q==0.05)  VMHL_Result = 90;
            if (Q==0.10)  VMHL_Result = 98;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 64;
            if (Q==0.005) VMHL_Result = 73;
            if (Q==0.010) VMHL_Result = 78;
            if (Q==0.025) VMHL_Result = 86;
            if (Q==0.05)  VMHL_Result = 93;
            if (Q==0.10)  VMHL_Result = 101;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 65;
            if (Q==0.005) VMHL_Result = 75;
            if (Q==0.010) VMHL_Result = 81;
            if (Q==0.025) VMHL_Result = 89;
            if (Q==0.05)  VMHL_Result = 96;
            if (Q==0.10)  VMHL_Result = 104;
        }
    }

    if (m==9)
    {
        if (n==9)
        {
            if (Q==0.001) VMHL_Result = 52;
            if (Q==0.005) VMHL_Result = 56;
            if (Q==0.010) VMHL_Result = 59;
            if (Q==0.025) VMHL_Result = 62;
            if (Q==0.05)  VMHL_Result = 66;
            if (Q==0.10)  VMHL_Result = 70;
        }

        if (n==10)
        {
            if (Q==0.001) VMHL_Result = 53;
            if (Q==0.005) VMHL_Result = 58;
            if (Q==0.010) VMHL_Result = 61;
            if (Q==0.025) VMHL_Result = 65;
            if (Q==0.05)  VMHL_Result = 69;
            if (Q==0.10)  VMHL_Result = 73;
        }

        if (n==11)
        {
            if (Q==0.001) VMHL_Result = 55;
            if (Q==0.005) VMHL_Result = 61;
            if (Q==0.010) VMHL_Result = 63;
            if (Q==0.025) VMHL_Result = 68;
            if (Q==0.05)  VMHL_Result = 72;
            if (Q==0.10)  VMHL_Result = 76;
        }

        if (n==12)
        {
            if (Q==0.001) VMHL_Result = 57;
            if (Q==0.005) VMHL_Result = 63;
            if (Q==0.010) VMHL_Result = 66;
            if (Q==0.025) VMHL_Result = 71;
            if (Q==0.05)  VMHL_Result = 75;
            if (Q==0.10)  VMHL_Result = 80;
        }

        if (n==13)
        {
            if (Q==0.001) VMHL_Result = 59;
            if (Q==0.005) VMHL_Result = 65;
            if (Q==0.010) VMHL_Result = 68;
            if (Q==0.025) VMHL_Result = 73;
            if (Q==0.05)  VMHL_Result = 78;
            if (Q==0.10)  VMHL_Result = 83;
        }

        if (n==14)
        {
            if (Q==0.001) VMHL_Result = 60;
            if (Q==0.005) VMHL_Result = 67;
            if (Q==0.010) VMHL_Result = 71;
            if (Q==0.025) VMHL_Result = 76;
            if (Q==0.05)  VMHL_Result = 81;
            if (Q==0.10)  VMHL_Result = 86;
        }

        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 62;
            if (Q==0.005) VMHL_Result = 69;
            if (Q==0.010) VMHL_Result = 73;
            if (Q==0.025) VMHL_Result = 79;
            if (Q==0.05)  VMHL_Result = 84;
            if (Q==0.10)  VMHL_Result = 90;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 64;
            if (Q==0.005) VMHL_Result = 72;
            if (Q==0.010) VMHL_Result = 76;
            if (Q==0.025) VMHL_Result = 82;
            if (Q==0.05)  VMHL_Result = 87;
            if (Q==0.10)  VMHL_Result = 93;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 66;
            if (Q==0.005) VMHL_Result = 74;
            if (Q==0.010) VMHL_Result = 78;
            if (Q==0.025) VMHL_Result = 84;
            if (Q==0.05)  VMHL_Result = 90;
            if (Q==0.10)  VMHL_Result = 97;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 68;
            if (Q==0.005) VMHL_Result = 76;
            if (Q==0.010) VMHL_Result = 81;
            if (Q==0.025) VMHL_Result = 87;
            if (Q==0.05)  VMHL_Result = 93;
            if (Q==0.10)  VMHL_Result = 100;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 70;
            if (Q==0.005) VMHL_Result = 78;
            if (Q==0.010) VMHL_Result = 83;
            if (Q==0.025) VMHL_Result = 90;
            if (Q==0.05)  VMHL_Result = 96;
            if (Q==0.10)  VMHL_Result = 103;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 71;
            if (Q==0.005) VMHL_Result = 81;
            if (Q==0.010) VMHL_Result = 85;
            if (Q==0.025) VMHL_Result = 93;
            if (Q==0.05)  VMHL_Result = 99;
            if (Q==0.10)  VMHL_Result = 107;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 73;
            if (Q==0.005) VMHL_Result = 83;
            if (Q==0.010) VMHL_Result = 88;
            if (Q==0.025) VMHL_Result = 95;
            if (Q==0.05)  VMHL_Result = 102;
            if (Q==0.10)  VMHL_Result = 110;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 75;
            if (Q==0.005) VMHL_Result = 85;
            if (Q==0.010) VMHL_Result = 90;
            if (Q==0.025) VMHL_Result = 98;
            if (Q==0.05)  VMHL_Result = 105;
            if (Q==0.10)  VMHL_Result = 113;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 77;
            if (Q==0.005) VMHL_Result = 88;
            if (Q==0.010) VMHL_Result = 93;
            if (Q==0.025) VMHL_Result = 101;
            if (Q==0.05)  VMHL_Result = 108;
            if (Q==0.10)  VMHL_Result = 117;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 79;
            if (Q==0.005) VMHL_Result = 90;
            if (Q==0.010) VMHL_Result = 95;
            if (Q==0.025) VMHL_Result = 104;
            if (Q==0.05)  VMHL_Result = 111;
            if (Q==0.10)  VMHL_Result = 120;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 81;
            if (Q==0.005) VMHL_Result = 92;
            if (Q==0.010) VMHL_Result = 98;
            if (Q==0.025) VMHL_Result = 107;
            if (Q==0.05)  VMHL_Result = 114;
            if (Q==0.10)  VMHL_Result = 123;
        }
    }

    if (m==10)
    {
        if (n==10)
        {
            if (Q==0.001) VMHL_Result = 65;
            if (Q==0.005) VMHL_Result = 71;
            if (Q==0.010) VMHL_Result = 74;
            if (Q==0.025) VMHL_Result = 78;
            if (Q==0.05)  VMHL_Result = 82;
            if (Q==0.10)  VMHL_Result = 87;
        }

        if (n==11)
        {
            if (Q==0.001) VMHL_Result = 67;
            if (Q==0.005) VMHL_Result = 73;
            if (Q==0.010) VMHL_Result = 77;
            if (Q==0.025) VMHL_Result = 81;
            if (Q==0.05)  VMHL_Result = 86;
            if (Q==0.10)  VMHL_Result = 91;
        }

        if (n==12)
        {
            if (Q==0.001) VMHL_Result = 69;
            if (Q==0.005) VMHL_Result = 76;
            if (Q==0.010) VMHL_Result = 79;
            if (Q==0.025) VMHL_Result = 84;
            if (Q==0.05)  VMHL_Result = 89;
            if (Q==0.10)  VMHL_Result = 94;
        }

        if (n==13)
        {
            if (Q==0.001) VMHL_Result = 72;
            if (Q==0.005) VMHL_Result = 79;
            if (Q==0.010) VMHL_Result = 82;
            if (Q==0.025) VMHL_Result = 88;
            if (Q==0.05)  VMHL_Result = 92;
            if (Q==0.10)  VMHL_Result = 98;
        }

        if (n==14)
        {
            if (Q==0.001) VMHL_Result = 74;
            if (Q==0.005) VMHL_Result = 81;
            if (Q==0.010) VMHL_Result = 85;
            if (Q==0.025) VMHL_Result = 91;
            if (Q==0.05)  VMHL_Result = 96;
            if (Q==0.10)  VMHL_Result = 102;
        }

        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 76;
            if (Q==0.005) VMHL_Result = 84;
            if (Q==0.010) VMHL_Result = 88;
            if (Q==0.025) VMHL_Result = 94;
            if (Q==0.05)  VMHL_Result = 99;
            if (Q==0.10)  VMHL_Result = 106;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 78;
            if (Q==0.005) VMHL_Result = 86;
            if (Q==0.010) VMHL_Result = 91;
            if (Q==0.025) VMHL_Result = 97;
            if (Q==0.05)  VMHL_Result = 103;
            if (Q==0.10)  VMHL_Result = 109;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 80;
            if (Q==0.005) VMHL_Result = 89;
            if (Q==0.010) VMHL_Result = 93;
            if (Q==0.025) VMHL_Result = 100;
            if (Q==0.05)  VMHL_Result = 106;
            if (Q==0.10)  VMHL_Result = 113;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 82;
            if (Q==0.005) VMHL_Result = 92;
            if (Q==0.010) VMHL_Result = 96;
            if (Q==0.025) VMHL_Result = 103;
            if (Q==0.05)  VMHL_Result = 110;
            if (Q==0.10)  VMHL_Result = 117;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 84;
            if (Q==0.005) VMHL_Result = 94;
            if (Q==0.010) VMHL_Result = 99;
            if (Q==0.025) VMHL_Result = 107;
            if (Q==0.05)  VMHL_Result = 113;
            if (Q==0.10)  VMHL_Result = 121;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 87;
            if (Q==0.005) VMHL_Result = 97;
            if (Q==0.010) VMHL_Result = 102;
            if (Q==0.025) VMHL_Result = 110;
            if (Q==0.05)  VMHL_Result = 117;
            if (Q==0.10)  VMHL_Result = 125;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 89;
            if (Q==0.005) VMHL_Result = 99;
            if (Q==0.010) VMHL_Result = 105;
            if (Q==0.025) VMHL_Result = 113;
            if (Q==0.05)  VMHL_Result = 120;
            if (Q==0.10)  VMHL_Result = 128;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 91;
            if (Q==0.005) VMHL_Result = 102;
            if (Q==0.010) VMHL_Result = 108;
            if (Q==0.025) VMHL_Result = 116;
            if (Q==0.05)  VMHL_Result = 123;
            if (Q==0.10)  VMHL_Result = 132;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 93;
            if (Q==0.005) VMHL_Result = 105;
            if (Q==0.010) VMHL_Result = 110;
            if (Q==0.025) VMHL_Result = 119;
            if (Q==0.05)  VMHL_Result = 127;
            if (Q==0.10)  VMHL_Result = 136;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 95;
            if (Q==0.005) VMHL_Result = 107;
            if (Q==0.010) VMHL_Result = 113;
            if (Q==0.025) VMHL_Result = 122;
            if (Q==0.05)  VMHL_Result = 130;
            if (Q==0.10)  VMHL_Result = 140;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 98;
            if (Q==0.005) VMHL_Result = 110;
            if (Q==0.010) VMHL_Result = 116;
            if (Q==0.025) VMHL_Result = 126;
            if (Q==0.05)  VMHL_Result = 134;
            if (Q==0.10)  VMHL_Result = 144;
        }

    }

    if (m==11)
    {
        if (n==11)
        {
            if (Q==0.001) VMHL_Result = 81;
            if (Q==0.005) VMHL_Result = 87;
            if (Q==0.010) VMHL_Result = 91;
            if (Q==0.025) VMHL_Result = 96;
            if (Q==0.05)  VMHL_Result = 100;
            if (Q==0.10)  VMHL_Result = 106;
        }

        if (n==12)
        {
            if (Q==0.001) VMHL_Result = 83;
            if (Q==0.005) VMHL_Result = 90;
            if (Q==0.010) VMHL_Result = 94;
            if (Q==0.025) VMHL_Result = 99;
            if (Q==0.05)  VMHL_Result = 104;
            if (Q==0.10)  VMHL_Result = 110;
        }

        if (n==13)
        {
            if (Q==0.001) VMHL_Result = 86;
            if (Q==0.005) VMHL_Result = 93;
            if (Q==0.010) VMHL_Result = 97;
            if (Q==0.025) VMHL_Result = 103;
            if (Q==0.05)  VMHL_Result = 108;
            if (Q==0.10)  VMHL_Result = 114;
        }

        if (n==14)
        {
            if (Q==0.001) VMHL_Result = 88;
            if (Q==0.005) VMHL_Result = 96;
            if (Q==0.010) VMHL_Result = 100;
            if (Q==0.025) VMHL_Result = 106;
            if (Q==0.05)  VMHL_Result = 112;
            if (Q==0.10)  VMHL_Result = 118;
        }

        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 90;
            if (Q==0.005) VMHL_Result = 99;
            if (Q==0.010) VMHL_Result = 103;
            if (Q==0.025) VMHL_Result = 110;
            if (Q==0.05)  VMHL_Result = 116;
            if (Q==0.10)  VMHL_Result = 123;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 93;
            if (Q==0.005) VMHL_Result = 102;
            if (Q==0.010) VMHL_Result = 107;
            if (Q==0.025) VMHL_Result = 113;
            if (Q==0.05)  VMHL_Result = 120;
            if (Q==0.10)  VMHL_Result = 127;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 95;
            if (Q==0.005) VMHL_Result = 105;
            if (Q==0.010) VMHL_Result = 110;
            if (Q==0.025) VMHL_Result = 117;
            if (Q==0.05)  VMHL_Result = 123;
            if (Q==0.10)  VMHL_Result = 131;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 98;
            if (Q==0.005) VMHL_Result = 108;
            if (Q==0.010) VMHL_Result = 113;
            if (Q==0.025) VMHL_Result = 121;
            if (Q==0.05)  VMHL_Result = 127;
            if (Q==0.10)  VMHL_Result = 135;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 100;
            if (Q==0.005) VMHL_Result = 111;
            if (Q==0.010) VMHL_Result = 116;
            if (Q==0.025) VMHL_Result = 124;
            if (Q==0.05)  VMHL_Result = 131;
            if (Q==0.10)  VMHL_Result = 139;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 103;
            if (Q==0.005) VMHL_Result = 114;
            if (Q==0.010) VMHL_Result = 119;
            if (Q==0.025) VMHL_Result = 128;
            if (Q==0.05)  VMHL_Result = 135;
            if (Q==0.10)  VMHL_Result = 144;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 106;
            if (Q==0.005) VMHL_Result = 117;
            if (Q==0.010) VMHL_Result = 123;
            if (Q==0.025) VMHL_Result = 131;
            if (Q==0.05)  VMHL_Result = 139;
            if (Q==0.10)  VMHL_Result = 148;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 108;
            if (Q==0.005) VMHL_Result = 120;
            if (Q==0.010) VMHL_Result = 126;
            if (Q==0.025) VMHL_Result = 135;
            if (Q==0.05)  VMHL_Result = 143;
            if (Q==0.10)  VMHL_Result = 152;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 111;
            if (Q==0.005) VMHL_Result = 123;
            if (Q==0.010) VMHL_Result = 129;
            if (Q==0.025) VMHL_Result = 139;
            if (Q==0.05)  VMHL_Result = 147;
            if (Q==0.10)  VMHL_Result = 156;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 113;
            if (Q==0.005) VMHL_Result = 126;
            if (Q==0.010) VMHL_Result = 132;
            if (Q==0.025) VMHL_Result = 142;
            if (Q==0.05)  VMHL_Result = 151;
            if (Q==0.10)  VMHL_Result = 161;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 116;
            if (Q==0.005) VMHL_Result = 129;
            if (Q==0.010) VMHL_Result = 136;
            if (Q==0.025) VMHL_Result = 146;
            if (Q==0.05)  VMHL_Result = 155;
            if (Q==0.10)  VMHL_Result = 165;
        }
    }

    if (m==12)
    {
        if (n==12)
        {
            if (Q==0.001) VMHL_Result = 98;
            if (Q==0.005) VMHL_Result = 105;
            if (Q==0.010) VMHL_Result = 109;
            if (Q==0.025) VMHL_Result = 115;
            if (Q==0.05)  VMHL_Result = 120;
            if (Q==0.10)  VMHL_Result = 127;
        }

        if (n==13)
        {
            if (Q==0.001) VMHL_Result = 101;
            if (Q==0.005) VMHL_Result = 109;
            if (Q==0.010) VMHL_Result = 113;
            if (Q==0.025) VMHL_Result = 119;
            if (Q==0.05)  VMHL_Result = 125;
            if (Q==0.10)  VMHL_Result = 131;
        }

        if (n==14)
        {
            if (Q==0.001) VMHL_Result = 103;
            if (Q==0.005) VMHL_Result = 112;
            if (Q==0.010) VMHL_Result = 116;
            if (Q==0.025) VMHL_Result = 123;
            if (Q==0.05)  VMHL_Result = 129;
            if (Q==0.10)  VMHL_Result = 136;
        }

        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 106;
            if (Q==0.005) VMHL_Result = 115;
            if (Q==0.010) VMHL_Result = 120;
            if (Q==0.025) VMHL_Result = 127;
            if (Q==0.05)  VMHL_Result = 133;
            if (Q==0.10)  VMHL_Result = 141;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 109;
            if (Q==0.005) VMHL_Result = 119;
            if (Q==0.010) VMHL_Result = 124;
            if (Q==0.025) VMHL_Result = 131;
            if (Q==0.05)  VMHL_Result = 138;
            if (Q==0.10)  VMHL_Result = 145;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 112;
            if (Q==0.005) VMHL_Result = 122;
            if (Q==0.010) VMHL_Result = 127;
            if (Q==0.025) VMHL_Result = 135;
            if (Q==0.05)  VMHL_Result = 142;
            if (Q==0.10)  VMHL_Result = 150;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 115;
            if (Q==0.005) VMHL_Result = 125;
            if (Q==0.010) VMHL_Result = 131;
            if (Q==0.025) VMHL_Result = 139;
            if (Q==0.05)  VMHL_Result = 146;
            if (Q==0.10)  VMHL_Result = 155;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 118;
            if (Q==0.005) VMHL_Result = 129;
            if (Q==0.010) VMHL_Result = 134;
            if (Q==0.025) VMHL_Result = 143;
            if (Q==0.05)  VMHL_Result = 150;
            if (Q==0.10)  VMHL_Result = 159;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 120;
            if (Q==0.005) VMHL_Result = 132;
            if (Q==0.010) VMHL_Result = 138;
            if (Q==0.025) VMHL_Result = 147;
            if (Q==0.05)  VMHL_Result = 155;
            if (Q==0.10)  VMHL_Result = 164;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 123;
            if (Q==0.005) VMHL_Result = 136;
            if (Q==0.010) VMHL_Result = 142;
            if (Q==0.025) VMHL_Result = 151;
            if (Q==0.05)  VMHL_Result = 159;
            if (Q==0.10)  VMHL_Result = 169;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 126;
            if (Q==0.005) VMHL_Result = 139;
            if (Q==0.010) VMHL_Result = 145;
            if (Q==0.025) VMHL_Result = 155;
            if (Q==0.05)  VMHL_Result = 163;
            if (Q==0.10)  VMHL_Result = 173;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 129;
            if (Q==0.005) VMHL_Result = 142;
            if (Q==0.010) VMHL_Result = 149;
            if (Q==0.025) VMHL_Result = 159;
            if (Q==0.05)  VMHL_Result = 168;
            if (Q==0.10)  VMHL_Result = 178;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 132;
            if (Q==0.005) VMHL_Result = 146;
            if (Q==0.010) VMHL_Result = 153;
            if (Q==0.025) VMHL_Result = 163;
            if (Q==0.05)  VMHL_Result = 172;
            if (Q==0.10)  VMHL_Result = 183;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 135;
            if (Q==0.005) VMHL_Result = 149;
            if (Q==0.010) VMHL_Result = 156;
            if (Q==0.025) VMHL_Result = 167;
            if (Q==0.05)  VMHL_Result = 176;
            if (Q==0.10)  VMHL_Result = 187;
        }
    }

    if (m==13)
    {
        if (n==13)
        {
            if (Q==0.001) VMHL_Result = 117;
            if (Q==0.005) VMHL_Result = 125;
            if (Q==0.010) VMHL_Result = 130;
            if (Q==0.025) VMHL_Result = 136;
            if (Q==0.05)  VMHL_Result = 142;
            if (Q==0.10)  VMHL_Result = 149;
        }

        if (n==14)
        {
            if (Q==0.001) VMHL_Result = 120;
            if (Q==0.005) VMHL_Result = 129;
            if (Q==0.010) VMHL_Result = 134;
            if (Q==0.025) VMHL_Result = 141;
            if (Q==0.05)  VMHL_Result = 147;
            if (Q==0.10)  VMHL_Result = 154;
        }

        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 123;
            if (Q==0.005) VMHL_Result = 133;
            if (Q==0.010) VMHL_Result = 138;
            if (Q==0.025) VMHL_Result = 145;
            if (Q==0.05)  VMHL_Result = 152;
            if (Q==0.10)  VMHL_Result = 159;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 126;
            if (Q==0.005) VMHL_Result = 136;
            if (Q==0.010) VMHL_Result = 142;
            if (Q==0.025) VMHL_Result = 150;
            if (Q==0.05)  VMHL_Result = 156;
            if (Q==0.10)  VMHL_Result = 165;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 129;
            if (Q==0.005) VMHL_Result = 140;
            if (Q==0.010) VMHL_Result = 146;
            if (Q==0.025) VMHL_Result = 154;
            if (Q==0.05)  VMHL_Result = 161;
            if (Q==0.10)  VMHL_Result = 170;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 133;
            if (Q==0.005) VMHL_Result = 144;
            if (Q==0.010) VMHL_Result = 150;
            if (Q==0.025) VMHL_Result = 158;
            if (Q==0.05)  VMHL_Result = 166;
            if (Q==0.10)  VMHL_Result = 175;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 136;
            if (Q==0.005) VMHL_Result = 148;
            if (Q==0.010) VMHL_Result = 154;
            if (Q==0.025) VMHL_Result = 163;
            if (Q==0.05)  VMHL_Result = 171;
            if (Q==0.10)  VMHL_Result = 180;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 139;
            if (Q==0.005) VMHL_Result = 151;
            if (Q==0.010) VMHL_Result = 158;
            if (Q==0.025) VMHL_Result = 167;
            if (Q==0.05)  VMHL_Result = 175;
            if (Q==0.10)  VMHL_Result = 185;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 142;
            if (Q==0.005) VMHL_Result = 155;
            if (Q==0.010) VMHL_Result = 162;
            if (Q==0.025) VMHL_Result = 171;
            if (Q==0.05)  VMHL_Result = 180;
            if (Q==0.10)  VMHL_Result = 190;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 145;
            if (Q==0.005) VMHL_Result = 159;
            if (Q==0.010) VMHL_Result = 166;
            if (Q==0.025) VMHL_Result = 176;
            if (Q==0.05)  VMHL_Result = 185;
            if (Q==0.10)  VMHL_Result = 195;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 149;
            if (Q==0.005) VMHL_Result = 163;
            if (Q==0.010) VMHL_Result = 170;
            if (Q==0.025) VMHL_Result = 180;
            if (Q==0.05)  VMHL_Result = 189;
            if (Q==0.10)  VMHL_Result = 200;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 152;
            if (Q==0.005) VMHL_Result = 166;
            if (Q==0.010) VMHL_Result = 174;
            if (Q==0.025) VMHL_Result = 185;
            if (Q==0.05)  VMHL_Result = 194;
            if (Q==0.10)  VMHL_Result = 205;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 155;
            if (Q==0.005) VMHL_Result = 170;
            if (Q==0.010) VMHL_Result = 178;
            if (Q==0.025) VMHL_Result = 189;
            if (Q==0.05)  VMHL_Result = 199;
            if (Q==0.10)  VMHL_Result = 211;
        }
    }

    if (m==14)
    {
        if (n==14)
        {
            if (Q==0.001) VMHL_Result = 137;
            if (Q==0.005) VMHL_Result = 147;
            if (Q==0.010) VMHL_Result = 152;
            if (Q==0.025) VMHL_Result = 160;
            if (Q==0.05)  VMHL_Result = 166;
            if (Q==0.10)  VMHL_Result = 174;
        }

        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 141;
            if (Q==0.005) VMHL_Result = 151;
            if (Q==0.010) VMHL_Result = 156;
            if (Q==0.025) VMHL_Result = 164;
            if (Q==0.05)  VMHL_Result = 171;
            if (Q==0.10)  VMHL_Result = 179;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 144;
            if (Q==0.005) VMHL_Result = 155;
            if (Q==0.010) VMHL_Result = 161;
            if (Q==0.025) VMHL_Result = 169;
            if (Q==0.05)  VMHL_Result = 176;
            if (Q==0.10)  VMHL_Result = 185;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 148;
            if (Q==0.005) VMHL_Result = 159;
            if (Q==0.010) VMHL_Result = 165;
            if (Q==0.025) VMHL_Result = 174;
            if (Q==0.05)  VMHL_Result = 182;
            if (Q==0.10)  VMHL_Result = 190;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 151;
            if (Q==0.005) VMHL_Result = 163;
            if (Q==0.010) VMHL_Result = 170;
            if (Q==0.025) VMHL_Result = 179;
            if (Q==0.05)  VMHL_Result = 187;
            if (Q==0.10)  VMHL_Result = 196;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 155;
            if (Q==0.005) VMHL_Result = 168;
            if (Q==0.010) VMHL_Result = 174;
            if (Q==0.025) VMHL_Result = 183;
            if (Q==0.05)  VMHL_Result = 192;
            if (Q==0.10)  VMHL_Result = 202;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 159;
            if (Q==0.005) VMHL_Result = 172;
            if (Q==0.010) VMHL_Result = 178;
            if (Q==0.025) VMHL_Result = 188;
            if (Q==0.05)  VMHL_Result = 197;
            if (Q==0.10)  VMHL_Result = 207;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 162;
            if (Q==0.005) VMHL_Result = 176;
            if (Q==0.010) VMHL_Result = 183;
            if (Q==0.025) VMHL_Result = 193;
            if (Q==0.05)  VMHL_Result = 202;
            if (Q==0.10)  VMHL_Result = 213;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 166;
            if (Q==0.005) VMHL_Result = 180;
            if (Q==0.010) VMHL_Result = 187;
            if (Q==0.025) VMHL_Result = 198;
            if (Q==0.05)  VMHL_Result = 207;
            if (Q==0.10)  VMHL_Result = 218;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 169;
            if (Q==0.005) VMHL_Result = 184;
            if (Q==0.010) VMHL_Result = 192;
            if (Q==0.025) VMHL_Result = 203;
            if (Q==0.05)  VMHL_Result = 212;
            if (Q==0.10)  VMHL_Result = 224;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 173;
            if (Q==0.005) VMHL_Result = 188;
            if (Q==0.010) VMHL_Result = 196;
            if (Q==0.025) VMHL_Result = 207;
            if (Q==0.05)  VMHL_Result = 218;
            if (Q==0.10)  VMHL_Result = 229;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 177;
            if (Q==0.005) VMHL_Result = 192;
            if (Q==0.010) VMHL_Result = 200;
            if (Q==0.025) VMHL_Result = 212;
            if (Q==0.05)  VMHL_Result = 223;
            if (Q==0.10)  VMHL_Result = 235;
        }
    }

    if (m==15)
    {
        if (n==15)
        {
            if (Q==0.001) VMHL_Result = 160;
            if (Q==0.005) VMHL_Result = 171;
            if (Q==0.010) VMHL_Result = 176;
            if (Q==0.025) VMHL_Result = 184;
            if (Q==0.05)  VMHL_Result = 192;
            if (Q==0.10)  VMHL_Result = 200;
        }

        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 163;
            if (Q==0.005) VMHL_Result = 175;
            if (Q==0.010) VMHL_Result = 181;
            if (Q==0.025) VMHL_Result = 190;
            if (Q==0.05)  VMHL_Result = 197;
            if (Q==0.10)  VMHL_Result = 206;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 167;
            if (Q==0.005) VMHL_Result = 180;
            if (Q==0.010) VMHL_Result = 186;
            if (Q==0.025) VMHL_Result = 195;
            if (Q==0.05)  VMHL_Result = 203;
            if (Q==0.10)  VMHL_Result = 212;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 171;
            if (Q==0.005) VMHL_Result = 184;
            if (Q==0.010) VMHL_Result = 190;
            if (Q==0.025) VMHL_Result = 200;
            if (Q==0.05)  VMHL_Result = 208;
            if (Q==0.10)  VMHL_Result = 218;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 175;
            if (Q==0.005) VMHL_Result = 189;
            if (Q==0.010) VMHL_Result = 195;
            if (Q==0.025) VMHL_Result = 205;
            if (Q==0.05)  VMHL_Result = 214;
            if (Q==0.10)  VMHL_Result = 224;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 179;
            if (Q==0.005) VMHL_Result = 193;
            if (Q==0.010) VMHL_Result = 200;
            if (Q==0.025) VMHL_Result = 210;
            if (Q==0.05)  VMHL_Result = 220;
            if (Q==0.10)  VMHL_Result = 230;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 183;
            if (Q==0.005) VMHL_Result = 198;
            if (Q==0.010) VMHL_Result = 205;
            if (Q==0.025) VMHL_Result = 216;
            if (Q==0.05)  VMHL_Result = 225;
            if (Q==0.10)  VMHL_Result = 236;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 187;
            if (Q==0.005) VMHL_Result = 202;
            if (Q==0.010) VMHL_Result = 210;
            if (Q==0.025) VMHL_Result = 221;
            if (Q==0.05)  VMHL_Result = 231;
            if (Q==0.10)  VMHL_Result = 242;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 191;
            if (Q==0.005) VMHL_Result = 207;
            if (Q==0.010) VMHL_Result = 214;
            if (Q==0.025) VMHL_Result = 226;
            if (Q==0.05)  VMHL_Result = 236;
            if (Q==0.10)  VMHL_Result = 248;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 195;
            if (Q==0.005) VMHL_Result = 211;
            if (Q==0.010) VMHL_Result = 219;
            if (Q==0.025) VMHL_Result = 231;
            if (Q==0.05)  VMHL_Result = 242;
            if (Q==0.10)  VMHL_Result = 254;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 199;
            if (Q==0.005) VMHL_Result = 216;
            if (Q==0.010) VMHL_Result = 224;
            if (Q==0.025) VMHL_Result = 237;
            if (Q==0.05)  VMHL_Result = 248;
            if (Q==0.10)  VMHL_Result = 260;
        }
    }

    if (m==16)
    {
        if (n==16)
        {
            if (Q==0.001) VMHL_Result = 184;
            if (Q==0.005) VMHL_Result = 196;
            if (Q==0.010) VMHL_Result = 202;
            if (Q==0.025) VMHL_Result = 211;
            if (Q==0.05)  VMHL_Result = 219;
            if (Q==0.10)  VMHL_Result = 229;
        }

        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 188;
            if (Q==0.005) VMHL_Result = 201;
            if (Q==0.010) VMHL_Result = 207;
            if (Q==0.025) VMHL_Result = 217;
            if (Q==0.05)  VMHL_Result = 225;
            if (Q==0.10)  VMHL_Result = 235;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 192;
            if (Q==0.005) VMHL_Result = 206;
            if (Q==0.010) VMHL_Result = 212;
            if (Q==0.025) VMHL_Result = 222;
            if (Q==0.05)  VMHL_Result = 231;
            if (Q==0.10)  VMHL_Result = 242;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 196;
            if (Q==0.005) VMHL_Result = 210;
            if (Q==0.010) VMHL_Result = 218;
            if (Q==0.025) VMHL_Result = 228;
            if (Q==0.05)  VMHL_Result = 237;
            if (Q==0.10)  VMHL_Result = 248;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 201;
            if (Q==0.005) VMHL_Result = 215;
            if (Q==0.010) VMHL_Result = 223;
            if (Q==0.025) VMHL_Result = 234;
            if (Q==0.05)  VMHL_Result = 243;
            if (Q==0.10)  VMHL_Result = 255;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 205;
            if (Q==0.005) VMHL_Result = 220;
            if (Q==0.010) VMHL_Result = 228;
            if (Q==0.025) VMHL_Result = 239;
            if (Q==0.05)  VMHL_Result = 249;
            if (Q==0.10)  VMHL_Result = 261;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 209;
            if (Q==0.005) VMHL_Result = 225;
            if (Q==0.010) VMHL_Result = 233;
            if (Q==0.025) VMHL_Result = 245;
            if (Q==0.05)  VMHL_Result = 255;
            if (Q==0.10)  VMHL_Result = 267;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 214;
            if (Q==0.005) VMHL_Result = 230;
            if (Q==0.010) VMHL_Result = 238;
            if (Q==0.025) VMHL_Result = 251;
            if (Q==0.05)  VMHL_Result = 261;
            if (Q==0.10)  VMHL_Result = 274;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 218;
            if (Q==0.005) VMHL_Result = 235;
            if (Q==0.010) VMHL_Result = 244;
            if (Q==0.025) VMHL_Result = 256;
            if (Q==0.05)  VMHL_Result = 267;
            if (Q==0.10)  VMHL_Result = 280;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 222;
            if (Q==0.005) VMHL_Result = 240;
            if (Q==0.010) VMHL_Result = 249;
            if (Q==0.025) VMHL_Result = 262;
            if (Q==0.05)  VMHL_Result = 273;
            if (Q==0.10)  VMHL_Result = 287;
        }
    }

    if (m==17)
    {
        if (n==17)
        {
            if (Q==0.001) VMHL_Result = 210;
            if (Q==0.005) VMHL_Result = 223;
            if (Q==0.010) VMHL_Result = 230;
            if (Q==0.025) VMHL_Result = 240;
            if (Q==0.05)  VMHL_Result = 249;
            if (Q==0.10)  VMHL_Result = 259;
        }

        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 214;
            if (Q==0.005) VMHL_Result = 228;
            if (Q==0.010) VMHL_Result = 235;
            if (Q==0.025) VMHL_Result = 246;
            if (Q==0.05)  VMHL_Result = 255;
            if (Q==0.10)  VMHL_Result = 266;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 219;
            if (Q==0.005) VMHL_Result = 234;
            if (Q==0.010) VMHL_Result = 241;
            if (Q==0.025) VMHL_Result = 252;
            if (Q==0.05)  VMHL_Result = 262;
            if (Q==0.10)  VMHL_Result = 273;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 223;
            if (Q==0.005) VMHL_Result = 239;
            if (Q==0.010) VMHL_Result = 246;
            if (Q==0.025) VMHL_Result = 258;
            if (Q==0.05)  VMHL_Result = 268;
            if (Q==0.10)  VMHL_Result = 280;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 228;
            if (Q==0.005) VMHL_Result = 244;
            if (Q==0.010) VMHL_Result = 252;
            if (Q==0.025) VMHL_Result = 264;
            if (Q==0.05)  VMHL_Result = 274;
            if (Q==0.10)  VMHL_Result = 287;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 233;
            if (Q==0.005) VMHL_Result = 249;
            if (Q==0.010) VMHL_Result = 258;
            if (Q==0.025) VMHL_Result = 270;
            if (Q==0.05)  VMHL_Result = 281;
            if (Q==0.10)  VMHL_Result = 294;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 238;
            if (Q==0.005) VMHL_Result = 255;
            if (Q==0.010) VMHL_Result = 263;
            if (Q==0.025) VMHL_Result = 276;
            if (Q==0.05)  VMHL_Result = 287;
            if (Q==0.10)  VMHL_Result = 300;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 242;
            if (Q==0.005) VMHL_Result = 260;
            if (Q==0.010) VMHL_Result = 269;
            if (Q==0.025) VMHL_Result = 282;
            if (Q==0.05)  VMHL_Result = 294;
            if (Q==0.10)  VMHL_Result = 307;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 247;
            if (Q==0.005) VMHL_Result = 265;
            if (Q==0.010) VMHL_Result = 275;
            if (Q==0.025) VMHL_Result = 288;
            if (Q==0.05)  VMHL_Result = 300;
            if (Q==0.10)  VMHL_Result = 314;
        }

       }

    if (m==18)
    {
        if (n==18)
        {
            if (Q==0.001) VMHL_Result = 237;
            if (Q==0.005) VMHL_Result = 252;
            if (Q==0.010) VMHL_Result = 259;
            if (Q==0.025) VMHL_Result = 270;
            if (Q==0.05)  VMHL_Result = 280;
            if (Q==0.10)  VMHL_Result = 291;
        }

        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 242;
            if (Q==0.005) VMHL_Result = 258;
            if (Q==0.010) VMHL_Result = 265;
            if (Q==0.025) VMHL_Result = 277;
            if (Q==0.05)  VMHL_Result = 287;
            if (Q==0.10)  VMHL_Result = 299;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 247;
            if (Q==0.005) VMHL_Result = 263;
            if (Q==0.010) VMHL_Result = 271;
            if (Q==0.025) VMHL_Result = 283;
            if (Q==0.05)  VMHL_Result = 294;
            if (Q==0.10)  VMHL_Result = 306;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 252;
            if (Q==0.005) VMHL_Result = 269;
            if (Q==0.010) VMHL_Result = 277;
            if (Q==0.025) VMHL_Result = 290;
            if (Q==0.05)  VMHL_Result = 301;
            if (Q==0.10)  VMHL_Result = 313;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 257;
            if (Q==0.005) VMHL_Result = 275;
            if (Q==0.010) VMHL_Result = 283;
            if (Q==0.025) VMHL_Result = 296;
            if (Q==0.05)  VMHL_Result = 307;
            if (Q==0.10)  VMHL_Result = 321;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 262;
            if (Q==0.005) VMHL_Result = 280;
            if (Q==0.010) VMHL_Result = 289;
            if (Q==0.025) VMHL_Result = 303;
            if (Q==0.05)  VMHL_Result = 314;
            if (Q==0.10)  VMHL_Result = 328;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 267;
            if (Q==0.005) VMHL_Result = 286;
            if (Q==0.010) VMHL_Result = 295;
            if (Q==0.025) VMHL_Result = 309;
            if (Q==0.05)  VMHL_Result = 321;
            if (Q==0.10)  VMHL_Result = 335;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 273;
            if (Q==0.005) VMHL_Result = 292;
            if (Q==0.010) VMHL_Result = 301;
            if (Q==0.025) VMHL_Result = 316;
            if (Q==0.05)  VMHL_Result = 328;
            if (Q==0.10)  VMHL_Result = 343;
        }
    }


    if (m==19)
    {
        if (n==19)
        {
            if (Q==0.001) VMHL_Result = 267;
            if (Q==0.005) VMHL_Result = 283;
            if (Q==0.010) VMHL_Result = 291;
            if (Q==0.025) VMHL_Result = 303;
            if (Q==0.05)  VMHL_Result = 313;
            if (Q==0.10)  VMHL_Result = 325;
        }

        if (n==20)
        {
            if (Q==0.001) VMHL_Result = 272;
            if (Q==0.005) VMHL_Result = 289;
            if (Q==0.010) VMHL_Result = 297;
            if (Q==0.025) VMHL_Result = 309;
            if (Q==0.05)  VMHL_Result = 320;
            if (Q==0.10)  VMHL_Result = 333;
        }

        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 277;
            if (Q==0.005) VMHL_Result = 295;
            if (Q==0.010) VMHL_Result = 303;
            if (Q==0.025) VMHL_Result = 316;
            if (Q==0.05)  VMHL_Result = 328;
            if (Q==0.10)  VMHL_Result = 341;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 283;
            if (Q==0.005) VMHL_Result = 301;
            if (Q==0.010) VMHL_Result = 310;
            if (Q==0.025) VMHL_Result = 323;
            if (Q==0.05)  VMHL_Result = 335;
            if (Q==0.10)  VMHL_Result = 349;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 288;
            if (Q==0.005) VMHL_Result = 307;
            if (Q==0.010) VMHL_Result = 316;
            if (Q==0.025) VMHL_Result = 330;
            if (Q==0.05)  VMHL_Result = 342;
            if (Q==0.10)  VMHL_Result = 357;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 294;
            if (Q==0.005) VMHL_Result = 313;
            if (Q==0.010) VMHL_Result = 323;
            if (Q==0.025) VMHL_Result = 337;
            if (Q==0.05)  VMHL_Result = 350;
            if (Q==0.10)  VMHL_Result = 364;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 299;
            if (Q==0.005) VMHL_Result = 319;
            if (Q==0.010) VMHL_Result = 329;
            if (Q==0.025) VMHL_Result = 344;
            if (Q==0.05)  VMHL_Result = 357;
            if (Q==0.10)  VMHL_Result = 372;
        }

    }


        if (m==20)
        {
            if (n==20)
            {
                if (Q==0.001) VMHL_Result = 298;
                if (Q==0.005) VMHL_Result = 315;
                if (Q==0.010) VMHL_Result = 324;
                if (Q==0.025) VMHL_Result = 337;
                if (Q==0.05)  VMHL_Result = 348;
                if (Q==0.10)  VMHL_Result = 361;
            }

            if (n==21)
            {
                if (Q==0.001) VMHL_Result = 304;
                if (Q==0.005) VMHL_Result = 322;
                if (Q==0.010) VMHL_Result = 331;
                if (Q==0.025) VMHL_Result = 344;
                if (Q==0.05)  VMHL_Result = 356;
                if (Q==0.10)  VMHL_Result = 370;
            }

            if (n==22)
            {
                if (Q==0.001) VMHL_Result = 309;
                if (Q==0.005) VMHL_Result = 328;
                if (Q==0.010) VMHL_Result = 337;
                if (Q==0.025) VMHL_Result = 351;
                if (Q==0.05)  VMHL_Result = 364;
                if (Q==0.10)  VMHL_Result = 378;
            }

            if (n==23)
            {
                if (Q==0.001) VMHL_Result = 315;
                if (Q==0.005) VMHL_Result = 335;
                if (Q==0.010) VMHL_Result = 344;
                if (Q==0.025) VMHL_Result = 359;
                if (Q==0.05)  VMHL_Result = 371;
                if (Q==0.10)  VMHL_Result = 386;
            }

            if (n==24)
            {
                if (Q==0.001) VMHL_Result = 321;
                if (Q==0.005) VMHL_Result = 341;
                if (Q==0.010) VMHL_Result = 351;
                if (Q==0.025) VMHL_Result = 366;
                if (Q==0.05)  VMHL_Result = 379;
                if (Q==0.10)  VMHL_Result = 394;
            }

            if (n==25)
            {
                if (Q==0.001) VMHL_Result = 327;
                if (Q==0.005) VMHL_Result = 348;
                if (Q==0.010) VMHL_Result = 358;
                if (Q==0.025) VMHL_Result = 373;
                if (Q==0.05)  VMHL_Result = 387;
                if (Q==0.10)  VMHL_Result = 403;
            }
        }

    if (m==21)
    {
        if (n==21)
        {
            if (Q==0.001) VMHL_Result = 331;
            if (Q==0.005) VMHL_Result = 349;
            if (Q==0.010) VMHL_Result = 359;
            if (Q==0.025) VMHL_Result = 373;
            if (Q==0.05)  VMHL_Result = 385;
            if (Q==0.10)  VMHL_Result = 399;
        }

        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 337;
            if (Q==0.005) VMHL_Result = 356;
            if (Q==0.010) VMHL_Result = 366;
            if (Q==0.025) VMHL_Result = 381;
            if (Q==0.05)  VMHL_Result = 393;
            if (Q==0.10)  VMHL_Result = 408;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 343;
            if (Q==0.005) VMHL_Result = 363;
            if (Q==0.010) VMHL_Result = 373;
            if (Q==0.025) VMHL_Result = 388;
            if (Q==0.05)  VMHL_Result = 401;
            if (Q==0.10)  VMHL_Result = 417;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 349;
            if (Q==0.005) VMHL_Result = 370;
            if (Q==0.010) VMHL_Result = 381;
            if (Q==0.025) VMHL_Result = 396;
            if (Q==0.05)  VMHL_Result = 410;
            if (Q==0.10)  VMHL_Result = 425;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 356;
            if (Q==0.005) VMHL_Result = 377;
            if (Q==0.010) VMHL_Result = 388;
            if (Q==0.025) VMHL_Result = 404;
            if (Q==0.05)  VMHL_Result = 418;
            if (Q==0.10)  VMHL_Result = 434;
        }
    }

    if (m==22)
    {
        if (n==22)
        {
            if (Q==0.001) VMHL_Result = 365;
            if (Q==0.005) VMHL_Result = 386;
            if (Q==0.010) VMHL_Result = 396;
            if (Q==0.025) VMHL_Result = 411;
            if (Q==0.05)  VMHL_Result = 424;
            if (Q==0.10)  VMHL_Result = 439;
        }

        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 372;
            if (Q==0.005) VMHL_Result = 393;
            if (Q==0.010) VMHL_Result = 403;
            if (Q==0.025) VMHL_Result = 419;
            if (Q==0.05)  VMHL_Result = 432;
            if (Q==0.10)  VMHL_Result = 448;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 379;
            if (Q==0.005) VMHL_Result = 400;
            if (Q==0.010) VMHL_Result = 411;
            if (Q==0.025) VMHL_Result = 427;
            if (Q==0.05)  VMHL_Result = 441;
            if (Q==0.10)  VMHL_Result = 457;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 385;
            if (Q==0.005) VMHL_Result = 408;
            if (Q==0.010) VMHL_Result = 419;
            if (Q==0.025) VMHL_Result = 435;
            if (Q==0.05)  VMHL_Result = 450;
            if (Q==0.10)  VMHL_Result = 467;
        }
    }

    if (m==23)
    {
        if (n==23)
        {
            if (Q==0.001) VMHL_Result = 402;
            if (Q==0.005) VMHL_Result = 424;
            if (Q==0.010) VMHL_Result = 434;
            if (Q==0.025) VMHL_Result = 451;
            if (Q==0.05)  VMHL_Result = 465;
            if (Q==0.10)  VMHL_Result = 481;
        }

        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 402;
            if (Q==0.005) VMHL_Result = 431;
            if (Q==0.010) VMHL_Result = 443;
            if (Q==0.025) VMHL_Result = 459;
            if (Q==0.05)  VMHL_Result = 474;
            if (Q==0.10)  VMHL_Result = 491;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 416;
            if (Q==0.005) VMHL_Result = 439;
            if (Q==0.010) VMHL_Result = 451;
            if (Q==0.025) VMHL_Result = 468;
            if (Q==0.05)  VMHL_Result = 483;
            if (Q==0.10)  VMHL_Result = 500;
        }
    }

    if (m==24)
    {
        if (n==24)
        {
            if (Q==0.001) VMHL_Result = 440;
            if (Q==0.005) VMHL_Result = 464;
            if (Q==0.010) VMHL_Result = 475;
            if (Q==0.025) VMHL_Result = 492;
            if (Q==0.05)  VMHL_Result = 507;
            if (Q==0.10)  VMHL_Result = 525;
        }

        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 448;
            if (Q==0.005) VMHL_Result = 472;
            if (Q==0.010) VMHL_Result = 484;
            if (Q==0.025) VMHL_Result = 501;
            if (Q==0.05)  VMHL_Result = 517;
            if (Q==0.10)  VMHL_Result = 535;
        }
    }

    if (m==25)
    {
        if (n==25)
        {
            if (Q==0.001) VMHL_Result = 480;
            if (Q==0.005) VMHL_Result = 505;
            if (Q==0.010) VMHL_Result = 517;
            if (Q==0.025) VMHL_Result = 536;
            if (Q==0.05)  VMHL_Result = 552;
            if (Q==0.10)  VMHL_Result = 570;
        }
    }

    return VMHL_Result;
}
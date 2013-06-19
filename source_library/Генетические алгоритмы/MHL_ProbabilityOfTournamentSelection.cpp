double MHL_ProbabilityOfTournamentSelection(double *Fitness, double *VMHL_ResultVector_Probability, int T, int VMHL_N)
{
/*
Функция вычисляет вероятности выбора индивидов из популяции с помощью турнирной селекции.
Входные параметры:
 Fitness - указатель на вектор значений целевой функции (не пригодности) индивидов;
 VMHL_ResultVector_Probability - указатель на вектор, в который будет проводиться запись;
 T - размер турнира;
 VMHL_N -  размер массивов.
Возвращаемое значение:
 Сумму вектора вероятностей Probability.
Примечание:
 Данная функция не нужна для работы турнирной селекции через функцию MHL_TournamentSelection
 в генетическом алгоритме. Функция предназначена для научных изысканий по исследованию работы
 различных видов селекций.
*/
    int i,j,minTn1,j0;
    double n1,n0,s,KC1,KC2,VMHL_Result;

    //пробегаем по всем индивидам
    for (i=0;i<VMHL_N;i++)
    {
        n0=0;//количество индивидов, которые выигрывают данный индивид
        n1=0;//количество индивидов, которые равны данному индивиду
        //Далее посчитаем их
        for (j=0;j<VMHL_N;j++) if (Fitness[j]>Fitness[i]) n0++;
        for (j=0;j<VMHL_N;j++) if (Fitness[j]==Fitness[i]) n1++;


        j0=TMHL_Max(1,int(T-(VMHL_N-n1-n0)));
        minTn1=TMHL_Min(T,int(n1));
        s=0;
        //пробегаем по всем допустимым сочетаниям
        //точная формула в справке
        for (j=j0-1;j<minTn1;j++)
        {
                KC1=TMHL_KCombinations(j+1,int(n1));// число возможных сочетаний
                KC2=TMHL_KCombinations(T-(j+1),int(VMHL_N-n1-n0));// число возможных сочетаний
                s+=KC1*KC2;
        }

        VMHL_ResultVector_Probability[i]=s/(n1*TMHL_KCombinations(T,VMHL_N));
    }


    VMHL_Result=TMHL_SumVector(VMHL_ResultVector_Probability,VMHL_N);
    return VMHL_Result;
}
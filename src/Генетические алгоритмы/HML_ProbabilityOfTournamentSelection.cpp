double HML_ProbabilityOfTournamentSelection(double *Fitness, double *VHML_ResultVector_Probability, int T, int VHML_N)
{
/*
Функция вычисляет вероятности выбора индивидов из популяции с помощью турнирной селекции.
Входные параметры:
 Fitness - указатель на вектор значений целевой функции (не пригодности) индивидов;
 VHML_ResultVector_Probability - указатель на вектор, в который будет проводиться запись;
 T - размер турнира;
 VHML_N -  размер массивов.
Возвращаемое значение:
 Сумму вектора вероятностей Probability.
Примечание:
 Данная функция не нужна для работы турнирной селекции через функцию HML_TournamentSelection
 в генетическом алгоритме. Функция предназначена для научных изысканий по исследованию работы
 различных видов селекций.
*/
    int i,j,minTn1,j0;
    double n1,n0,s,KC1,KC2,VHML_Result;

    //пробегаем по всем индивидам
    for (i=0;i<VHML_N;i++)
    {
        n0=0;//количество индивидов, которые выигрывают данный индивид
        n1=0;//количество индивидов, которые равны данному индивиду
        //Далее посчитаем их
        for (j=0;j<VHML_N;j++) if (Fitness[j]>Fitness[i]) n0++;
        for (j=0;j<VHML_N;j++) if (Fitness[j]==Fitness[i]) n1++;


        j0=HML_Max(1,int(T-(VHML_N-n1-n0)));
        minTn1=HML_Min(T,int(n1));
        s=0;
        //пробегаем по всем допустимым сочетаниям
        //точная формула в справке
        for (j=j0-1;j<minTn1;j++)
        {
                KC1=HML_KCombinations(j+1,int(n1));// число возможных сочетаний
                KC2=HML_KCombinations(T-(j+1),int(VHML_N-n1-n0));// число возможных сочетаний
                s+=KC1*KC2;
        }

        VHML_ResultVector_Probability[i]=s/(n1*HML_KCombinations(T,VHML_N));
    }


    VHML_Result=HML_SumVector(VHML_ResultVector_Probability,VHML_N);
    return VHML_Result;
}
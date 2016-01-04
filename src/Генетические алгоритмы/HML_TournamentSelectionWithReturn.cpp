int HML_TournamentSelectionWithReturn(double *Fitness, int SizeTournament, int VHML_N)
{
/*
Турнирная селекция с возвращением. Оператор генетического алгоритма. Работает с массивом пригодностей индивидов.
Входные параметры:
 Fitness - массив пригодностей индивидов;
 VHML_N - размер массива VectorProbability;
 SizeTournament - размер турнира.
Возвращаемое значение:
 Номер выбранного индивида популяции.
Примечание:
 Не является стандартной реализацией турнирной селекции, так как в классичсекой турнирной селекции
в один турнир один и тот же индивид может попасть только один раз.
*/
if (SizeTournament<2) SizeTournament=2;
if (SizeTournament>VHML_N) SizeTournament=VHML_N;
int VHML_Result;//победитель (номер) для турнирной селекции
int r; //случайное число для определения победителя

//турнирная  селекция с возвращением.
VHML_Result=HML_RandomUniformInt(0,VHML_N);//первый участник

for (int i=1;i<SizeTournament;i++)
 {//выбор еще одного участника турнира
 r=HML_RandomUniformInt(0,VHML_N);
 if (Fitness[r]>Fitness[VHML_Result]) VHML_Result=r;
 }//выбор еще одного участника турнира

return VHML_Result;
}
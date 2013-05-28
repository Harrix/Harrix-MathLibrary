int MHL_TournamentSelectionWithReturn(double *Fitness, int SizeTournament, int VMHL_N)
{
/*
Турнирная селекция с возвращением. Оператор генетического алгоритма. Работает с массивом пригодностей индивидов.
Входные параметры:
 Fitness - массив пригодностей индивидов;
 VMHL_N - размер массива VectorProbability;
 SizeTournament - размер турнира.
Возвращаемое значение:
 Номер выбранного индивида популяции.
Примечание:
 Не является стандартной реализацией турнирной селекции, так как в классичсекой турнирной селекции
в один туринир один и тот же индивид может попасть только один раз.
*/
if (SizeTournament<2) SizeTournament=2;
if (SizeTournament>VMHL_N) SizeTournament=VMHL_N;
int VMHL_Result;//победитель (номер) для турнирной селекции
int r; //случайное число для определения победителя

//турнирная  селекция с возвращением.
VMHL_Result=MHL_RandomUniformInt(0,VMHL_N);//первый участник

for (int i=1;i<SizeTournament;i++)
 {//выбор еще одного участника турнира
 r=MHL_RandomUniformInt(0,VMHL_N);
 if (Fitness[r]>Fitness[VMHL_Result]) VMHL_Result=r;
 }//выбор еще одного участника турнира

return VMHL_Result;
}
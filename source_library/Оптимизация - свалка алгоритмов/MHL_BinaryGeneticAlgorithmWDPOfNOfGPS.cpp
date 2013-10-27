int MHL_BinaryGeneticAlgorithmWDPOfNOfGPS(double *Parameters, double (*FitnessFunction)(int*,int), int *VMHL_ResultVector, double *VMHL_Result)
{
/*
Генетический алгоритм на бинарных строках с изменяющимся соотношением числа поколений и размера популяции.
Отличается от стандартного генетического алгоритма, тем, что размер популяции и число поколений рассчитывается
из числа вычислений целевой функции не как одинаковые величины (извлечение квадратного корня), а через некоторое соотношение.
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина бинарной хромосомы (определяется задачей оптимизации, что мы решаем);
  [1] - число вычислений целевой функции (CountOfFitness);
  [2] - тип селекции (TypeOfSel):
        0 - ProportionalSelection (Пропорциональная селекция);
        1 - RankSelection (Ранговая селекция);
        2 - TournamentSelection (Турнирная селекция).
  [3] - тип скрещивания (TypeOfCros):
        0 - SinglepointCrossover (Одноточечное скрещивание);
        1 - TwopointCrossover (Двуточечное скрещивание);
        2 - UniformCrossover (Равномерное скрещивание).
  [4] - тип мутации (TypeOfMutation):
        0 - Weak (Слабая мутация);
        1 - Averagen (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида).
  [6] - "доля" (Proportion) числа поколений от общего числа вычислений целевой функции.
        Определяется как возведение числа вычислений целевой функции в степень Proportion.
        Может принимать значения в интервале [0;1].
        Число поколений = int(CountOfFitness^Proportion).
        Размер популяции = int(CountOfFitness/Число поколений).
        При Proportion=0.5 получим обычный стандартный генетический алгоритм.
        Чем меньше Proportion, тем меньше число поколений будет.
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VMHL_ResultVector - найденное решение (бинарный вектор);
 VMHL_Result - значение целевой функции в точке, определенной вектором VMHL_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VMHL_ResultVector и в VMHL_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=50;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
 Parameters[6]=0.5;
*/
//Считываем из Parameters параметры алгоритма
int ChromosomeLength=Parameters[0];//Длина хромосомы
int CountOfFitness=Parameters[1];//Число вычислений целевой функции
int TypeOfSel=Parameters[2];//Тип селекции
int TypeOfCros=Parameters[3];//Тип скрещивания
int TypeOfMutation=Parameters[4];//Тип мутации
int TypeOfForm=Parameters[5];//Тип формирования нового поколения
double Proportion=Parameters[6];//"доля" числа поколений от общего числа вычислений целевой функции

//Проверим данные
if (ChromosomeLength<1)	return 0;//Слишком маленькая длина хромосомы
if (CountOfFitness<1)	return 0;//Слишком маленькое число вычислений целевой функции
if (!((TypeOfSel==0)||(TypeOfSel==1)||(TypeOfSel==2))) return 0;//Тип селекции указан не верно
if (!((TypeOfCros==0)||(TypeOfCros==1)||(TypeOfCros==2))) return 0;//Тип скрещивания указан не верно
if (!((TypeOfMutation==0)||(TypeOfMutation==1)||(TypeOfMutation==2))) return 0;//Тип мутации указан не верно
if (!((TypeOfForm==0)||(TypeOfForm==1))) return 0;//Тип формирования нового поколения указан не верно
if ((Proportion<0)||(Proportion>1)) return 0;//"доля" числа поколений может быть в интервале [0;1].

//Теперь определим остальные параметры алгоритма, исходя из полученной информации
//Размер популяции и число поколений должны быть приблизительно равны (насколько это возможно)
int NumberOfGenerations=int(pow(double(CountOfFitness),Proportion));//Число поколений
int PopulationSize=int(CountOfFitness/NumberOfGenerations);//Размер популяции
int SizeOfTournament=2;//В стандартном генетическом алгоритме на бинарных строках размер турнира равен 2

//Переменные
int I,i,j;//Счетчики
int NumberOfMaximumFitness;//Номер лучшего индивида в текущей популяции
double MaximumFitness;//Значение целевой функции лучшего индивида в текущей популяции
double BestFitness;//Значение целевой функции лучшего индивида за всё время работы алгоритма
int NumberOfParent1;//Номер первого выбранного родителя
int NumberOfParent2;//Номер второго выбранного родителя
double ProbabilityOfMutation;//Вероятность мутации

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Популяция индивидов
int **Population;
Population=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) Population[i]=new int[ChromosomeLength];
//Популяция потомков
int **ChildrenPopulation;
ChildrenPopulation=new int*[PopulationSize];
for (i=0;i<PopulationSize;i++) ChildrenPopulation[i]=new int[ChromosomeLength];
//Массив значений целевой функции индивидов
double *Fitness;
Fitness=new double[PopulationSize];
//Массив значений целевой функции потомков
double *ChildrenFitness;
ChildrenFitness=new double[PopulationSize];
//Массив для хранения произвольного индивида
int *TempIndividual;
TempIndividual=new int[ChromosomeLength];
//Массив для хранения лучшего индивида за всё время работы алгоритма
int *BestIndividual;
BestIndividual=new int[ChromosomeLength];
//Для пропорциональной и ранговой селекции нужен массив вероятностей выбора индивидов
double *VectorOfProbability;
VectorOfProbability=new double[PopulationSize];
//Для ранговой селекции нужен массив рангов индивидов
double *Rank;
Rank=new double[PopulationSize];
//Для турнирной селекции нужен служебный массив, содержащий информация о том, в турнире или нет индивид;
int *Taken;
Taken=new int[PopulationSize];
//Массив для хранения первого родителя
int *Parent1;
Parent1=new int[ChromosomeLength];
//Массив для хранения второго родителя
int *Parent2;
Parent2=new int[ChromosomeLength];
//Массив для хранения потомка от скрещивания двух родителей
int *Child;
Child=new int[ChromosomeLength];

//Инициализация начальной популяции
TMHL_RandomBinaryMatrix(Population,PopulationSize,ChromosomeLength);

//Вычислим значение целевой функции для каждого индивида
for (i=0;i<PopulationSize;i++)
 {
 //Копируем индивида во временного индивида, так как целевая функция работает с вектором, а не матрицей
 TMHL_MatrixToRow(Population,TempIndividual,i,ChromosomeLength);
 try
  {
  Fitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
  }
 catch(...)
  {
  return 0;//Генетический алгоритм не смог посчитать значение целевая функции индивида
  }
 }

//Определим наилучшего индивида и запомним его
NumberOfMaximumFitness=TMHL_NumberOfMaximumOfVector(Fitness,PopulationSize);
MaximumFitness=TMHL_MaximumOfVector(Fitness,PopulationSize);
TMHL_MatrixToRow(Population,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
BestFitness=MaximumFitness;//Запоминаем его значение целевой функции

for (I=1;I<NumberOfGenerations;I++)
 {//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

 //Подготовка массивов для оператора селекции
 if (TypeOfSel==1)
  {
  //Для ранговой селекции нужен массив рангов индивидов
  MHL_MakeVectorOfRankForRankSelection(Fitness,Rank,PopulationSize);
  //Для ранговой селекции нужен массив вероятностей выбора индивидов из рангов
  MHL_MakeVectorOfProbabilityForRanklSelection(Rank,VectorOfProbability,PopulationSize);
  }
 if (TypeOfSel==0)//Для пропорциональной нужен массив вероятностей выбора индивидов
  MHL_MakeVectorOfProbabilityForProportionalSelectionV2(Fitness,VectorOfProbability,PopulationSize);

 for (j=0;j<PopulationSize;j++)
  {//Формирование популяции потомков
  if (TypeOfSel==0)//Пропорциональная селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=MHL_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   NumberOfParent2=MHL_ProportionalSelectionV2(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==1)//Ранговая селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=MHL_RankSelection(VectorOfProbability,PopulationSize);
   NumberOfParent2=MHL_RankSelection(VectorOfProbability,PopulationSize);
   }
  if (TypeOfSel==2)//Турнирная селекция
   {
   //Выбираем двух родителей (точнее их номера)
   NumberOfParent1=MHL_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
   NumberOfParent2=MHL_TournamentSelection(Fitness,SizeOfTournament,Taken,PopulationSize);
   }

  //Копируем родителей из популяции
  TMHL_MatrixToRow(Population,Parent1,NumberOfParent1,ChromosomeLength);//Первого родителя
  TMHL_MatrixToRow(Population,Parent2,NumberOfParent2,ChromosomeLength);//Второго родителя

  //Теперь путем скрещивания получаем потомка
  if (TypeOfCros==0)//Одноточечное скрещивание
   TMHL_SinglepointCrossover(Parent1,Parent2,Child,ChromosomeLength);
  if (TypeOfCros==1)//Двухточечное скрещивание
   TMHL_TwopointCrossover(Parent1,Parent2,Child,ChromosomeLength);
  if (TypeOfCros==2)//Равномерное скрещивание
   TMHL_UniformCrossover(Parent1,Parent2,Child,ChromosomeLength);

  //Переместим потомка в массив потомков
  TMHL_RowToMatrix(ChildrenPopulation,Child,j,ChromosomeLength);
  }//Формирование популяции потомков

 //Мутируем получившуюся популяцию потомков
 //Но вначале определим вероятность мутации
 if (TypeOfMutation==0)//Слабая
  ProbabilityOfMutation=1./(3.*double(ChromosomeLength));
 if (TypeOfMutation==1)//Средняя
  ProbabilityOfMutation=1./double(ChromosomeLength);
 if (TypeOfMutation==2)//Сильняя
  ProbabilityOfMutation=TMHL_Min(3./double(ChromosomeLength),1.);
 TMHL_MutationBinaryMatrix(ChildrenPopulation,ProbabilityOfMutation,PopulationSize,ChromosomeLength);//Мутируем

 //Вычислим значение целевой функции для каждого потомка
 for (i=0;i<PopulationSize;i++)
  {
  //Копируем потомка во временного индивида, так как целевой функция работает с вектором, а не матрицей
  TMHL_MatrixToRow(ChildrenPopulation,TempIndividual,i,ChromosomeLength);
  try
   {
   ChildrenFitness[i]=FitnessFunction(TempIndividual,ChromosomeLength);
   }
  catch(...)
   {
   return 0;//Генетический алгоритм не смог посчитать значение целевой функции потомка
   }
  }

 //Определим наилучшего потомка и запомним его
 MaximumFitness=TMHL_MaximumOfVector(ChildrenFitness,PopulationSize);

 //Является ли лучшее решение на данном поколении лучше лучшего решения за всё время работы алгоритма
 if (MaximumFitness>BestFitness)
  {
  //Если всё-таки лучше
  NumberOfMaximumFitness=TMHL_NumberOfMaximumOfVector(ChildrenFitness,PopulationSize);
  TMHL_MatrixToRow(ChildrenPopulation,BestIndividual,NumberOfMaximumFitness,ChromosomeLength);//Запоминаем индивида
  BestFitness=MaximumFitness;//Запоминаем его значение целевой функции
  }

 //Теперь сформируем новое поколение
 if (TypeOfForm==0)//Только потомки
  {
  TMHL_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  TMHL_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  }
 if (TypeOfForm==1)//Только потомки и копия лучшего индивида
  {
  TMHL_MatrixToMatrix(ChildrenPopulation,Population,PopulationSize,ChromosomeLength);
  TMHL_RowToMatrix(Population,BestIndividual,0,ChromosomeLength);
  TMHL_VectorToVector(ChildrenFitness,Fitness,PopulationSize);
  Fitness[0]=BestFitness;
  }

 }//////////////////// ГЛАВНЫЙ ЦИКЛ ///////////////////////

//Генетический алгоритм закончил свою работу
//Выдадим найденное лучшее решение за время запуска алгоритма и его значение целевой функции
TMHL_VectorToVector(BestIndividual,VMHL_ResultVector,ChromosomeLength);
*VMHL_Result=BestFitness;

//Удалим все дополнительные массивы
for (i=0;i<PopulationSize;i++) delete [] Population[i];
 delete [] Population;
for (i=0;i<PopulationSize;i++) delete [] ChildrenPopulation[i];
 delete [] ChildrenPopulation;
delete [] Fitness;
delete [] ChildrenFitness;
delete [] TempIndividual;
delete [] BestIndividual;
delete [] VectorOfProbability;
delete [] Rank;
delete [] Taken;
delete [] Parent1;
delete [] Parent2;
delete [] Child;

return 1;//Всё успешно
}
int MHL_RealGeneticAlgorithmWDPOfNOfGPS(double *Parameters, int *NumberOfParts, double *Left, double *Right, double (*FitnessFunction)(double*,int), double *VMHL_ResultVector, double *VMHL_Result)
{
/*
Генетический алгоритм для решения задач на вещественных строках с изменяющимся соотношением числа поколений и размера популяции.
Отличается от стандартного генетического алгоритма, тем, что размер популяции и число поколений рассчитывается
из числа вычислений целевой функции не как одинаковые величины (извлечение квадратного корня), а через некоторое соотношение.
Алгоритм оптимизации. Ищет максимум целевой функции FitnessFunction.
Тип алгоритма: исследовательский алгоритм оптимизации.
Входные параметры:
 Parameters - Вектор параметров генетического алгоритма. Каждый элемент обозначает свой параметр:
  [0] - длина вещественной хромосомы (определяется задачей оптимизации, что мы решаем);
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
        1 - Average (Средняя мутация);
        2 - Strong (Сильная мутация).
  [5] - тип формирования нового поколения (TypeOfForm):
        0 - OnlyOffspringGenerationForming (Только потомки);
        1 - OnlyOffspringWithBestGenerationForming (Только потомки и копия лучшего индивида)
  [6] - тип преобразования задачи вещественной оптимизации в задачу бинарной оптимизации (TypeOfConverting);
        0 - IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации);
        1 - GrayСodeConverting (Стандартный рефлексивный Грей-код).
  [7] - "доля" (Proportion) числа поколений от общего числа вычислений целевой функции.
        Определяется как возведение числа вычислений целевой функции в степень Proportion.
        Может принимать значения в интервале [0;1].
        Число поколений = int(CountOfFitness^Proportion).
        Размер популяции = int(CountOfFitness/Число поколений).
        При Proportion=0.5 получим обычный стандартный генетический алгоритм.
        Чем меньше Proportion, тем меньше число поколений будет.
 NumberOfParts - указатель на массив: на сколько частей делить каждую вещественную координату при дискретизации (размерность Parameters[0]);
  Желательно брать по формуле NumberOfParts[i]=(2^k)-1, где k - натуральное число, например, 12.
 Left - массив левых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 Right - массив правых границ изменения каждой вещественной координаты (размерность Parameters[0]);
 FitnessFunction - указатель на целевую функцию (если решается задача условной оптимизации, то учет ограничений должен быть включен в эту функцию);
 VMHL_ResultVector - найденное решение (вещественный вектор);
 VMHL_Result - значение целевой функции в точке, определенной вектором VMHL_ResultVector.
Возвращаемое значение:
 1 - завершил работу без ошибок. Всё хорошо.
 0 - возникли при работе ошибки. Скорее всего в этом случае в VMHL_ResultVector и в VMHL_Result не содержится решение задачи.
Пример значений рабочего вектора Parameters:
 Parameters[0]=2;
 Parameters[1]=100*100;
 Parameters[2]=2;
 Parameters[3]=2;
 Parameters[4]=1;
 Parameters[5]=1;
 Parameters[6]=0;
 Parameters[7]=0.5;
*/
//Переменные
int i;//Счетчик
int ChromosomeLength;//Длина бинарной строки
int VMHL_Success;//Успешен ли будет запуск cГА на бинарных строках

//Считываем из Parameters необходимые параметры алгоритма
int RealLength=Parameters[0];//Размерность вещественного вектора
int TypOfConverting=Parameters[6];//Тип преобразования задачи в бинарную задачу оптимизацию

//Проверим данные
for (i=0;i<RealLength;i++) if (Left[i]>Right[i]) return 0;//Левая граница не может быть больше правой
for (i=0;i<RealLength;i++) if (NumberOfParts[i]<1) return 0;//На слишком мало частей предложено делить каждую координату
if (!((TypOfConverting==0)||(TypOfConverting==1))) return 0;//Тип преобразования указан не верно

//Для выполнения алгоритма требуются некоторые дополнительные массивы. Создадим их.
//Массив значений, сколько бит приходится в бинарной хромосоме на кодирование
//каждой вещественной координаты
int *Lengthi;
Lengthi=new int[RealLength];
//Параметры стандартного генетического алгоритма на бинарных строках
double *ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS;
//Указатель на массив, в который записываются решения при вычислении целевой функции
double *RealVector;
RealVector=new double[RealLength];

//Процесс преобразования задачи вещественной оптимизации в задачу бинарной оптимизации
//Определим длину бинарной хромосомы. При этом число точек для кодирования на одну больше, чем интервалов,
//на которые мы хотим разбить каждую вещественную координату.
for (int i=0;i<RealLength;i++)
 Lengthi[i]=MHL_HowManyPowersOfTwo(NumberOfParts[i]+1);

ChromosomeLength=TMHL_SumVector(Lengthi,RealLength);//Просуммируем элементы вектора

//Бинарное решение бинарной задачи оптимизации
int *BinaryDecision;
BinaryDecision=new int[ChromosomeLength];

//Создадим еще один массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную
int *TempBinaryVector;
TempBinaryVector=new int[ChromosomeLength];//GrayСodeConverting (Стандартный рефлексивный Грей-код)

//Определим параметры стандартного генетического алгоритма на бинарных строках
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS=new double[7];
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[0]=ChromosomeLength;//Длина хромосомы
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[1]=Parameters[1];//Число вычислений целевой функции
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[2]=Parameters[2];//Тип селекции
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[3]=Parameters[3];//Тип скрещивания
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[4]=Parameters[4];//Тип мутации
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[5]=Parameters[5];//Тип формирования нового поколения
ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS[6]=Parameters[7];//"доля" числа поколений

//сГА на бинарных строках работает с функцией типа double (*)(int*,int)
//то есть в качестве входных параметров только решение и его размерность
//но для вычисления значения целевой функции еще требуются дополнительные переменные
//целевая функция для вещественного решения и так далее.
//Делаем их доступными, используя служебные дополнительные указатели библиотеки
VMHL_TempFunction=FitnessFunction;//указатель на целевая функция для вещественного решения
VMHL_TempInt1=Lengthi;//указатель на массив, сколько бит приходится в бинарной хромосоме на кодирование
VMHL_TempDouble1=Left;//указатель на массив левых границ изменения вещественной переменной
VMHL_TempDouble2=Right;//указатель на массив правых границ изменения вещественной переменной
VMHL_TempDouble3=RealVector;//указатель на массив, в котором можно сохранить вещественный индивид
//при его раскодировании из бинарной строки
VMHL_TempInt2=&RealLength;//указатель на размерность вещественного вектора
VMHL_TempInt3=&TypOfConverting;//указатель на тип преобразования
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VMHL_TempInt4=TempBinaryVector;//массив для хранения бинарного массива для преобразования строки Грей-кода в бинарную

//Выполнение стандартного генетического алгоритма на бинарных строках
try
 {
 //Выполнение стандартного генетического алгоритма на бинарных строках
 VMHL_Success=MHL_BinaryGeneticAlgorithmWDPOfNOfGPS(ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS,MHL_BinaryFitnessFunction,BinaryDecision,VMHL_Result);
 }
catch(...)
 {
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками
 }

if (VMHL_Success==1)
 {
 //VMHL_Result уже записан и определен, а вот VMHL_ResultVector (конечное решение) еще нет
 //так как есть только бинарное решение, а не вещественное, которое нам и нужно

 //Преобразование бинарного решения в вещественное
 if (TypOfConverting==0)//IntConverting (Стандартное представление целого числа – номер узла в сетке дискретизации)
  MHL_BinaryVectorToRealVector(BinaryDecision,VMHL_ResultVector,VMHL_TempDouble1,VMHL_TempDouble2,VMHL_TempInt1,RealLength);
 if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
  MHL_BinaryGrayVectorToRealVector(BinaryDecision,ChromosomeLength,VMHL_ResultVector,VMHL_TempDouble1,VMHL_TempDouble2,VMHL_TempInt1,RealLength);
 }
else
 return 0;//Генетический алгоритм на бинарных строках завершился с ошибками, но не в результате генерирования исключений

//Удалим массивы для запуска стандартного генетического алгоритма на бинарных строках
delete [] ParametersOfBinaryGeneticAlgorithmWDPOfNOfGPS;
delete [] Lengthi;
delete [] BinaryDecision;
delete [] RealVector;
delete [] TempBinaryVector;

//Обнулим дополнительные указатели
VMHL_TempFunction=NULL;
VMHL_TempInt1=NULL;
VMHL_TempDouble1=NULL;
VMHL_TempDouble2=NULL;
VMHL_TempInt2=NULL;
VMHL_TempDouble3=NULL;
VMHL_TempInt3=NULL;
if (TypOfConverting==1)//GrayСodeConverting (Стандартный рефлексивный Грей-код)
 VMHL_TempInt4=NULL;

return 1;//Всё успешно
}
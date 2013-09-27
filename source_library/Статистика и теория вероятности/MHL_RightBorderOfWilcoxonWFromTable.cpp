double MHL_RightBorderOfWilcoxonWFromTable(int m, int n, double Q)
{
    /*
    Функция возвращает правую границу интервала критический значений статистики W для критерия Вилкоксена по табличным данным.
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
     Правая граница интервала критический значений статистики W для критерия Вилкоксена.
    Примечание:
     Если размеры выборок не из таблицы, если не правильный выбран уровень значимости, то возвратится -1.
    */
    double VMHL_Result=-1;

    if (n<m)  TMHL_NumberInterchange(&n,&m);//вначале должна идти выборка с меньшим объемом

    //Получим леdую границу
    double LeftBorder=MHL_LeftBorderOfWilcoxonWFromTable(m, n, Q);

    if (LeftBorder==-1) return -1;

    if (m==1)
    {
        if (n==2)  VMHL_Result = 4;
        if (n==3)  VMHL_Result = 5;
        if (n==4)  VMHL_Result = 6;
        if (n==5)  VMHL_Result = 7;
        if (n==6)  VMHL_Result = 8;
        if (n==7)  VMHL_Result = 9;
        if (n==8)  VMHL_Result = 10;
        if (n==9)  VMHL_Result = 11;
        if (n==10) VMHL_Result = 12;
        if (n==11) VMHL_Result = 13;
        if (n==12) VMHL_Result = 14;
        if (n==13) VMHL_Result = 15;
        if (n==14) VMHL_Result = 16;
        if (n==15) VMHL_Result = 17;
        if (n==16) VMHL_Result = 18;
        if (n==17) VMHL_Result = 19;
        if (n==18) VMHL_Result = 20;
        if (n==19) VMHL_Result = 21;
        if (n==20) VMHL_Result = 22;
        if (n==21) VMHL_Result = 23;
        if (n==22) VMHL_Result = 24;
        if (n==23) VMHL_Result = 25;
        if (n==24) VMHL_Result = 26;
        if (n==25) VMHL_Result = 27;
    }

    if (m==2)
    {
        if (n==2)  VMHL_Result = 10;
        if (n==3)  VMHL_Result = 12;
        if (n==4)  VMHL_Result = 14;
        if (n==5)  VMHL_Result = 16;
        if (n==6)  VMHL_Result = 18;
        if (n==7)  VMHL_Result = 20;
        if (n==8)  VMHL_Result = 22;
        if (n==9)  VMHL_Result = 24;
        if (n==10) VMHL_Result = 26;
        if (n==11) VMHL_Result = 28;
        if (n==12) VMHL_Result = 30;
        if (n==13) VMHL_Result = 32;
        if (n==14) VMHL_Result = 34;
        if (n==15) VMHL_Result = 36;
        if (n==16) VMHL_Result = 38;
        if (n==17) VMHL_Result = 40;
        if (n==18) VMHL_Result = 42;
        if (n==19) VMHL_Result = 44;
        if (n==20) VMHL_Result = 46;
        if (n==21) VMHL_Result = 48;
        if (n==22) VMHL_Result = 50;
        if (n==23) VMHL_Result = 52;
        if (n==24) VMHL_Result = 54;
        if (n==25) VMHL_Result = 56;
    }

    if (m==3)
    {
        if (n==3)  VMHL_Result = 21;
        if (n==4)  VMHL_Result = 24;
        if (n==5)  VMHL_Result = 27;
        if (n==6)  VMHL_Result = 30;
        if (n==7)  VMHL_Result = 33;
        if (n==8)  VMHL_Result = 36;
        if (n==9)  VMHL_Result = 39;
        if (n==10) VMHL_Result = 42;
        if (n==11) VMHL_Result = 45;
        if (n==12) VMHL_Result = 48;
        if (n==13) VMHL_Result = 51;
        if (n==14) VMHL_Result = 54;
        if (n==15) VMHL_Result = 57;
        if (n==16) VMHL_Result = 60;
        if (n==17) VMHL_Result = 63;
        if (n==18) VMHL_Result = 66;
        if (n==19) VMHL_Result = 69;
        if (n==20) VMHL_Result = 72;
        if (n==21) VMHL_Result = 75;
        if (n==22) VMHL_Result = 78;
        if (n==23) VMHL_Result = 81;
        if (n==24) VMHL_Result = 84;
        if (n==25) VMHL_Result = 87;
    }

    if (m==4)
    {
        if (n==4)  VMHL_Result = 36;
        if (n==5)  VMHL_Result = 40;
        if (n==6)  VMHL_Result = 44;
        if (n==7)  VMHL_Result = 48;
        if (n==8)  VMHL_Result = 52;
        if (n==9)  VMHL_Result = 56;
        if (n==10) VMHL_Result = 60;
        if (n==11) VMHL_Result = 64;
        if (n==12) VMHL_Result = 68;
        if (n==13) VMHL_Result = 72;
        if (n==14) VMHL_Result = 76;
        if (n==15) VMHL_Result = 80;
        if (n==16) VMHL_Result = 84;
        if (n==17) VMHL_Result = 88;
        if (n==18) VMHL_Result = 92;
        if (n==19) VMHL_Result = 96;
        if (n==20) VMHL_Result = 100;
        if (n==21) VMHL_Result = 104;
        if (n==22) VMHL_Result = 108;
        if (n==23) VMHL_Result = 112;
        if (n==24) VMHL_Result = 116;
        if (n==25) VMHL_Result = 120;
    }

    if (m==5)
    {
        if (n==5)  VMHL_Result = 55;
        if (n==6)  VMHL_Result = 60;
        if (n==7)  VMHL_Result = 65;
        if (n==8)  VMHL_Result = 70;
        if (n==9)  VMHL_Result = 75;
        if (n==10) VMHL_Result = 80;
        if (n==11) VMHL_Result = 85;
        if (n==12) VMHL_Result = 90;
        if (n==13) VMHL_Result = 95;
        if (n==14) VMHL_Result = 100;
        if (n==15) VMHL_Result = 105;
        if (n==16) VMHL_Result = 110;
        if (n==17) VMHL_Result = 115;
        if (n==18) VMHL_Result = 120;
        if (n==19) VMHL_Result = 125;
        if (n==20) VMHL_Result = 130;
        if (n==21) VMHL_Result = 135;
        if (n==22) VMHL_Result = 140;
        if (n==23) VMHL_Result = 145;
        if (n==24) VMHL_Result = 150;
        if (n==25) VMHL_Result = 155;
    }

    if (m==6)
    {
        if (n==6)  VMHL_Result = 78;
        if (n==7)  VMHL_Result = 84;
        if (n==8)  VMHL_Result = 90;
        if (n==9)  VMHL_Result = 96;
        if (n==10) VMHL_Result = 102;
        if (n==11) VMHL_Result = 108;
        if (n==12) VMHL_Result = 114;
        if (n==13) VMHL_Result = 120;
        if (n==14) VMHL_Result = 126;
        if (n==15) VMHL_Result = 132;
        if (n==16) VMHL_Result = 138;
        if (n==17) VMHL_Result = 144;
        if (n==18) VMHL_Result = 150;
        if (n==19) VMHL_Result = 156;
        if (n==20) VMHL_Result = 162;
        if (n==21) VMHL_Result = 168;
        if (n==22) VMHL_Result = 174;
        if (n==23) VMHL_Result = 180;
        if (n==24) VMHL_Result = 186;
        if (n==25) VMHL_Result = 192;
    }

    if (m==7)
    {
        if (n==7)  VMHL_Result = 105;
        if (n==8)  VMHL_Result = 112;
        if (n==9)  VMHL_Result = 119;
        if (n==10) VMHL_Result = 126;
        if (n==11) VMHL_Result = 133;
        if (n==12) VMHL_Result = 140;
        if (n==13) VMHL_Result = 147;
        if (n==14) VMHL_Result = 154;
        if (n==15) VMHL_Result = 161;
        if (n==16) VMHL_Result = 168;
        if (n==17) VMHL_Result = 175;
        if (n==18) VMHL_Result = 182;
        if (n==19) VMHL_Result = 189;
        if (n==20) VMHL_Result = 196;
        if (n==21) VMHL_Result = 203;
        if (n==22) VMHL_Result = 210;
        if (n==23) VMHL_Result = 217;
        if (n==24) VMHL_Result = 224;
        if (n==25) VMHL_Result = 231;
    }

    if (m==8)
    {
        if (n==8)  VMHL_Result = 136;
        if (n==9)  VMHL_Result = 144;
        if (n==10) VMHL_Result = 152;
        if (n==11) VMHL_Result = 160;
        if (n==12) VMHL_Result = 168;
        if (n==13) VMHL_Result = 176;
        if (n==14) VMHL_Result = 184;
        if (n==15) VMHL_Result = 192;
        if (n==16) VMHL_Result = 200;
        if (n==17) VMHL_Result = 208;
        if (n==18) VMHL_Result = 216;
        if (n==19) VMHL_Result = 224;
        if (n==20) VMHL_Result = 232;
        if (n==21) VMHL_Result = 240;
        if (n==22) VMHL_Result = 248;
        if (n==23) VMHL_Result = 256;
        if (n==24) VMHL_Result = 264;
        if (n==25) VMHL_Result = 272;
    }

    if (m==9)
    {
        if (n==9)  VMHL_Result = 171;
        if (n==10) VMHL_Result = 180;
        if (n==11) VMHL_Result = 189;
        if (n==12) VMHL_Result = 198;
        if (n==13) VMHL_Result = 207;
        if (n==14) VMHL_Result = 216;
        if (n==15) VMHL_Result = 225;
        if (n==16) VMHL_Result = 234;
        if (n==17) VMHL_Result = 243;
        if (n==18) VMHL_Result = 252;
        if (n==19) VMHL_Result = 261;
        if (n==20) VMHL_Result = 270;
        if (n==21) VMHL_Result = 279;
        if (n==22) VMHL_Result = 288;
        if (n==23) VMHL_Result = 297;
        if (n==24) VMHL_Result = 306;
        if (n==25) VMHL_Result = 315;
    }

    if (m==10)
    {
        if (n==10) VMHL_Result = 210;
        if (n==11) VMHL_Result = 220;
        if (n==12) VMHL_Result = 230;
        if (n==13) VMHL_Result = 240;
        if (n==14) VMHL_Result = 250;
        if (n==15) VMHL_Result = 260;
        if (n==16) VMHL_Result = 270;
        if (n==17) VMHL_Result = 280;
        if (n==18) VMHL_Result = 290;
        if (n==19) VMHL_Result = 300;
        if (n==20) VMHL_Result = 310;
        if (n==21) VMHL_Result = 320;
        if (n==22) VMHL_Result = 330;
        if (n==23) VMHL_Result = 340;
        if (n==24) VMHL_Result = 350;
        if (n==25) VMHL_Result = 360;
    }

    if (m==11)
    {
        if (n==11) VMHL_Result = 253;
        if (n==12) VMHL_Result = 264;
        if (n==13) VMHL_Result = 275;
        if (n==14) VMHL_Result = 286;
        if (n==15) VMHL_Result = 297;
        if (n==16) VMHL_Result = 308;
        if (n==17) VMHL_Result = 319;
        if (n==18) VMHL_Result = 330;
        if (n==19) VMHL_Result = 341;
        if (n==20) VMHL_Result = 352;
        if (n==21) VMHL_Result = 363;
        if (n==22) VMHL_Result = 374;
        if (n==23) VMHL_Result = 385;
        if (n==24) VMHL_Result = 396;
        if (n==25) VMHL_Result = 407;
    }

    if (m==12)
    {
        if (n==12) VMHL_Result = 300;
        if (n==13) VMHL_Result = 312;
        if (n==14) VMHL_Result = 324;
        if (n==15) VMHL_Result = 336;
        if (n==16) VMHL_Result = 348;
        if (n==17) VMHL_Result = 360;
        if (n==18) VMHL_Result = 372;
        if (n==19) VMHL_Result = 384;
        if (n==20) VMHL_Result = 396;
        if (n==21) VMHL_Result = 408;
        if (n==22) VMHL_Result = 420;
        if (n==23) VMHL_Result = 432;
        if (n==24) VMHL_Result = 444;
        if (n==25) VMHL_Result = 456;
    }

    if (m==13)
    {
        if (n==13) VMHL_Result = 351;
        if (n==14) VMHL_Result = 364;
        if (n==15) VMHL_Result = 377;
        if (n==16) VMHL_Result = 390;
        if (n==17) VMHL_Result = 403;
        if (n==18) VMHL_Result = 416;
        if (n==19) VMHL_Result = 429;
        if (n==20) VMHL_Result = 442;
        if (n==21) VMHL_Result = 455;
        if (n==22) VMHL_Result = 468;
        if (n==23) VMHL_Result = 481;
        if (n==24) VMHL_Result = 494;
        if (n==25) VMHL_Result = 507;
    }

    if (m==14)
    {
        if (n==14) VMHL_Result = 406;
        if (n==15) VMHL_Result = 420;
        if (n==16) VMHL_Result = 434;
        if (n==17) VMHL_Result = 448;
        if (n==18) VMHL_Result = 462;
        if (n==19) VMHL_Result = 476;
        if (n==20) VMHL_Result = 490;
        if (n==21) VMHL_Result = 504;
        if (n==22) VMHL_Result = 518;
        if (n==23) VMHL_Result = 532;
        if (n==24) VMHL_Result = 546;
        if (n==25) VMHL_Result = 560;
    }

    if (m==15)
    {
        if (n==15) VMHL_Result = 465;
        if (n==16) VMHL_Result = 480;
        if (n==17) VMHL_Result = 495;
        if (n==18) VMHL_Result = 510;
        if (n==19) VMHL_Result = 525;
        if (n==20) VMHL_Result = 540;
        if (n==21) VMHL_Result = 555;
        if (n==22) VMHL_Result = 570;
        if (n==23) VMHL_Result = 585;
        if (n==24) VMHL_Result = 600;
        if (n==25) VMHL_Result = 615;
    }

    if (m==16)
    {
        if (n==16) VMHL_Result = 528;
        if (n==17) VMHL_Result = 544;
        if (n==18) VMHL_Result = 560;
        if (n==19) VMHL_Result = 576;
        if (n==20) VMHL_Result = 592;
        if (n==21) VMHL_Result = 608;
        if (n==22) VMHL_Result = 624;
        if (n==23) VMHL_Result = 640;
        if (n==24) VMHL_Result = 656;
        if (n==25) VMHL_Result = 672;
    }

    if (m==17)
    {
        if (n==17) VMHL_Result = 595;
        if (n==18) VMHL_Result = 612;
        if (n==19) VMHL_Result = 629;
        if (n==20) VMHL_Result = 646;
        if (n==21) VMHL_Result = 663;
        if (n==22) VMHL_Result = 680;
        if (n==23) VMHL_Result = 697;
        if (n==24) VMHL_Result = 714;
        if (n==25) VMHL_Result = 731;
    }

    if (m==18)
    {
        if (n==18) VMHL_Result = 666;
        if (n==19) VMHL_Result = 684;
        if (n==20) VMHL_Result = 702;
        if (n==21) VMHL_Result = 720;
        if (n==22) VMHL_Result = 738;
        if (n==23) VMHL_Result = 756;
        if (n==24) VMHL_Result = 774;
        if (n==25) VMHL_Result = 792;
    }

    if (m==19)
    {
        if (n==19) VMHL_Result = 741;
        if (n==20) VMHL_Result = 760;
        if (n==21) VMHL_Result = 779;
        if (n==22) VMHL_Result = 798;
        if (n==23) VMHL_Result = 817;
        if (n==24) VMHL_Result = 836;
        if (n==25) VMHL_Result = 855;
    }

    if (m==20)
    {
        if (n==20) VMHL_Result = 820;
        if (n==21) VMHL_Result = 840;
        if (n==22) VMHL_Result = 860;
        if (n==23) VMHL_Result = 880;
        if (n==24) VMHL_Result = 900;
        if (n==25) VMHL_Result = 920;
    }

    if (m==21)
    {
        if (n==21) VMHL_Result = 903;
        if (n==22) VMHL_Result = 924;
        if (n==23) VMHL_Result = 945;
        if (n==24) VMHL_Result = 966;
        if (n==25) VMHL_Result = 987;
    }

    if (m==22)
    {
        if (n==22) VMHL_Result = 990;
        if (n==23) VMHL_Result = 1012;
        if (n==24) VMHL_Result = 1034;
        if (n==25) VMHL_Result = 1056;
    }

    if (m==23)
    {
        if (n==23) VMHL_Result = 1081;
        if (n==24) VMHL_Result = 1104;
        if (n==25) VMHL_Result = 1127;
    }

    if (m==24)
    {
        if (n==24) VMHL_Result = 1176;
        if (n==25) VMHL_Result = 1200;
    }

    if (m==25)
    {
        if (n==25) VMHL_Result = 1275;
    }

    return (VMHL_Result-LeftBorder);
}
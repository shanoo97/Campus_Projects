function [Li,Ri]=DESround(text,i,subkey)

EBox = [32 1   2   3   4   5 4   5   6   7   8   9 8   9   10  11  12  13 12  13  14  15  16  17 ... 
        16  17  18  19  20  21 20  21  22  23  24  25 24  25  26  27  28  29 28  29  30  31  32  1];
S1 = [14 4 13 1 2 15 11 8 3 10 6 12 5 9 0 7; 0 15 7 4 14 2 13 1 10 6 12 11 9 5 3 8;...
        4 1 14 8 13 6 2 11 15 12 9 7 3 10 5 0; 15 12 8 2 4 9 1 7 5 11 3 14 10 0 6 13];
S2 = [15 1 8 14 6 11 3 4 9 7 2 13 12 0 5 10; 3 13 4 7 15 2 8 14 12 0 1 10 6 9 11 5;...
        0 14 7 11 10 4 13 1 5 8 12 6 9 3 2 15; 13 8 10 1 3 15 4 2 11 6 7 12 0 5 14 9];
S3 =[10 0 9 14 6 3 15 5 1 13 12 7 11 4 2 8; 13 7 0 9 3 4 6 10 2 8 5 14 12 11 15 1;...
        13 6 4 9 8 15 3 0 11 1 2 12 5 10 14 7; 1 10 13 0 6 9 8 7 4 15 14 3 11 5 2 12];
S4 = [7 13 14 3 0 6 9 10 1 2 8 5 11 12 4 15; 13 8 11 5 6 15 0 3 4 7 2 12 1 10 14 9;...
       10 6 9 0 12 11 7 13 15 1 3 14 5 2 8 4; 3 15 0 6 10 1 13 8 9 4 5 11 12 7 2 14];
S5 = [2 12 4 1 7 10 11 6 8 5 3 15 13 0 14 9; 14 11 2 12 4 7 13 1 5 0 15 10 3 9 8 6;...
        4 2 1 11 10 13 7 8 15 9 12 5 6 3 0 14; 11 8 12 7 1 14 2 13 6 15 0 9 10 4 5 3];
S6 = [12 1 10 15 9 2 6 8 0 13 3 4 14 7 5 11; 10 15 4 2 7 12 9 5 6 1 13 14 0 11 3 8;...
        9 14 15 5 2 8 12 3 7 0 4 10 1 13 11 6; 4 3 2 12 9 5 15 10 11 14 1 7 6 0 8 13];
S7 = [4 11 2 14 15 0 8 13 3 12 9 7 5 10 6 1; 13 0 11 7 4 9 1 10 14 3 5 12 2 15 8 6;...
        1 4 11 13 12 3 7 14 10 15 6 8 0 5 9 2; 6 11 13 8 1 4 10 7 9 5 0 15 14 2 3 12];
S8 = [13 2 8 4 6 15 11 1 10 9 3 14 5 0 12 7; 1 15 13 8 10 3 7 4 12 5 6 11 0 14 9 2;...
        7 11 4 1 9 12 14 2 0 6 10 13 15 3 5 8; 2 1 14 7 4 10 8 13 15 12 9 0 3 5 6 11];
PBox = [16 7 20 21 29 12 28 17 1 15 23 26 5 18 31 10 2 8 24 14 32 27 3 9 19 13 30 6 22 11 4 25];

lefthalf = text(1:32);
righthalf = text(33:64);
Li = righthalf ;

for i=1:48
    Ri(i)=righthalf(EBox(i));
end

for i=1:48
    if (Ri(i)==num2str(subkey(i)))
        Ri(i)='0';
    else Ri(i)='1';
    end 
end

section1 = Ri(1:6);
section2 = Ri(7:12);
section3 = Ri(13:18);
section4 = Ri(19:24);
section5 = Ri(25:30);
section6 = Ri(31:36);
section7 = Ri(37:42);
section8 = Ri(43:48);
combined='';

row= bin2dec(strcat(section1(1),section1(6)))+1;
coloumn= bin2dec(strcat(section1(2),section1(3),section1(4),section1(5)))+1;
combined = strcat(combined,num2str(dec2bin(S1(row,coloumn),4)));

row= bin2dec(strcat(section2(1),section2(6)))+1;
coloumn= bin2dec(strcat(section2(2),section2(3),section2(4),section2(5)))+1;
combined = strcat(combined,num2str(dec2bin(S2(row,coloumn),4)));

row= bin2dec(strcat(section3(1),section3(6)))+1;
coloumn= bin2dec(strcat(section3(2),section3(3),section3(4),section3(5)))+1;
combined = strcat(combined,num2str(dec2bin(S3(row,coloumn),4)));

row= bin2dec(strcat(section4(1),section4(6)))+1;
coloumn= bin2dec(strcat(section4(2),section4(3),section4(4),section4(5)))+1;
combined = strcat(combined,num2str(dec2bin(S4(row,coloumn),4)));

row= bin2dec(strcat(section5(1),section5(6)))+1;
coloumn= bin2dec(strcat(section5(2),section5(3),section5(4),section5(5)))+1;
combined = strcat(combined,num2str(dec2bin(S5(row,coloumn),4)));

row= bin2dec(strcat(section6(1),section6(6)))+1;
coloumn= bin2dec(strcat(section6(2),section6(3),section6(4),section6(5)))+1;
combined = strcat(combined,num2str(dec2bin(S6(row,coloumn),4)));

row= bin2dec(strcat(section7(1),section7(6)))+1;
coloumn= bin2dec(strcat(section7(2),section7(3),section7(4),section7(5)))+1;
combined = strcat(combined,num2str(dec2bin(S7(row,coloumn),4)));

row= bin2dec(strcat(section8(1),section8(6)))+1;
coloumn= bin2dec(strcat(section8(2),section8(3),section8(4),section8(5)))+1;
combined = strcat(combined,num2str(dec2bin(S8(row,coloumn),4)));


for i=1:32
    f(i)=combined(PBox(i));
end

for i=1:32
    if (f(i)==lefthalf(i));
        test(i)='0';
    else test(i)='1';
    end 
    
end
Ri=test;

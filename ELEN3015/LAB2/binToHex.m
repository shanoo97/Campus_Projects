function final = binToHex (binArr)
%Converts an array to binary digits to hex string

FullhexStr=[];
%binArr=[1 0 1 0 0 0 0 0 1 1 1 1]
[r,c]=size(binArr);
for  k=1:c
    if (mod(k,4)==0)
    input=binArr(k-3:k);
    %input=[1 1 1 1]
    decimalVal = 8*input(1) + 4*input(2) + 2*input(3) + input(4);
    switch decimalVal
    case 0, hexstr = '0';
    case 1, hexstr = '1';
    case 2, hexstr = '2';
    case 3, hexstr = '3';
    case 4, hexstr = '4';
    case 5, hexstr = '5';
    case 6, hexstr = '6';
    case 7, hexstr = '7'; 
    case 8, hexstr = '8';
    case 9, hexstr = '9';
    case 10, hexstr = 'A';
    case 11, hexstr = 'B';
    case 12, hexstr = 'C';
    case 13, hexstr = 'D';
    case 14, hexstr = 'E';
    case 15, hexstr = 'F';
    otherwise
        bin_string = -1;
    end
    FullhexStr=strcat(FullhexStr,hexstr);
    end
    
end
    final=FullhexStr;
end

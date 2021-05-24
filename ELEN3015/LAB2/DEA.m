function encrypt= DEA(plaintext,key64)

FP = [40 8 48 16 56 24 64 32 39 7 47 15 55 23 63 31 38 6 46 14 54 22 62 30 ...
37 5 45 13 53 21 61 29 36 4 44 12 52 20 60 28 35 3 43 11 51 19 59 27 ...
34 2 42 10 50 18 58 26 33 1 41 9 49 17 57 25];

IP = ([58   50  42  34  26  18  10  2 60  52  44  36  28  20  12  4 62  54  ...
       46  38  30  22  14  6 64  56  48  40  32  24  16  8 57  49  41  33  ...
       25  17  9   1 59  51  43  35  27  19  11  3 61  53  45  37  29  21  13 ...
       5 63  55  47  39  31  23  15  7]);
   
   for i=1:64
      permutedplaintext(i)=plaintext(IP(i));
   end
   
       KeyPermutation = [ 57 49 41 33 25 17 9 1 58 50 42 34 26 18   ...
                       10 2 59 51 43 35 27 19 11 3 60 52 44 36   ...
                       63 55 47 39 31 23 15 7 62 54 46 38 30 22  ...
                       14 6 61 53 45 37 29 21 13 5 28 20 12 4    ];
                   
    key56=zeros(1,56);
    
    for i=1:1:56
            key56(i)=str2num(key64(KeyPermutation(i)));
    end 
        
        for i=1:15        
       [Li,Ri]=DESround(permutedplaintext,i,generatekey(key56,i));
       permutedplaintext=strcat(Li,Ri);
        end
       [Li,Ri]=DESround(permutedplaintext,16,generatekey(key56,16));
       permutedplaintext=strcat(Ri,Li);
       
       
      for i=1:64
      finalpermutedplaintext(i)=permutedplaintext(FP(i));
      end
   
   encrypt=finalpermutedplaintext;
end
   
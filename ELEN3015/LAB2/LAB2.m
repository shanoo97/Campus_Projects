    
    % Question 1
    
    key64 = '0001001100110100010101110111100110011011101111001101111111110001';



        
    KeyPermutation = [ 57 49 41 33 25 17 9 1 58 50 42 34 26 18   ...
                       10 2 59 51 43 35 27 19 11 3 60 52 44 36   ...
                       63 55 47 39 31 23 15 7 62 54 46 38 30 22  ...
                       14 6 61 53 45 37 29 21 13 5 28 20 12 4    ];
                   
    key56=zeros(1,56);
    
    for i=1:1:56
            key56(i)=str2num(key64(KeyPermutation(i)));
    end 
    
    subkey = generatekey(key56,14)
    
    % Question 2 
    
    Allkeys=string(16);
    key64 = '1F1F1F1F0E0E0E0E';
    key64=lower(key64);
   
    
    key64=hex2bin(key64);
    
        for i=1:1:56
            key56(i)=key64(KeyPermutation(i));
    end 
    
    for ki=1:16
        subkey=generatekey(key56,ki);
        Allkeys(ki)=binToHex(subkey);
    end
    
    Allkeys'
        
        Allkeys=string(16);
    key64 = '1FFE1FFE0EFE0EFE';
    key64=lower(key64);
   
    
    key64=hex2bin(key64);
    
        for i=1:1:56
            key56(i)=key64(KeyPermutation(i));
    end 
    
    for ki=1:16
        subkey=generatekey(key56,ki);
        Allkeys(ki)=binToHex(subkey);
    end
    Allkeys'
        
        Allkeys=string(16);
    key64 = '1FFEFE1F0EFEFE0E';
    key64=lower(key64);
   
    
    key64=hex2bin(key64);
    
        for i=1:1:56
            key56(i)=key64(KeyPermutation(i));
    end 
    
    for ki=1:16
        subkey=generatekey(key56,ki);
        Allkeys(ki)=binToHex(subkey);
    end
    Allkeys'
        
    % Question 3 
    
    [Li,Ri]= DESround('1100110000000000110011001111111111110000101010101111000010101010',1,...
        '000110110000001011101111111111000111000001110010')
    
   % Question 4
   plaintext= '0111001101101000011000010111100101100001011000010110111001110011';
   key64 = '0110001101110010011110010111000001110100011011110110110101100101';
   encrypted=DEA(plaintext,key64)
   
   
   
    
   
    
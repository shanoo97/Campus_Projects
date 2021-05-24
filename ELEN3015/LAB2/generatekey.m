function subkey = generatekey(key56, ki)


    firsthalf=key56(1:28);
    secondhalf=key56(29:56);
    
    shiftperround =[ 1 1 2 2 2 2 2 2 1 2 2 2 2 2 2 1 ];
    
    for i=1:ki
    
    firsthalf=circshift(firsthalf,-shiftperround(i));
    secondhalf=circshift(secondhalf,-shiftperround(i));
    
    end 
    
        KeyCompression =[ 14 17 11 24 1 5 3 28 15 6 21 10 ...
                      23 19 12 4 26 8 16 7 27 20 13 2 ...
                      41 52 31 37 47 55 30 40 51 45 33 48 ...
                      44 49 39 56 34 53 46 42 50 36 29 32 ];
    
                  
        temp = zeros(1,48);
        combined= horzcat(firsthalf,secondhalf);
        
        for i=1:48
            temp(i)=combined(KeyCompression(i));
        end 
        
        
        subkey= temp; 
        
        
        
        
        
        
        
        
        
        
        
                  
                  
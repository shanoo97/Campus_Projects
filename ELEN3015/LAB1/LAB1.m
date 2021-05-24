% Shayaan Salim(1240547) Faheem Moolla(1234085)


% Question 1A

sampletext=readfile('text.txt');
strippedtext=strip(sampletext,1);
frequency=freqget(strippedtext) %using basic functions and getting freqeuncy of sampletext

% Question 1B

Letters=1:26;
plot(Letters,frequency)
title('Frequency of sample text vs Frequency of letters in English Language');
axis([1 26 0 inf]);
hold on;
grid on;
set(gca, 'XTick', Letters, 'XTickLabel',{'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' ...
    'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z'});

F = [  0.0749    0.0129    0.0354    0.0362    0.1400    0.0218    0.0174 ... 
                   0.0422    0.0665    0.0027    0.0047    0.0357    0.0339    0.0674 ... 
                   0.0737    0.0243    0.0026    0.0614    0.0695    0.0985    0.0300 ... 
                   0.0116    0.0169    0.0028    0.0164    0.0004 ];
%Plotting Frequencies on same graph 
plot(Letters,F)
legend('Sample','Language');
xlabel('Letters of the English Alphabet');
ylabel('Frequency Distribution');  

%Question 1D

enciphered=enmono(strippedtext,'CDEFGHIJKLMNOPQRSTUVWXYZAB')
deciphered=demono(enciphered,'YZABCDEFGHIJKLMNOPQRSTUVWX')
[cracked,table]=freqmatch(enciphered);
textlength= 19446;
matches=0;

for x=1:textlength  %Counting mathcing letters to calculate accuracy 
    if (cracked(x)==strippedtext(x))
        matches=matches + 1;
    end 
end 

accuracy= matches/textlength *100

%Question 1F

[cracked,table2]=freqmatch(enciphered,frequency);
textlength= 19446;
matches=0;

for x=1:textlength
    if (cracked(x)==strippedtext(x)) %Used to calculate accuracy 
        matches=matches + 1;
    end 
end 

accuracy= matches/textlength *100

%Question 2

testtext=strip(sampletext); 
x=IOC(testtext);   %IC values 

y=enpoly(strippedtext,'a');
x1=IOC(y);

y=enpoly(strippedtext,'ab');
x2=IOC(y);

y=enpoly(strippedtext,'abc');
x3=IOC(y);

y=enpoly(strippedtext,'abcd');
x4=IOC(y);

y=enpoly(strippedtext,'abcde');
x5=IOC(y);

y= [1 2 3 4 5 : x1 x2 x3 x4 x5] %All IC values 

%QUESTION 3A

text=readfile('3A.txt');
enciphered=encolumn(text)
deciphered=decolumn(enciphered)
freqenciphered=freqget(enciphered);
freqdeciphered=freqget(text);

plot(Letters,freqenciphered);
hold on;
plot(Letters,freqdeciphered); %Plotting Frequencies on one graph 
title('Columnar Transposition Letter Frequency');
xlabel('Letters of the English alphabet');
ylabel('Normalised Frequency' );
axis([1 26 0 inf]);
legend('Encipher Frequency','Plaintext Frequency');
set(gca, 'XTick',Letters, 'XTickLabel',{'A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' ...
    'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z'});

%Question 3B


text=readfile('3B.txt');
encipher1=encolumn(text,7) 
encipher2=encolumn(encipher1,13)%Enciphering twice 


%Question 3C

text=readfile('3C.txt');
encipher=encolumn(text,4);
counter=1; %starts at 1 because enciphered once already 

while (~strcmp(text,encipher))
    counter=counter+1;
    encipher=encolumn(encipher,4); %counting enciphering times
    
end

counter 

text=readfile('3C.txt');
encipher=encolumn(text,5);
counter=1;  %starts at 1 because enciphered once already 

while (~strcmp(text,encipher))
    counter=counter+1;
    encipher=encolumn(encipher,5);%counting enciphering times
    
end

counter 











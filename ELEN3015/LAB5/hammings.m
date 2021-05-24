function x = hammings(input_text)
%generator matrix
G = [1 1 0 1 0 0 0;
    0 1 1 0 1 0 0;
    1 1 1 0 0 1 0;
    1 0 1 0 0 0 1;];

%Parity check matrix
H = [1 0 0 1 0 1 1;
    0 1 0 1 1 1 0;
    0 0 1 0 1 1 1;];

C1 = input_text*G;

x = mod(C1,2);

end
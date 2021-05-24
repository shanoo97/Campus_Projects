function x = add(input_text)
%x^(n-k)
x3 = [0 0 0 1];
C = gfconv(input_text,x3);
store = C;
G = [1 1 0 1];
[quotient,rem] = gfdeconv(store,G);
[m,len] = size(rem);
dif = 7 - len; %since total is 7 bits
%padding with zeros
if dif~=0 
for index = len+1:7
rem(index) = 0;
end
end

[r,dif] = size(C);
dif1 = 7 - dif;

if dif1~=0
for p2 = dif+1:7
C(p2) = 0;
end
end

x = C+rem;
end
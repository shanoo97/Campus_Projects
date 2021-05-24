function x = error_def(input_text)

H = [1 0 0 1 0 1 1;
    0 1 0 1 1 1 0;
    0 0 1 0 1 1 1;];

LT =          [1 0 0;
               0 1 0;
               0 0 1;
               1 1 0;
               0 1 1;
               1 1 1;
               1 0 1];
     G = H';     
i_h = mod(input_text*G,2);
c = 0;

for i = 1:7
Ck = xor(LT(i,:),i_h);
sums = sum(Ck);
c = c+1;
if sums == 0
break
end
end
l = input_text(7);
if c ~=0
if input_text(c) == 0
input_text(c)=1;
else
input_text(c)=0;
end
end
input_text(7) = l;
x = input_text;
end
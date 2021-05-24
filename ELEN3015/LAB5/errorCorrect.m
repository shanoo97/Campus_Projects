function x = errorCorrect(in)

Gx = [1 1 0 1];
LT =          [1 0 0 0 0 0 0;
               0 1 0 0 0 0 0;
               0 0 1 0 0 0 0;
               1 1 0 0 0 0 0;
               0 1 1 0 0 0 0;
               1 1 1 0 0 0 0;
               1 0 1 0 0 0 0];

quotient = 0;
rem = 0;
[quotient,rem]=gfdeconv(in,Gx);
count1 = 0;
count2 = 0;
[count1,count2] = size(rem);
num = 0;
num = 7-count2;
store = 0;
store = rem;
%completion of padding
if num~=0
for index = count2+1:7
rem(index) = 0;
end
end
array = 0;
suming = 0;
counter=0;
for i = 1:7
array = xor(LT(i,:),rem);
suming = sum(array);
counter = counter+1;
if suming == 0
break
end
end
l = in(7);
if counter ~=0
if in(counter) == 0
in(counter)=1;
else
in(counter)=0;
end
end
in(7) = l;
x = in;
end
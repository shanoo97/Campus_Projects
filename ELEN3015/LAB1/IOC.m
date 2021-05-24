function x = IOC(y)
alphabets = count(y);
len = length(y);
sum =0;
temp=0;
for z=1:26
   temp=  alphabets(z)*(alphabets(z)-1)/(len*(len-1));
   sum=sum + temp;
end
x= sum ;


end


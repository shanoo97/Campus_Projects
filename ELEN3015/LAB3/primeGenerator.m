function prime = primeGenerator()


%Uses Rabin-Miller test to see if generated numbers are prime
%We will limit the prime digit length to 3 digits

check = 0;

while (check == 0)
    %pr_ini = randi([1000, 9999]); %4 digits takes too long
    %pr_ini = randi([3 99]); %2 digits test case
    pr_ini = randi([100 999]);
    
%Make random number odd if even
if (mod(pr_ini,2)==0)
    pr_ini=pr_ini-1;
else
    pr_ini=pr_ini;
end

%Computing b
c = 0;
while (power(2,c) <= pr_ini-1)
    if (mod(pr_ini-1,power(2,c)) == 0)
    b = c;
    end
    c = c+1;
end

%Computing m 
m = (pr_ini-1)/power(2,b);
    if (mod(m,1) == 0)
    a = randi([1 pr_ini-1]);
    j=0;
    z = bigMod(a,m,pr_ini);
    if (z==1)|(z == pr_ini-1)
    if isprime(pr_ini) == 1
        prime = pr_ini;
        check = 1;
    end
    end
    end
end

end

